////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           OpenSpaceToolkit/IO/IP/TCP/HTTP/Response.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __OpenSpaceToolkit_IO_IP_TCP_HTTP_Response__
#define __OpenSpaceToolkit_IO_IP_TCP_HTTP_Response__

#include <OpenSpaceToolkit/Core/Types/String.hpp>

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

using ostk::core::types::String ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Hypertext Transfer Protocol (HTTP) response
///
/// @ref                        https://en.wikipedia.org/wiki/List_of_HTTP_status_codes

class Response
{

    public:

        enum class StatusCode
        {

            Undefined                       = 0,                                ///< Undefined

            Continue                        = 100,                              ///< 100 Continue
            SwitchingProtocols              = 101,                              ///< 101 Switching Protocols
            Processing                      = 102,                              ///< 102 Processing (WebDAV; RFC 2518)
            EarlyHints                      = 103,                              ///< 103 Early Hints (RFC 8297)

            Ok                              = 200,                              ///< 200 OK
            Created                         = 201,                              ///< 201 Created
            Accepted                        = 202,                              ///< 202 Accepted
            NonAuthoritativeInformation     = 203,                              ///< 203 Non-Authoritative Information (since HTTP/1.1)
            NoContent                       = 204,                              ///< 204 No Content
            ResetContent                    = 205,                              ///< 205 Reset Content
            PartialContent                  = 206,                              ///< 206 Partial Content (RFC 7233)
            MultiStatus                     = 207,                              ///< 207 Multi-Status (WebDAV; RFC 4918)
            AlreadyReported                 = 208,                              ///< 208 Already Reported (WebDAV; RFC 5842)
            IMUsed                          = 226,                              ///< 226 IM Used (RFC 3229)

            MultipleChoices                 = 300,                              ///< 300 Multiple Choices
            MovedPermanently                = 301,                              ///< 301 Moved Permanently
            Found                           = 302,                              ///< 302 Found (Previously "Moved temporarily")
            SeeOther                        = 303,                              ///< 303 See Other (since HTTP/1.1)
            NotModified                     = 304,                              ///< 304 Not Modified (RFC 7232)
            UseProxy                        = 305,                              ///< 305 Use Proxy (since HTTP/1.1)
            SwitchProxy                     = 306,                              ///< 306 Switch Proxy
            TemporaryRedirect               = 307,                              ///< 307 Temporary Redirect (since HTTP/1.1)
            PermanentRedirect               = 308,                              ///< 308 Permanent Redirect (RFC 7538)

            BadRequest                      = 400,                              ///< 400 Bad Request
            Unauthorized                    = 401,                              ///< 401 Unauthorized (RFC 7235)
            PaymentRequired                 = 402,                              ///< 402 Payment Required
            Forbidden                       = 403,                              ///< 403 Forbidden
            NotFound                        = 404,                              ///< 404 Not Found
            MethodNotAllowed                = 405,                              ///< 405 Method Not Allowed
            NotAcceptable                   = 406,                              ///< 406 Not Acceptable
            ProxyAuthenticationRequired     = 407,                              ///< 407 Proxy Authentication Required (RFC 7235)
            RequestTimeout                  = 408,                              ///< 408 Request Timeout
            Conflict                        = 409,                              ///< 409 Conflict
            Gone                            = 410,                              ///< 410 Gone
            LengthRequired                  = 411,                              ///< 411 Length Required
            PreconditionFailed              = 412,                              ///< 412 Precondition Failed (RFC 7232)
            PayloadTooLarge                 = 413,                              ///< 413 Payload Too Large (RFC 7231)
            URITooLong                      = 414,                              ///< 414 URI Too Long (RFC 7231)
            UnsupportedMediaType            = 415,                              ///< 415 Unsupported Media Type
            RangeNotSatisfiable             = 416,                              ///< 416 Range Not Satisfiable (RFC 7233)
            ExpectationFailed               = 417,                              ///< 417 Expectation Failed
            ImATeapot                       = 418,                              ///< 418 I'm a teapot (RFC 2324, RFC 7168)
            MisdirectedRequest              = 421,                              ///< 421 Misdirected Request (RFC 7540)
            UnprocessableEntity             = 422,                              ///< 422 Unprocessable Entity (WebDAV; RFC 4918)
            Locked                          = 423,                              ///< 423 Locked (WebDAV; RFC 4918)
            FailedDependency                = 424,                              ///< 424 Failed Dependency (WebDAV; RFC 4918)
            UpgradeRequired                 = 426,                              ///< 426 Upgrade Required
            PreconditionRequired            = 428,                              ///< 428 Precondition Required (RFC 6585)
            TooManyRequests                 = 429,                              ///< 429 Too Many Requests (RFC 6585)
            RequestHeaderFieldsTooLarge     = 431,                              ///< 431 Request Header Fields Too Large (RFC 6585)
            UnavailableForLegalReasons      = 451,                              ///< 451 Unavailable For Legal Reasons (RFC 7725)

            InternalServerError             = 500,                              ///< 500 Internal Server Error
            NotImplemented                  = 501,                              ///< 501 Not Implemented
            BadGateway                      = 502,                              ///< 502 Bad Gateway
            ServiceUnavailable              = 503,                              ///< 503 Service Unavailable
            GatewayTimeout                  = 504,                              ///< 504 Gateway Timeout
            HTTPVersionNotSupported         = 505,                              ///< 505 HTTP Version Not Supported
            VariantAlsoNegotiates           = 506,                              ///< 506 Variant Also Negotiates (RFC 2295)
            InsufficientStorage             = 507,                              ///< 507 Insufficient Storage (WebDAV; RFC 4918)
            LoopDetected                    = 508,                              ///< 508 Loop Detected (WebDAV; RFC 5842)
            NotExtended                     = 510,                              ///< 510 Not Extended (RFC 2774)
            NetworkAuthenticationRequire    = 511                               ///< 511 Network Authentication Required (RFC 6585)d

        } ;

        /// @brief              Constructor
        ///
        /// @param              [in] aStatusCode A status code
        /// @param              [in] aBody A body

                                Response                                    (   const   Response::StatusCode&       aStatusCode,
                                                                                const   String&                     aBody                                       ) ;

        /// @brief              Output stream operator
        ///
        /// @param              [in] anOutputStream An output stream
        /// @param              [in] aResponse A response
        /// @return             An output stream

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Response&                   aResponse                                   ) ;

        /// @brief              Check if response is defined
        ///
        /// @return             True if response is defined

        bool                    isDefined                                   ( ) const ;

        /// @brief              Check if response status code is Ok
        ///
        /// @return             True if response status code is Ok

        bool                    isOk                                        ( ) const ;

        /// @brief              Get response status code
        ///
        /// @return             Response status code

        Response::StatusCode    getStatusCode                               ( ) const ;

        /// @brief              Get response body
        ///
        /// @return             Response body

        String                  getBody                                     ( ) const ;

        /// @brief              Constructs an undefined response
        ///
        /// @return             Undefined response

        static Response         Undefined                                   ( ) ;

        /// @brief              Converts response status code to string
        ///
        /// @param              [in] aStatusCode A response status code
        /// @return             Response status code string

        static String           StringFromStatusCode                        (   const   Response::StatusCode&       aStatusCode                                 ) ;

    private:

        Response::StatusCode    statusCode_ ;
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
