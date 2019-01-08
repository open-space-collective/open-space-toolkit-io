////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/IP/TCP/HTTP/Request.hpp
/// @author         Lucas Brémond <lucas.bremond@gmail.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_IO_IP_TCP_HTTP_Request__
#define __Library_IO_IP_TCP_HTTP_Request__

#include <Library/IO/URL.hpp>

#include <Library/Core/Types/String.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
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

using library::core::types::String ;

using library::io::URL ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Hypertext Transfer Protocol (HTTP) request
///
/// @ref                        https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol#Request_methods

class Request
{

    public:

        /// @brief              Request method

        enum class Method
        {

            Undefined,          ///< Undefined request method.
            Get,                ///< Requests a representation of the specified resource.
            Head,               ///< Asks for a response identical to that of a GET request, but without the response body.
            Post,               ///< Requests that the server accept the entity enclosed in the request as a new subordinate of the web resource identified by the URI.
            Put,                ///< Requests that the enclosed entity be stored under the supplied URI.
            Delete,             ///< Deletes the specified resource.
            Trace,              ///< Echoes the received request so that a client can see what (if any) changes or additions have been made by intermediate servers.
            Options,            ///< Returns the HTTP methods that the server supports for the specified URL.
            Connect,            ///< Converts the request connection to a transparent TCP/IP tunnel.
            Patch               ///< Applies partial modifications to a resource.

        } ;

        /// @brief              Constructor
        ///
        /// @param              [in] aMethod A method
        /// @param              [in] aUrl A URL
        /// @param              [in] aBody A body

                                Request                                     (   const   Request::Method&            aMethod,
                                                                                const   URL&                        aUrl,
                                                                                const   String&                     aBody                                       ) ;

        /// @brief              Output stream operator
        ///
        /// @param              [in] anOutputStream An output stream
        /// @param              [in] aRequest A request
        /// @return             An output stream

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Request&                    aRequest                                    ) ;

        /// @brief              Check if request is defined
        ///
        /// @return             True if request is defined

        bool                    isDefined                                   ( ) const ;

        /// @brief              Get request method
        ///
        /// @return             Request method
        
        Request::Method         getMethod                                   ( ) const ;
        
        /// @brief              Get request URL
        ///
        /// @return             Request URL
        
        URL                     getUrl                                      ( ) const ;

        /// @brief              Get request body
        ///
        /// @return             Request body
        
        String                  getBody                                     ( ) const ;

        /// @brief              Constructs an undefined request
        ///
        /// @return             Undefined request
        
        static Request          Undefined                                   ( ) ;

        /// @brief              Constructs a GET request
        ///
        /// @param              [in] aUrl A URL
        /// @return             GET request
        
        static Request          Get                                         (   const   URL&                        aUrl                                        ) ;

        /// @brief              Converts request method to string
        ///
        /// @param              [in] aMethod A request method
        /// @return             Request method string
        
        static String           StringFromMethod                            (   const   Request::Method&            aMethod                                     ) ;

    private:

        Request::Method         method_ ;
        URL                     url_ ;
        String                  body_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////