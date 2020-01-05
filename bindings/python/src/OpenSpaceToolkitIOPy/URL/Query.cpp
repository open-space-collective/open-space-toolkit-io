////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           bindings/python/src/OpenSpaceToolkitIOPy/URL/Query.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkitIOPy/Utilities/IterableConverter.hpp>

#include <OpenSpaceToolkit/IO/URL/Query.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitIOPy_URL_Query              ( )
{

    using namespace boost::python ;

    using ostk::core::ctnr::Array ;

    using ostk::io::url::Query ;

    scope in_Query = class_<Query>("Query", init<const Array<Query::Parameter>&>())

        .def(self == self)
        .def(self != self)

        .def("__str__", +[] (const Query& aQuery) -> std::string { return aQuery.toString() ; })
        .def("__repr__", +[] (const Query& aQuery) -> std::string { return aQuery.toString() ; })

        .def("is_defined", &Query::isDefined)
        .def("has_parameter_with_name", &Query::hasParameterWithName)

        .def("get_parameter_with_name", &Query::getParameterWithName)
        .def("to_string", &Query::toString)
        .def("add_parameter", &Query::addParameter)

        .def("undefined", &Query::Undefined).staticmethod("undefined")
        .def("parse", &Query::Parse).staticmethod("parse")

    ;

    scope in_Parameter = class_<Query::Parameter>("Parameter", init<const Query::Parameter::Name&, const Query::Parameter::Value&>())

        .def(self == self)
        .def(self != self)

        .def("is_defined", &Query::Parameter::isDefined)

        .def("get_name", &Query::Parameter::getName)
        .def("get_value", &Query::Parameter::getValue)

    ;

    IterableConverter()

        .from_python<Array<Query::Parameter>>()
        .to_python<Array<Query::Parameter>>()

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
