/// Apache License 2.0

#include <OpenSpaceToolkitIOPy/IP/TCP.cpp>

inline void OpenSpaceToolkitIOPy_IP(pybind11::module& aModule)
{
    // Create "ip" python submodule
    auto ip = aModule.def_submodule("ip");

    // Add custom types to python "ip" submodule
    OpenSpaceToolkitIOPy_IP_TCP(ip);
}
