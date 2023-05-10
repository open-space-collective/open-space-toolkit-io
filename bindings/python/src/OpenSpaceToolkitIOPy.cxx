/// Apache License 2.0

#include <OpenSpaceToolkitIOPy/Utilities/ShiftToString.hpp>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>

#include <OpenSpaceToolkitIOPy/IP.cpp>
#include <OpenSpaceToolkitIOPy/URL.cpp>

PYBIND11_MODULE(OpenSpaceToolkitIOPy, m)
{
    // Add optional docstring for package OpenSpaceToolkitIOPy
    m.doc() = "Addressing, networking, database connectors for OpenSpaceToolkit.";

    // Add __path__ attribute to python package
    m.attr("__path__") = "ostk.io";

    // Change attribute __name__ to make OpenSpaceToolkitIOPy invisible in import path
    m.attr("__name__") = "ostk.io";

// Package version information
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif

    // Add python submodules to OpenSpaceToolkitIOPy
    OpenSpaceToolkitIOPy_URL(m);
    OpenSpaceToolkitIOPy_IP(m);
}
