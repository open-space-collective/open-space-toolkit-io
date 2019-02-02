////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           LibraryIOPy/IP/TCP/HTTP/Response.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/IP/TCP/HTTP/Response.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryIOPy_IP_TCP_HTTP_Response            ( )
{
    
    using namespace boost::python ;

    using library::core::types::String ;
    
    using library::io::ip::tcp::http::Response ;

    scope in_Response = class_<Response>("Response", init<const Response::StatusCode&, const String&>())

        .def(self_ns::str(self_ns::self))
        .def(self_ns::repr(self_ns::self))

		.def("isDefined", &Response::isDefined)
        .def("isOk", &Response::isOk)
        .def("getStatusCode", &Response::getStatusCode)
        .def("getBody", &Response::getBody)
        
        .def("Undefined", &Response::Undefined).staticmethod("Undefined")
        .def("StringFromStatusCode", &Response::StringFromStatusCode).staticmethod("StringFromStatusCode")

    ;

    enum_<Response::StatusCode>("StatusCode")

        .value("Undefined", Response::StatusCode::Undefined)
        .value("Continue", Response::StatusCode::Continue)
        .value("SwitchingProtocols", Response::StatusCode::SwitchingProtocols)
        .value("Processing", Response::StatusCode::Processing)
        .value("EarlyHints", Response::StatusCode::EarlyHints)
        .value("Ok", Response::StatusCode::Ok)
        .value("Created", Response::StatusCode::Created)
        .value("Accepted", Response::StatusCode::Accepted)
        .value("NonAuthoritativeInformation", Response::StatusCode::NonAuthoritativeInformation)
        .value("NoContent", Response::StatusCode::NoContent)
        .value("ResetContent", Response::StatusCode::ResetContent)
        .value("PartialContent", Response::StatusCode::PartialContent)
        .value("MultiStatus", Response::StatusCode::MultiStatus)
        .value("AlreadyReported", Response::StatusCode::AlreadyReported)
        .value("IMUsed", Response::StatusCode::IMUsed)
        .value("MultipleChoices", Response::StatusCode::MultipleChoices)
        .value("MovedPermanently", Response::StatusCode::MovedPermanently)
        .value("Found", Response::StatusCode::Found)
        .value("SeeOther", Response::StatusCode::SeeOther)
        .value("NotModified", Response::StatusCode::NotModified)
        .value("UseProxy", Response::StatusCode::UseProxy)
        .value("SwitchProxy", Response::StatusCode::SwitchProxy)
        .value("TemporaryRedirect", Response::StatusCode::TemporaryRedirect)
        .value("PermanentRedirect", Response::StatusCode::PermanentRedirect)
        .value("BadRequest", Response::StatusCode::BadRequest)
        .value("Unauthorized", Response::StatusCode::Unauthorized)
        .value("PaymentRequired", Response::StatusCode::PaymentRequired)
        .value("Forbidden", Response::StatusCode::Forbidden)
        .value("NotFound", Response::StatusCode::NotFound)
        .value("MethodNotAllowed", Response::StatusCode::MethodNotAllowed)
        .value("NotAcceptable", Response::StatusCode::NotAcceptable)
        .value("ProxyAuthenticationRequired", Response::StatusCode::ProxyAuthenticationRequired)
        .value("RequestTimeout", Response::StatusCode::RequestTimeout)
        .value("Conflict", Response::StatusCode::Conflict)
        .value("Gone", Response::StatusCode::Gone)
        .value("LengthRequired", Response::StatusCode::LengthRequired)
        .value("PreconditionFailed", Response::StatusCode::PreconditionFailed)
        .value("PayloadTooLarge", Response::StatusCode::PayloadTooLarge)
        .value("URITooLong", Response::StatusCode::URITooLong)
        .value("UnsupportedMediaType", Response::StatusCode::UnsupportedMediaType)
        .value("RangeNotSatisfiable", Response::StatusCode::RangeNotSatisfiable)
        .value("ExpectationFailed", Response::StatusCode::ExpectationFailed)
        .value("ImATeapot", Response::StatusCode::ImATeapot)
        .value("MisdirectedRequest", Response::StatusCode::MisdirectedRequest)
        .value("UnprocessableEntity", Response::StatusCode::UnprocessableEntity)
        .value("Locked", Response::StatusCode::Locked)
        .value("FailedDependency", Response::StatusCode::FailedDependency)
        .value("UpgradeRequired", Response::StatusCode::UpgradeRequired)
        .value("PreconditionRequired", Response::StatusCode::PreconditionRequired)
        .value("TooManyRequests", Response::StatusCode::TooManyRequests)
        .value("RequestHeaderFieldsTooLarge", Response::StatusCode::RequestHeaderFieldsTooLarge)
        .value("UnavailableForLegalReasons", Response::StatusCode::UnavailableForLegalReasons)
        .value("InternalServerError", Response::StatusCode::InternalServerError)
        .value("NotImplemented", Response::StatusCode::NotImplemented)
        .value("BadGateway", Response::StatusCode::BadGateway)
        .value("ServiceUnavailable", Response::StatusCode::ServiceUnavailable)
        .value("GatewayTimeout", Response::StatusCode::GatewayTimeout)
        .value("HTTPVersionNotSupported", Response::StatusCode::HTTPVersionNotSupported)
        .value("VariantAlsoNegotiates", Response::StatusCode::VariantAlsoNegotiates)
        .value("InsufficientStorage", Response::StatusCode::InsufficientStorage)
        .value("LoopDetected", Response::StatusCode::LoopDetected)
        .value("NotExtended", Response::StatusCode::NotExtended)
        .value("NetworkAuthenticationRequire", Response::StatusCode::NetworkAuthenticationRequire)
    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////