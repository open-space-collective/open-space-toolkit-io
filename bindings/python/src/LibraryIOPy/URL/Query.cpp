////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           LibraryIOPy/URL/Query.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <LibraryIOPy/Utilities/IterableConverter.hpp>

#include <OpenSpaceToolkit/IO/URL/Query.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryIOPy_URL_Query                       ( )
{

    using namespace boost::python ;

    using ostk::core::ctnr::Array ;

    using ostk::io::url::Query ;

    scope in_Query = class_<Query>("Query", init<const Array<Query::Parameter>&>())

        .def(self == self)
        .def(self != self)

        .def("__str__", +[] (const Query& aQuery) -> std::string { return aQuery.toString() ; })
        .def("__repr__", +[] (const Query& aQuery) -> std::string { return aQuery.toString() ; })

        .def("isDefined", &Query::isDefined)
        .def("hasParameterWithName", &Query::hasParameterWithName)

        .def("getParameterWithName", &Query::getParameterWithName)
        .def("toString", &Query::toString)
        .def("addParameter", &Query::addParameter)

        .def("Undefined", &Query::Undefined).staticmethod("Undefined")
        .def("Parse", &Query::Parse).staticmethod("Parse")

    ;

    scope in_Parameter = class_<Query::Parameter>("Parameter", init<const Query::Parameter::Name&, const Query::Parameter::Value&>())

        .def(self == self)
        .def(self != self)

        .def("isDefined", &Query::Parameter::isDefined)

        .def("getName", &Query::Parameter::getName)
        .def("getValue", &Query::Parameter::getValue)

    ;

    IterableConverter()

        .from_python<Array<Query::Parameter>>()
        .to_python<Array<Query::Parameter>>()

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
