////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           OpenSpaceToolkit/IO/IP/TCP/HTTP/Client.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Client.hpp>

#include <OpenSpaceToolkit/Core/FileSystem/Path.hpp>
#include <OpenSpaceToolkit/Core/Error.hpp>
#include <OpenSpaceToolkit/Core/Utilities.hpp>

#include <curl/curl.h>

// #include <openssl/opensslv.h>
// #include <openssl/ssl.h>

// #define BOOST_NETWORK_ENABLE_HTTPS
// #include <boost/network.hpp>

// #include <boost/beast/core.hpp>
// #include <boost/beast/http.hpp>
// #include <boost/asio/connect.hpp>
// #include <boost/asio/ip/tcp.hpp>
// #include <boost/asio/ssl/error.hpp>
// #include <boost/asio/ssl/stream.hpp>

#include <boost/algorithm/string.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// [TBI] curl_easy_setopt(curlPtr, CURLOPT_USERPWD, "username:password") ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ostk
{
namespace io
{
namespace ip
{
namespace tcp
{
namespace http
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int                             debugHandler                                (           CURL*                       aCurlPtr,
                                                                                        curl_infotype               aType,
                                                                                        char*                       aDataset,
                                                                                        size_t                      aSize,
                                                                                        void*                       aContext                                    )
{

    (void) aCurlPtr ;
    (void) aSize ;
    (void) aContext ;

    switch (aType)
    {

        case CURLINFO_TEXT:
            std::cout << aDataset << std::endl ;
            break ;

        case CURLINFO_HEADER_OUT:
            std::cout << "=> Send header" << std::endl ;
            break ;

        case CURLINFO_DATA_OUT:
            std::cout << "=> Send data" << std::endl ;
            break ;

        case CURLINFO_SSL_DATA_OUT:
            std::cout << "=> Send SSL data" << std::endl ;
            break ;

        case CURLINFO_HEADER_IN:
            std::cout << "<= Recv header" << std::endl ;
            break ;

        case CURLINFO_DATA_IN:
            std::cout << "<= Recv data" << std::endl ;
            break ;

        case CURLINFO_SSL_DATA_IN:
            std::cout << "<= Recv SSL data" << std::endl ;
            break ;

        default:
            return 0 ;

    }

    return 0 ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Response                        Client::Send                                (   const   Request&                    aRequest                                    )
{

    if (!aRequest.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Request") ;
    }

    // std::cout << "curl_global_init(CURL_GLOBAL_SSL)..." << std::endl ;

    // curl_global_init(CURL_GLOBAL_SSL) ;

    // SSL_library_init() ;

    // Setup

    CURL* curlPtr = curl_easy_init() ;

    try
    {

        if (curlPtr == nullptr)
        {
            throw ostk::core::error::RuntimeError("Error with cURL setup.") ;
        }

        // Set URL

        const String urlString = aRequest.getUrl().toString(true) ;

        curl_easy_setopt(curlPtr, CURLOPT_URL, urlString.data()) ;

        // Set request method

        curl_easy_setopt(curlPtr, CURLOPT_CUSTOMREQUEST, boost::to_upper_copy<String>(Request::StringFromMethod(aRequest.getMethod())).data()) ;

        // Set request body

        curl_easy_setopt(curlPtr, CURLOPT_POSTFIELDS, aRequest.getBody().data()) ;

        // Set response data handler

        std::ostringstream responseStream ;

        curl_easy_setopt(curlPtr, CURLOPT_WRITEDATA, &responseStream) ;

        const auto writeDataFunction = +[] (char* aBuffer, size_t aSize, size_t aDataSize, void* aContextPtr) -> size_t
        {

            std::ostringstream* streamPtr = static_cast<std::ostringstream*>(aContextPtr) ;

            const size_t count = aSize * aDataSize ;

            streamPtr->write(aBuffer, count) ;

            return count ;

        } ;

        curl_easy_setopt(curlPtr, CURLOPT_WRITEFUNCTION, writeDataFunction) ;

        //

        // curl_easy_setopt(curlPtr, CURLOPT_SSL_CIPHER_LIST, "ecdhe_ecdsa_aes_128_sha") ;

        // curl_easy_setopt(curlPtr, CURLOPT_DEBUGFUNCTION, debugHandler) ;
        // curl_easy_setopt(curlPtr, CURLOPT_VERBOSE, 1L) ;

        // Send request

        const CURLcode curlCode = curl_easy_perform(curlPtr) ;

        // Check response

        if (curlCode != CURLE_OK)
        {
            throw ostk::core::error::RuntimeError("Error using cURL: [{}].", curl_easy_strerror(curlCode)) ;
        }

        long responseCode ;

        curl_easy_getinfo(curlPtr, CURLINFO_RESPONSE_CODE, &responseCode) ;

        // Cleanup

        curl_easy_cleanup(curlPtr) ;

        return { Response::StatusCode(responseCode), responseStream.str() } ;
    }
    catch (...)
    {
        curl_easy_cleanup(curlPtr) ;
        throw ;
    }

    // [TBR] Below are (failed) attempts to use CppNetLib and Boost.Beast...

    // try
    // {

    //     Response::StatusCode responseStatusCode = Response::StatusCode::Undefined ;
    //     String responseBody = String::Empty() ;

    //     // cpp-netlib (bug with HTTPS)

    //     boost::network::http::client::request request(aUrl.toString()) ;

    //     request << boost::network::header("Connection", "close") ;

    //     const boost::network::http::client::response response = boost::network::http::client().get(request) ;

    //     responseStatusCode = Response::StatusCode(boost::network::http::status(response)) ;

    //     responseBody = boost::network::http::body(response) ;

    //     Boost.Beast (no straightforward response parsing)

    //     using tcp = boost::asio::ip::tcp ;

    //     namespace http = boost::beast::http ;
    //     namespace ssl = boost::asio::ssl ;

    //     std::string target = aUrl.getPath() ;

    //     if (aUrl.getQuery().isDefined())
    //     {
    //         target += "?" + aUrl.getQuery().toString() ;
    //     }

    //     if (aUrl.getFragment().isDefined())
    //     {
    //         target += "#" + aUrl.getFragment() ;
    //     }

    //     if (aUrl.getScheme() == "http")
    //     {

    //         const std::string host = aUrl.getHost() ;
    //         const std::string port = aUrl.getPort().isDefined() ? aUrl.getPort().toString() : "80" ;
    //         const int version = 10 ; // [TBM] Param

    //         // The io_context is required for all I/O

    //         boost::asio::io_context ioc ;

    //         // These objects perform our I/O

    //         tcp::resolver resolver { ioc } ;
    //         tcp::socket socket { ioc } ;

    //         // Look up the domain name

    //         const auto results = resolver.resolve(host, port) ;

    //         // Make the connection on the IP address we get from a lookup

    //         boost::asio::connect(socket, results.begin(), results.end()) ;

    //         // Set up an HTTP GET request message

    //         http::request<http::string_body> req { http::verb::get, target, version } ;

    //         req.set(http::field::host, host) ;
    //         // req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING) ;

    //         // Send the HTTP request to the remote host

    //         http::write(socket, req) ;

    //         // This buffer is used for reading and must be persisted

    //         boost::beast::flat_buffer buffer ;

    //         // Declare a container to hold the response

    //         http::response<http::dynamic_body> res ;

    //         // Receive the HTTP response

    //         http::read(socket, buffer, res) ;

    //         // Write the message to standard out

    //         std::cout << res << std::endl ;

    //         [TBI] Response parsing

    //         // Gracefully close the socket

    //         boost::system::error_code ec ;
    //         socket.shutdown(tcp::socket::shutdown_both, ec) ;

    //         // not_connected happens sometimes so don't bother reporting it.

    //         if (ec && (ec != boost::system::errc::not_connected))
    //         {
    //             throw boost::system::system_error {ec} ;
    //         }

    //     }
    //     else if (aUrl.getScheme() == "https")
    //     {

    //         const std::string host = aUrl.getHost() ;
    //         const std::string port = aUrl.getPort().isDefined() ? aUrl.getPort().toString() : "443" ;
    //         const int version = 10 ; // [TBM] Param

    //         // The io_context is required for all I/O

    //         boost::asio::io_context ioc ;

    //         // The SSL context is required, and holds certificates

    //         ssl::context ctx { ssl::context::sslv23_client } ;

    //         // This holds the root certificate used for verification

    //         // load_root_certificates(ctx) ;

    //         // Verify the remote server's certificate

    //         ctx.set_verify_mode(ssl::verify_peer) ;

    //         // These objects perform our I/O

    //         tcp::resolver resolver { ioc } ;
    //         ssl::stream<tcp::socket> stream { ioc, ctx } ;

    //         // Set SNI Hostname (many hosts need this to handshake successfully)

    //         if (!SSL_set_tlsext_host_name(stream.native_handle(), host.data()))
    //         {
    //             boost::system::error_code ec { static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category() } ;
    //             throw boost::system::system_error { ec } ;
    //         }

    //         // Look up the domain name

    //         const auto results = resolver.resolve(host, port) ;

    //         // Make the connection on the IP address we get from a lookup

    //         boost::asio::connect(socket, results.begin(), results.end()) ;

    //         // Set up an HTTP GET request message

    //         http::request<http::string_body> req { http::verb::get, target, version } ;

    //         req.set(http::field::host, host) ;
    //         // req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING) ;

    //         // Send the HTTP request to the remote host

    //         http::write(socket, req) ;

    //         // This buffer is used for reading and must be persisted

    //         boost::beast::flat_buffer buffer ;

    //         // Declare a container to hold the response

    //         http::response<http::dynamic_body> res ;

    //         // Receive the HTTP response

    //         http::read(socket, buffer, res) ;

    //         // Write the message to standard out

    //         std::cout << res << std::endl ;

    //         [TBI] Response parsing

    //         // Make the connection on the IP address we get from a lookup

    //         boost::asio::connect(stream.next_layer(), results.begin(), results.end()) ;

    //         // Perform the SSL handshake

    //         stream.handshake(ssl::stream_base::client) ;

    //         // Gracefully close the stream

    //         boost::system::error_code ec ;
    //         stream.shutdown(ec) ;

    //         if (ec == boost::asio::error::eof)
    //         {

    //             // Rationale: http://stackoverflow.com/questions/25587403/boost-asio-ssl-async-shutdown-always-finishes-with-an-error

    //             ec.assign(0, ec.category()) ;

    //         }
    //         if (ec)
    //         {
    //             throw boost::system::system_error {ec} ;
    //         }

    //     }
    //     else
    //     {
    //         throw ostk::core::error::runtime::Wrong("URL scheme", aUrl.getScheme()) ;
    //     }

    // }
    // catch (const std::exception& e)
    // {
    //     throw ostk::core::error::RuntimeError(e.what()) ;
    // }

    // return { responseStatusCode, responseBody } ;

}

Response                        Client::Get                                 (   const   URL&                        aUrl                                        )
{
    return Client::Send(Request::Get(aUrl)) ;
}

File                            Client::Fetch                               (   const   URL&                        aUrl,
                                                                                const   Directory&                  aDirectory                                  )
{

    using ostk::core::fs::Path ;

    if (!aUrl.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("URL") ;
    }

    if (!aDirectory.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Directory") ;
    }

    File file = File::Undefined() ;

    // Setup

    CURL* curlPtr = curl_easy_init() ;

    try
    {

        if (curlPtr == nullptr)
        {
            throw ostk::core::error::RuntimeError("Error with cURL setup.") ;
        }

        if (!aDirectory.exists())
        {
            Directory(aDirectory).create() ;
        }

        // Set URL

        const String urlString = aUrl.toString(true) ;

        curl_easy_setopt(curlPtr, CURLOPT_URL, urlString.data()) ;

        // Set response data handler

        file = File::Path(Path::Parse(String::Format("{}/{}", aDirectory.getPath().toString(), Path::Parse(aUrl.getPath()).getLastElement()))) ;

        FILE* filePtr = fopen(file.getPath().toString().data(), "wb") ;

        if (!filePtr)
        {
            throw ostk::core::error::RuntimeError("Cannot create file [" + file.toString() + "].") ;
        }

        curl_easy_setopt(curlPtr, CURLOPT_WRITEDATA, filePtr) ;

        const auto writeDataFunction = +[] (void* aBuffer, size_t aSize, size_t aDataSize, FILE* aFilePtr) -> size_t
        {
            return fwrite(aBuffer, aSize, aDataSize, aFilePtr) ;
        } ;

        curl_easy_setopt(curlPtr, CURLOPT_WRITEFUNCTION, writeDataFunction) ;

        curl_easy_setopt(curlPtr, CURLOPT_FAILONERROR, true) ;
        // curl_easy_setopt(curlPtr, CURLOPT_FOLLOWLOCATION, 1L) ;

        // Send request

        const CURLcode curlCode = curl_easy_perform(curlPtr) ;

        // Check response

        long responseCode ;

        curl_easy_getinfo(curlPtr, CURLINFO_RESPONSE_CODE, &responseCode) ;

        // Cleanup

        if (filePtr != nullptr)
        {

            if (fclose(filePtr) == EOF)
            {
                throw ostk::core::error::RuntimeError("Error when closing the file.") ;
            }

        }

        if (curlCode != CURLE_OK)
        {

            if (file.exists())
            {
                file.remove() ;
            }

            throw ostk::core::error::RuntimeError("Error using cURL to fetch file at URL [{}]: [{}].", aUrl.toString(), curl_easy_strerror(curlCode)) ;

        }

        curl_easy_cleanup(curlPtr) ;

        return file ;

    }
    catch (...)
    {
        curl_easy_cleanup(curlPtr) ;
        throw ;
    }

}

void                            Client::List                                (   const   URL&                        aUrl,
                                                                                const   File&                       aFile,
                                                                                const   bool                        showNamesOnly                               )
{

    using ostk::core::fs::Path ;

    if (!aUrl.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("URL") ;
    }

    if (!aFile.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("File") ;
    }

    if (aFile.exists())
    {
        throw ostk::core::error::RuntimeError("File [{}] already exists.", aFile.toString()) ;
    }

    // Setup

    CURL* curlPtr = curl_easy_init() ;

    try
    {

        if (curlPtr == nullptr)
        {
            throw ostk::core::error::RuntimeError("Error with cURL setup.") ;
        }

        // Set URL

        const String urlString = aUrl.toString(true) ;

        curl_easy_setopt(curlPtr, CURLOPT_URL, urlString.data()) ;

        // Set file handler

        FILE* filePtr = fopen(aFile.getPath().toString().data(), "w") ;

        if (!filePtr)
        {
            throw ostk::core::error::RuntimeError("Cannot create file [" + aFile.toString() + "].") ;
        }

        curl_easy_setopt(curlPtr, CURLOPT_FILE, filePtr) ;

        // Set options

        curl_easy_setopt(curlPtr, CURLOPT_TRANSFERTEXT, 1) ;

        if (showNamesOnly)
        {
            curl_easy_setopt(curlPtr, CURLOPT_DIRLISTONLY, 1) ;
        }

        // Send request

        const CURLcode curlCode = curl_easy_perform(curlPtr) ;

        // Check response

        long responseCode ;

        curl_easy_getinfo(curlPtr, CURLINFO_RESPONSE_CODE, &responseCode) ;

        // Cleanup

        if (filePtr != nullptr)
        {

            if (fclose(filePtr) == EOF)
            {
                throw ostk::core::error::RuntimeError("Error when closing the file.") ;
            }

        }

        if (curlCode != CURLE_OK)
        {

            if (aFile.exists())
            {
                File(aFile).remove() ;
            }

            throw ostk::core::error::RuntimeError("Error using cURL to list files at URL [{}]: [{}].", aUrl.toString(), curl_easy_strerror(curlCode)) ;

        }

        curl_easy_cleanup(curlPtr) ;

    }
    catch (...)
    {
        curl_easy_cleanup(curlPtr) ;
        throw ;
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
