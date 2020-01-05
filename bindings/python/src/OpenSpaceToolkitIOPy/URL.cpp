////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           bindings/python/src/OpenSpaceToolkitIOPy/URL.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkitIOPy/URL/Query.cpp>

#include <OpenSpaceToolkit/IO/URL.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS (OpenSpaceToolkitIOPy_URL_toString_overloads, ostk::io::URL::toString, 0, 1)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitIOPy_URL                    ( )
{

    using namespace boost::python ;

    using ostk::core::types::Integer ;
    using ostk::core::types::String ;

    using ostk::io::URL ;
    using ostk::io::url::Query ;

    scope in_URL = class_<URL>("URL", init<const String&, const String&, const String&, const Integer&, const String&, const String&, const Query&, const String&>())

        .def(self == self)
        .def(self != self)

        .def(self + String())
        .def(self += String())

        .def(self_ns::str(self_ns::self))

        .def("__repr__", +[] (const URL& aUrl) -> std::string { return aUrl.toString() ; })

        .def("is_defined", &URL::isDefined)

        .def("get_scheme", &URL::getScheme)
        .def("get_host", &URL::getHost)
        .def("get_path", &URL::getPath)
        .def("get_port", &URL::getPort)
        .def("get_user", &URL::getUser)
        .def("get_password", &URL::getPassword)
        .def("get_query", &URL::getQuery)
        .def("get_fragment", &URL::getFragment)
        .def("to_string", &URL::toString, OpenSpaceToolkitIOPy_URL_toString_overloads())
        .def("set_scheme", &URL::setScheme)
        .def("set_host", &URL::setHost)
        .def("set_path", &URL::setPath)
        .def("set_port", &URL::setPort)
        .def("set_user", &URL::setUser)
        .def("set_password", &URL::setPassword)
        .def("set_query", &URL::setQuery)
        .def("set_fragment", &URL::setFragment)

        .def("undefined", &URL::Undefined).staticmethod("undefined")
        .def("parse", &URL::Parse).staticmethod("parse")
        // .def("encode_string", &URL::EncodeString).staticmethod("encode_string")
        // .def("decode_string", &URL::DecodeString).staticmethod("decode_string")

    ;

    OpenSpaceToolkitIOPy_URL_Query() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
