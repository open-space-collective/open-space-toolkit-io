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

        .def("isDefined", &URL::isDefined)

        .def("getScheme", &URL::getScheme)
        .def("getHost", &URL::getHost)
        .def("getPath", &URL::getPath)
        .def("getPort", &URL::getPort)
        .def("getUser", &URL::getUser)
        .def("getPassword", &URL::getPassword)
        .def("getQuery", &URL::getQuery)
        .def("getFragment", &URL::getFragment)
        .def("toString", &URL::toString, OpenSpaceToolkitIOPy_URL_toString_overloads())
        .def("setScheme", &URL::setScheme)
        .def("setHost", &URL::setHost)
        .def("setPath", &URL::setPath)
        .def("setPort", &URL::setPort)
        .def("setUser", &URL::setUser)
        .def("setPassword", &URL::setPassword)
        .def("setQuery", &URL::setQuery)
        .def("setFragment", &URL::setFragment)

        .def("Undefined", &URL::Undefined).staticmethod("Undefined")
        .def("Parse", &URL::Parse).staticmethod("Parse")
        // .def("EncodeString", &URL::EncodeString).staticmethod("EncodeString")
        // .def("DecodeString", &URL::DecodeString).staticmethod("DecodeString")

    ;

    OpenSpaceToolkitIOPy_URL_Query() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
