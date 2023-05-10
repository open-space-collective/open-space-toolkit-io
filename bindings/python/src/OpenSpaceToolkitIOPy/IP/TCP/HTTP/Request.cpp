/// Apache License 2.0

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Request.hpp>

inline void OpenSpaceToolkitIOPy_IP_TCP_HTTP_Request(pybind11::module& aModule)
{
    using namespace pybind11;
    using ostk::core::types::String;

    using ostk::io::URL;
    using ostk::io::ip::tcp::http::Request;

    class_<Request> request(aModule, "Request");

    request
        .def(init<const Request::Method&, const URL&, const String&>())

        .def("__str__", &(shiftToString<Request>))
        .def("__repr__", &(shiftToString<Request>))

        .def("is_defined", &Request::isDefined)
        .def("get_method", &Request::getMethod)
        .def("get_url", &Request::getUrl)
        .def("get_body", &Request::getBody)

        .def_static("undefined", &Request::Undefined)
        .def_static("get", &Request::Get)
        .def_static("string_from_method", &Request::StringFromMethod)

        ;

    enum_<Request::Method>(request, "Method")

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
