/// Apache License 2.0

#include <OpenSpaceToolkitIOPy/IP/TCP/HTTP.cpp>

inline void OpenSpaceToolkitIOPy_IP_TCP(pybind11::module& aModule)
{
    // Create "tcp" python submodule
    auto tcp = aModule.def_submodule("tcp");

    // Add __path__ attribute for "tcp" submodule
    tcp.attr("__path__") = "ostk.io.ip.tcp";

    // Add custom types to python "tcp" submodule
    OpenSpaceToolkitIOPy_IP_TCP_HTTP(tcp);
}
