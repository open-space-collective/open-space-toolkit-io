/// Apache License 2.0

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Response.hpp>

#include <OpenSpaceToolkit/Core/Containers/Map.hpp>
#include <OpenSpaceToolkit/Core/Error.hpp>
#include <OpenSpaceToolkit/Core/Utilities.hpp>

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

                                Response::Response                          (   const   Response::StatusCode&       aStatusCode,
                                                                                const   String&                     aBody                                       )
                                :   statusCode_(aStatusCode),
                                    body_(aBody)
{

}

std::ostream&                   operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Response&                   aResponse                                   )
{

    ostk::core::utils::Print::Header(anOutputStream, "Response") ;

    ostk::core::utils::Print::Line(anOutputStream) << "Status code:"         << String::Format("{} - {}", static_cast<uint>(aResponse.statusCode_), Response::StringFromStatusCode(aResponse.statusCode_)) ;
    ostk::core::utils::Print::Line(anOutputStream) << "Body:"                << aResponse.body_ ;

    ostk::core::utils::Print::Footer(anOutputStream) ;

    return anOutputStream ;

}

bool                            Response::isDefined                         ( ) const
{
    return statusCode_ != Response::StatusCode::Undefined ;
}

bool                            Response::isOk                              ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Response") ;
    }

    return statusCode_ == Response::StatusCode::Ok ;

}

Response::StatusCode            Response::getStatusCode                     ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Response") ;
    }

    return statusCode_ ;

}

String                          Response::getBody                           ( ) const
{

    if (!this->isDefined())
    {
        throw ostk::core::error::runtime::Undefined("Response") ;
    }

    return body_ ;

}

Response                        Response::Undefined                         ( )
{
    return { Response::StatusCode::Undefined, String::Empty() } ;
}

String                          Response::StringFromStatusCode              (   const   Response::StatusCode&       aStatusCode                                 )
{

    using ostk::core::ctnr::Map ;

    static const Map<Response::StatusCode, String> statusCodeStringMap =
    {
        {
            { Response::StatusCode::Undefined, "Undefined" },
            { Response::StatusCode::Continue, "Continue" },
            { Response::StatusCode::SwitchingProtocols, "SwitchingProtocols" },
            { Response::StatusCode::Processing, "Processing" },
            { Response::StatusCode::EarlyHints, "EarlyHints" },
            { Response::StatusCode::Ok, "Ok" },
            { Response::StatusCode::Created, "Created" },
            { Response::StatusCode::Accepted, "Accepted" },
            { Response::StatusCode::NonAuthoritativeInformation, "NonAuthoritativeInformation" },
            { Response::StatusCode::NoContent, "NoContent" },
            { Response::StatusCode::ResetContent, "ResetContent" },
            { Response::StatusCode::PartialContent, "PartialContent" },
            { Response::StatusCode::MultiStatus, "MultiStatus" },
            { Response::StatusCode::AlreadyReported, "AlreadyReported" },
            { Response::StatusCode::IMUsed, "IMUsed" },
            { Response::StatusCode::MultipleChoices, "MultipleChoices" },
            { Response::StatusCode::MovedPermanently, "MovedPermanently" },
            { Response::StatusCode::Found, "Found" },
            { Response::StatusCode::SeeOther, "SeeOther" },
            { Response::StatusCode::NotModified, "NotModified" },
            { Response::StatusCode::UseProxy, "UseProxy" },
            { Response::StatusCode::SwitchProxy, "SwitchProxy" },
            { Response::StatusCode::TemporaryRedirect, "TemporaryRedirect" },
            { Response::StatusCode::PermanentRedirect, "PermanentRedirect" },
            { Response::StatusCode::BadRequest, "BadRequest" },
            { Response::StatusCode::Unauthorized, "Unauthorized" },
            { Response::StatusCode::PaymentRequired, "PaymentRequired" },
            { Response::StatusCode::Forbidden, "Forbidden" },
            { Response::StatusCode::NotFound, "NotFound" },
            { Response::StatusCode::MethodNotAllowed, "MethodNotAllowed" },
            { Response::StatusCode::NotAcceptable, "NotAcceptable" },
            { Response::StatusCode::ProxyAuthenticationRequired, "ProxyAuthenticationRequired" },
            { Response::StatusCode::RequestTimeout, "RequestTimeout" },
            { Response::StatusCode::Conflict, "Conflict" },
            { Response::StatusCode::Gone, "Gone" },
            { Response::StatusCode::LengthRequired, "LengthRequired" },
            { Response::StatusCode::PreconditionFailed, "PreconditionFailed" },
            { Response::StatusCode::PayloadTooLarge, "PayloadTooLarge" },
            { Response::StatusCode::URITooLong, "URITooLong" },
            { Response::StatusCode::UnsupportedMediaType, "UnsupportedMediaType" },
            { Response::StatusCode::RangeNotSatisfiable, "RangeNotSatisfiable" },
            { Response::StatusCode::ExpectationFailed, "ExpectationFailed" },
            { Response::StatusCode::ImATeapot, "ImATeapot" },
            { Response::StatusCode::MisdirectedRequest, "MisdirectedRequest" },
            { Response::StatusCode::UnprocessableEntity, "UnprocessableEntity" },
            { Response::StatusCode::Locked, "Locked" },
            { Response::StatusCode::FailedDependency, "FailedDependency" },
            { Response::StatusCode::UpgradeRequired, "UpgradeRequired" },
            { Response::StatusCode::PreconditionRequired, "PreconditionRequired" },
            { Response::StatusCode::TooManyRequests, "TooManyRequests" },
            { Response::StatusCode::RequestHeaderFieldsTooLarge, "RequestHeaderFieldsTooLarge" },
            { Response::StatusCode::UnavailableForLegalReasons, "UnavailableForLegalReasons" },
            { Response::StatusCode::InternalServerError, "InternalServerError" },
            { Response::StatusCode::NotImplemented, "NotImplemented" },
            { Response::StatusCode::BadGateway, "BadGateway" },
            { Response::StatusCode::ServiceUnavailable, "ServiceUnavailable" },
            { Response::StatusCode::GatewayTimeout, "GatewayTimeout" },
            { Response::StatusCode::HTTPVersionNotSupported, "HTTPVersionNotSupported" },
            { Response::StatusCode::VariantAlsoNegotiates, "VariantAlsoNegotiates" },
            { Response::StatusCode::InsufficientStorage, "InsufficientStorage" },
            { Response::StatusCode::LoopDetected, "LoopDetected" },
            { Response::StatusCode::NotExtended, "NotExtended" },
            { Response::StatusCode::NetworkAuthenticationRequire, "NetworkAuthenticationRequire" }
        }
    } ;

    return statusCodeStringMap.at(aStatusCode) ;

}

}
}
}
}
}
