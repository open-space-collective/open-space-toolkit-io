/// Apache License 2.0

#include <OpenSpaceToolkit/IO/URL.hpp>

#include <OpenSpaceToolkitIOPy/URL/Query.cpp>

// https://pybind11.readthedocs.io/en/stable/basics.html#default-args

inline void OpenSpaceToolkitIOPy_URL(pybind11::module& aModule)
{
    using namespace pybind11;

    using ostk::core::types::Integer;
    using ostk::core::types::String;

    using ostk::io::URL;
    using ostk::io::url::Query;

    class_<URL> url_class(aModule, "URL");

    url_class
        .def(init<
             const String&,
             const String&,
             const String&,
             const Integer&,
             const String&,
             const String&,
             const Query&,
             const String&>())

        .def(self == self)
        .def(self != self)

        .def(self + String())
        .def(self += String())

        .def("__str__", &(shiftToString<URL>))
        .def(
            "__repr__",
            +[](const URL& aUrl) -> std::string
            {
                return aUrl.toString();
            }
        )

        .def("is_defined", &URL::isDefined)

        .def("get_scheme", &URL::getScheme)
        .def("get_host", &URL::getHost)
        .def("get_path", &URL::getPath)
        .def("get_port", &URL::getPort)
        .def("get_user", &URL::getUser)
        .def("get_password", &URL::getPassword)
        .def("get_query", &URL::getQuery)
        .def("get_fragment", &URL::getFragment)

        .def("to_string", &URL::toString, "doSanitize"_a = false)
        .def("set_scheme", &URL::setScheme)
        .def("set_host", &URL::setHost)
        .def("set_path", &URL::setPath)
        .def("set_port", &URL::setPort)
        .def("set_user", &URL::setUser)
        .def("set_password", &URL::setPassword)
        .def("set_query", &URL::setQuery)
        .def("set_fragment", &URL::setFragment)

        .def_static("undefined", &URL::Undefined)
        .def_static("parse", &URL::Parse)
        // .def_static("encode_string", &URL::EncodeString)
        // .def_static("decode_string", &URL::DecodeString)

        ;

    OpenSpaceToolkitIOPy_URL_Query(url_class);
}
