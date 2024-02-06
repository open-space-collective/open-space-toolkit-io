/// Apache License 2.0

#include <OpenSpaceToolkitIOPy/Utilities/ArrayCasting.hpp>

#include <OpenSpaceToolkit/IO/URL/Query.hpp>

using ostk::core::container::Array;
using ostk::io::url::Query;

void set_array(const Array<Query::Parameter>& anArray)
{
    (void)anArray;
}

// Taking a python class as input to mimic previous behavior with Boost. Can be refined later if needed
inline void OpenSpaceToolkitIOPy_URL_Query(auto aClass)
{
    using namespace pybind11;

    using ostk::core::container::Array;

    using ostk::io::url::Query;

    class_<Query> query(aClass, "Query");

    query
        .def(init<const Array<Query::Parameter>&>())

        .def(self == self)
        .def(self != self)

        // Operator definition needed to use template
        // .def("__str__", &(shiftToString<Query>))
        // .def("__repr__", &(shiftToString<Query>))
        .def(
            "__str__",
            +[](const Query& aQuery) -> std::string
            {
                return aQuery.toString();
            }
        )
        .def(
            "__repr__",
            +[](const Query& aQuery) -> std::string
            {
                return aQuery.toString();
            }
        )

        .def("is_defined", &Query::isDefined)
        .def("has_parameter_with_name", &Query::hasParameterWithName)

        .def("get_parameter_with_name", &Query::getParameterWithName)
        .def("to_string", &Query::toString)
        .def("add_parameter", &Query::addParameter)

        .def_static("undefined", &Query::Undefined)
        .def_static("parse", &Query::Parse)

        ;

    class_<Query::Parameter> param(query, "Parameter");

    param
        .def(init<const Query::Parameter::Name&, const Query::Parameter::Value&>())

        .def(self == self)
        .def(self != self)

        .def("is_defined", &Query::Parameter::isDefined)

        .def("get_name", &Query::Parameter::getName)
        .def("get_value", &Query::Parameter::getValue)

        ;

    aClass.def("set_array", overload_cast<const Array<Query::Parameter>&>(&set_array));
}
