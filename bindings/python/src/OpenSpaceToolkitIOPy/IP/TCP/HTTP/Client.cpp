/// Apache License 2.0

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Client.hpp>

inline void OpenSpaceToolkitIOPy_IP_TCP_HTTP_Client(pybind11::module& aModule)
{
    using namespace pybind11;

    using ostk::io::ip::tcp::http::Client;

    class_<Client>(aModule, "Client")

        .def_static("send", &Client::Send)
        .def_static("get", &Client::Get)
        .def_static("fetch", &Client::Fetch)
        .def_static("list", &Client::List)

        ;
}
