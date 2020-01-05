////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           bindings/python/src/OpenSpaceToolkitIOPy/IP/TCP/HTTP/Request.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Request.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitIOPy_IP_TCP_HTTP_Request    ( )
{

    using namespace boost::python ;

    using ostk::core::types::String ;

    using ostk::io::URL ;
    using ostk::io::ip::tcp::http::Request ;

    scope in_Request = class_<Request>("Request", init<const Request::Method&, const URL&, const String&>())

        .def(self_ns::str(self_ns::self))
        .def(self_ns::repr(self_ns::self))

		.def("is_defined", &Request::isDefined)
        .def("get_method", &Request::getMethod)
        .def("get_url", &Request::getUrl)
        .def("get_body", &Request::getBody)

        .def("undefined", &Request::Undefined).staticmethod("undefined")
        .def("get", &Request::Get).staticmethod("get")
        .def("string_from_method", &Request::StringFromMethod).staticmethod("string_from_method")

    ;

    enum_<Request::Method>("Method")

        .value("Undefined", Request::Method::Undefined)
        .value("Get", Request::Method::Get)
        .value("Head", Request::Method::Head)
        .value("Post", Request::Method::Post)
        .value("Put", Request::Method::Put)
        .value("Delete", Request::Method::Delete)
        .value("Trace", Request::Method::Trace)
        .value("Options", Request::Method::Options)
        .value("Connect", Request::Method::Connect)
        .value("Patch", Request::Method::Patch)
    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
