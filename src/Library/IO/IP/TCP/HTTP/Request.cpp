////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/IP/TCP/HTTP/Request.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/IP/TCP/HTTP/Request.hpp>

#include <Library/Core/Containers/Map.hpp>
#include <Library/Core/Error.hpp>
#include <Library/Core/Utilities.hpp>

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

                                Request::Request                            (   const   Request::Method&            aMethod,
                                                                                const   URL&                        aUrl,
                                                                                const   String&                     aBody                                       )
                                :   method_(aMethod),
                                    url_(aUrl),
                                    body_(aBody)
{

}

bool                            Request::isDefined                          ( ) const
{
    return (method_ != Request::Method::Undefined) && url_.isDefined() ;
}

Request::Method                 Request::getMethod                          ( ) const
{
    return method_ ;
}

URL                             Request::getUrl                             ( ) const
{
    return url_ ;
}

String                          Request::getBody                            ( ) const
{
    return body_ ;
}

Request                         Request::Undefined                          ( )
{
    return { Request::Method::Undefined, URL::Undefined(), String::Empty() } ;
}

Request                         Request::Get                                (   const   URL&                        aUrl                                        )
{
    return { Request::Method::GET, aUrl, String::Empty() } ;
}

String                          Request::StringFromMethod                   (   const   Request::Method&            aMethod                                     )
{

    using library::core::ctnr::Map ;

    static const Map< Request::Method, String> methodStringMap = 
    {
        {
            {  Request::Method::Undefined, "Undefined" },
            {  Request::Method::GET, "GET" },
            {  Request::Method::HEAD, "HEAD" },
            {  Request::Method::POST, "POST" },
            {  Request::Method::PUT, "PUT" },
            {  Request::Method::DELETE, "DELETE" },
            {  Request::Method::TRACE, "TRACE" },
            {  Request::Method::OPTIONS, "OPTIONS" },
            {  Request::Method::CONNECT, "CONNECT" },
            {  Request::Method::PATCH, "PATCH" }
        }
    } ;

    return methodStringMap.at(aMethod) ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////