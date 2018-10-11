////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/IP/TCP/HTTP/Request.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

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

class Request
{

    public:

        enum class Method
        {

            Undefined,
            GET,
            HEAD,
            POST,
            PUT,
            DELETE,
            TRACE,
            OPTIONS,
            CONNECT,
            PATCH

        } ;

                                Request                                     (   const   Request::Method&            aMethod,
                                                                                const   URL&                        aUrl,
                                                                                const   String&                     aBody                                       ) ;

        bool                    isDefined                                   ( ) const ;

        Request::Method         getMethod                                   ( ) const ;
        
        URL                     getUrl                                      ( ) const ;

        String                  getBody                                     ( ) const ;

        static Request          Undefined                                   ( ) ;

        static Request          Get                                         (   const   URL&                        aUrl                                        ) ;

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