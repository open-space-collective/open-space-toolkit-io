/// Apache License 2.0

#include <OpenSpaceToolkitIOPy/IP/TCP.cpp>

inline void OpenSpaceToolkitIOPy_IP(nanobind::module_& aModule)
{
    // Create "ip" python submodule
    auto ip = aModule.def_submodule("ip");

    // Add custom types to python "ip" submodule
    OpenSpaceToolkitIOPy_IP_TCP(ip);
}
