/// Apache License 2.0

#include <OpenSpaceToolkitIOPy/IP/TCP/HTTP.cpp>

inline void OpenSpaceToolkitIOPy_IP_TCP(pybind11::module& aModule)
{
    // Create "tcp" python submodule
    auto tcp = aModule.def_submodule("tcp");


    // Add custom types to python "tcp" submodule
    OpenSpaceToolkitIOPy_IP_TCP_HTTP(tcp);
}
