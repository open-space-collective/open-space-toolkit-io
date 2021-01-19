////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           bindings/python/src/OpenSpaceToolkitIOPy/URL/Query.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkitIOPy/Utilities/ArrayCasting.hpp>
#include <OpenSpaceToolkit/IO/URL/Query.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using ostk::core::ctnr::Array ;
using ostk::io::url::Query ;

void          set_array(const Array<Query::Parameter>& anArray) { (void) anArray ; }

inline void                     OpenSpaceToolkitIOPy_URL_Query              (              pybind11::module&                              aModule              )
{

    using namespace pybind11 ;

    using ostk::core::ctnr::Array ;

    using ostk::io::url::Query ;

    class_<Query> query(aModule, "Query") ;

    query.def(init<const Array<Query::Parameter>&>())

        .def(self == self)
        .def(self != self)

        .def("__str__", &(shift_to_string<Query>))
        .def("__repr__", &(shift_to_string<Query>))

        .def("is_defined", &Query::isDefined)
        .def("has_parameter_with_name", &Query::hasParameterWithName)

        .def("get_parameter_with_name", &Query::getParameterWithName)
        .def("to_string", &Query::toString)
        .def("add_parameter", &Query::addParameter)

        .def_static("undefined", &Query::Undefined)
        .def_static("parse", &Query::Parse)

    ;

    class_<Query::Parameter> param(aModule, "Parameter") ;

    param.def(init<const Query::Parameter::Name&, const Query::Parameter::Value&>())

        .def(self == self)
        .def(self != self)

        .def("is_defined", &Query::Parameter::isDefined)

        .def("get_name", &Query::Parameter::getName)
        .def("get_value", &Query::Parameter::getValue)

    ;

    aModule.attr("Query") = query ;
    aModule.attr("Parameter") = param ;

    aModule.def("set_array", overload_cast<const Array<Query::Parameter>&>(&set_array));

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
