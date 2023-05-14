/// Apache License 2.0

#include <OpenSpaceToolkitIOPy/IP/TCP/HTTP/Client.cpp>
#include <OpenSpaceToolkitIOPy/IP/TCP/HTTP/Response.cpp>
#include <OpenSpaceToolkitIOPy/IP/TCP/HTTP/Request.cpp>

inline void                     OpenSpaceToolkitIOPy_IP_TCP_HTTP            (           pybind11::module&           aModule                                     )
{

    // Create "http" python submodule
    auto http = aModule.def_submodule("http") ;

    // Add __path__ attribute for "http" submodule
    http.attr("__path__") = "ostk.io.ip.tcp.http" ;

    // Add custom types to python "http" submodule
    OpenSpaceToolkitIOPy_IP_TCP_HTTP_Request(http) ;
    OpenSpaceToolkitIOPy_IP_TCP_HTTP_Response(http) ;
    OpenSpaceToolkitIOPy_IP_TCP_HTTP_Client(http) ;

}
