/// Apache License 2.0

#include <boost/algorithm/string.hpp>
#include <curl/curl.h>

#include <OpenSpaceToolkit/Core/Error.hpp>
#include <OpenSpaceToolkit/Core/FileSystem/Path.hpp>
#include <OpenSpaceToolkit/Core/Utilities.hpp>

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Client.hpp>

// [TBI] curl_easy_setopt(curlPtr, CURLOPT_USERPWD, "username:password") ;

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

int debugHandler(CURL* aCurlPtr, curl_infotype aType, char* aDataset, size_t aSize, void* aContext)
{
    (void)aCurlPtr;
    (void)aSize;
    (void)aContext;

    switch (aType)
    {
        case CURLINFO_TEXT:
            std::cout << aDataset << std::endl;
            break;

        case CURLINFO_HEADER_OUT:
            std::cout << "=> Send header" << std::endl;
            break;

        case CURLINFO_DATA_OUT:
            std::cout << "=> Send data" << std::endl;
            break;

        case CURLINFO_SSL_DATA_OUT:
            std::cout << "=> Send SSL data" << std::endl;
            break;

        case CURLINFO_HEADER_IN:
            std::cout << "<= Recv header" << std::endl;
            break;

        case CURLINFO_DATA_IN:
            std::cout << "<= Recv data" << std::endl;
            break;

        case CURLINFO_SSL_DATA_IN:
            std::cout << "<= Recv SSL data" << std::endl;
            break;

        default:
            return 0;
    }

    return 0;
}

Response Client::Send(const Request& aRequest)
{
    if (!aRequest.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Request");
    }

    // std::cout << "curl_global_init(CURL_GLOBAL_SSL)..." << std::endl ;

    // curl_global_init(CURL_GLOBAL_SSL) ;

    // SSL_library_init() ;

    // Setup

    CURL* curlPtr = curl_easy_init();

    try
    {
        if (curlPtr == nullptr)
        {
            throw ostk::core::error::RuntimeError("Error with cURL setup.");
        }

        // Set URL

        const String urlString = aRequest.getUrl().toString(true);

        curl_easy_setopt(curlPtr, CURLOPT_URL, urlString.data());

        // Set request method

        curl_easy_setopt(
            curlPtr,
            CURLOPT_CUSTOMREQUEST,
            boost::to_upper_copy<String>(Request::StringFromMethod(aRequest.getMethod())).data()
        );

        // Set request body

        curl_easy_setopt(curlPtr, CURLOPT_POSTFIELDS, aRequest.getBody().data());

        // Set response data handler

        std::ostringstream responseStream;

        curl_easy_setopt(curlPtr, CURLOPT_WRITEDATA, &responseStream);

        const auto writeDataFunction = +[](char* aBuffer, size_t aSize, size_t aDataSize, void* aContextPtr) -> size_t
        {
            std::ostringstream* streamPtr = static_cast<std::ostringstream*>(aContextPtr);

            const size_t count = aSize * aDataSize;

            streamPtr->write(aBuffer, count);

            return count;
        };

        curl_easy_setopt(curlPtr, CURLOPT_WRITEFUNCTION, writeDataFunction);

        //

        // curl_easy_setopt(curlPtr, CURLOPT_SSL_CIPHER_LIST, "ecdhe_ecdsa_aes_128_sha") ;

        // curl_easy_setopt(curlPtr, CURLOPT_DEBUGFUNCTION, debugHandler) ;
        // curl_easy_setopt(curlPtr, CURLOPT_VERBOSE, 1L) ;

        // Send request

        const CURLcode curlCode = curl_easy_perform(curlPtr);

        // Check response

        if (curlCode != CURLE_OK)
        {
            throw ostk::core::error::RuntimeError("Error using cURL: [{}].", curl_easy_strerror(curlCode));
        }

        long responseCode;

        curl_easy_getinfo(curlPtr, CURLINFO_RESPONSE_CODE, &responseCode);

        // Cleanup

        curl_easy_cleanup(curlPtr);

        return {Response::StatusCode(responseCode), responseStream.str()};
    }
    catch (...)
    {
        curl_easy_cleanup(curlPtr);
        throw;
    }
}

Response Client::Get(const URL& aUrl)
{
    return Client::Send(Request::Get(aUrl));
}

File Client::Fetch(const URL& aUrl, const Directory& aDirectory, const Size& aFollowCount)
{
    using ostk::core::filesystem::Path;

    if (!aUrl.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("URL");
    }

    if (!aDirectory.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Directory");
    }

    File file = File::Undefined();

    // Setup

    CURL* curlPtr = curl_easy_init();

    try
    {
        if (curlPtr == nullptr)
        {
            throw ostk::core::error::RuntimeError("Error with cURL setup.");
        }

        if (!aDirectory.exists())
        {
            Directory(aDirectory).create();
        }

        // Set URL

        const String urlString = aUrl.toString(true);

        curl_easy_setopt(curlPtr, CURLOPT_URL, urlString.data());

        // Set response data handler

        file = File::Path(Path::Parse(
            String::Format("{}/{}", aDirectory.getPath().toString(), Path::Parse(aUrl.getPath()).getLastElement())
        ));

        FILE* filePtr = fopen(file.getPath().toString().data(), "wb");

        if (!filePtr)
        {
            throw ostk::core::error::RuntimeError("Cannot create file [" + file.toString() + "].");
        }

        curl_easy_setopt(curlPtr, CURLOPT_WRITEDATA, filePtr);

        const auto writeDataFunction = +[](void* aBuffer, size_t aSize, size_t aDataSize, FILE* aFilePtr) -> size_t
        {
            return fwrite(aBuffer, aSize, aDataSize, aFilePtr);
        };

        curl_easy_setopt(curlPtr, CURLOPT_WRITEFUNCTION, writeDataFunction);

        curl_easy_setopt(curlPtr, CURLOPT_FAILONERROR, true);
        curl_easy_setopt(curlPtr, CURLOPT_FOLLOWLOCATION, aFollowCount);

        // Send request

        const CURLcode curlCode = curl_easy_perform(curlPtr);

        // Check response

        long responseCode;

        curl_easy_getinfo(curlPtr, CURLINFO_RESPONSE_CODE, &responseCode);

        // Cleanup

        if (filePtr != nullptr)
        {
            if (fclose(filePtr) == EOF)
            {
                throw ostk::core::error::RuntimeError("Error when closing the file.");
            }
        }

        if (curlCode != CURLE_OK)
        {
            if (file.exists())
            {
                file.remove();
            }

            throw ostk::core::error::RuntimeError(
                "Error using cURL to fetch file at URL [{}]: [{}].", aUrl.toString(), curl_easy_strerror(curlCode)
            );
        }

        curl_easy_cleanup(curlPtr);

        return file;
    }
    catch (...)
    {
        curl_easy_cleanup(curlPtr);
        throw;
    }
}

void Client::List(const URL& aUrl, const File& aFile, const bool showNamesOnly)
{
    using ostk::core::filesystem::Path;

    if (!aUrl.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("URL");
    }

    if (!aFile.isDefined())
    {
        throw ostk::core::error::runtime::Undefined("File");
    }

    if (aFile.exists())
    {
        throw ostk::core::error::RuntimeError("File [{}] already exists.", aFile.toString());
    }

    // Setup

    CURL* curlPtr = curl_easy_init();

    try
    {
        if (curlPtr == nullptr)
        {
            throw ostk::core::error::RuntimeError("Error with cURL setup.");
        }

        // Set URL

        const String urlString = aUrl.toString(true);

        curl_easy_setopt(curlPtr, CURLOPT_URL, urlString.data());

        // Set file handler

        FILE* filePtr = fopen(aFile.getPath().toString().data(), "w");

        if (!filePtr)
        {
            throw ostk::core::error::RuntimeError("Cannot create file [" + aFile.toString() + "].");
        }

        curl_easy_setopt(curlPtr, CURLOPT_FILE, filePtr);

        // Set options

        curl_easy_setopt(curlPtr, CURLOPT_TRANSFERTEXT, 1);

        if (showNamesOnly)
        {
            curl_easy_setopt(curlPtr, CURLOPT_DIRLISTONLY, 1);
        }

        // Send request

        const CURLcode curlCode = curl_easy_perform(curlPtr);

        // Check response

        long responseCode;

        curl_easy_getinfo(curlPtr, CURLINFO_RESPONSE_CODE, &responseCode);

        // Cleanup

        if (filePtr != nullptr)
        {
            if (fclose(filePtr) == EOF)
            {
                throw ostk::core::error::RuntimeError("Error when closing the file.");
            }
        }

        if (curlCode != CURLE_OK)
        {
            if (aFile.exists())
            {
                File(aFile).remove();
            }

            throw ostk::core::error::RuntimeError(
                "Error using cURL to list files at URL [{}]: [{}].", aUrl.toString(), curl_easy_strerror(curlCode)
            );
        }

        curl_easy_cleanup(curlPtr);
    }
    catch (...)
    {
        curl_easy_cleanup(curlPtr);
        throw;
    }
}

}  // namespace http
}  // namespace tcp
}  // namespace ip
}  // namespace io
}  // namespace ostk
