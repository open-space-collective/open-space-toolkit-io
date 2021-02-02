////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           bindings/python/src/OpenSpaceToolkitIOPy/IP/TCP/HTTP/Response.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Response.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitIOPy_IP_TCP_HTTP_Response   (           pybind11::module&           aModule                                     )
{

    using namespace pybind11 ;

    using ostk::core::types::String ;

    using ostk::io::ip::tcp::http::Response ;

    class_<Response> response (aModule, "Response") ;

    response.def(init<const Response::StatusCode&, const String&>())

        .def("__str__", &(shiftToString<Response>))
        .def("__repr__", &(shiftToString<Response>))

		.def("is_defined", &Response::isDefined)
        .def("is_ok", &Response::isOk)
        .def("get_status_code", &Response::getStatusCode)
        .def("get_body", &Response::getBody)

        .def_static("undefined", &Response::Undefined)
        .def_static("string_from_status_code", &Response::StringFromStatusCode)

    ;

    enum_<Response::StatusCode>(response, "StatusCode")

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
