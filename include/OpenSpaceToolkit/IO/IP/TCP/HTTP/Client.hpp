/// Apache License 2.0

#ifndef __OpenSpaceToolkit_IO_IP_TCP_HTTP_Client__
#define __OpenSpaceToolkit_IO_IP_TCP_HTTP_Client__

#include <OpenSpaceToolkit/Core/FileSystem/Directory.hpp>
#include <OpenSpaceToolkit/Core/FileSystem/File.hpp>
#include <OpenSpaceToolkit/Core/Type/Size.hpp>

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Request.hpp>
#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Response.hpp>
#include <OpenSpaceToolkit/IO/URL.hpp>

namespace ostk
{
namespace io
{
namespace ip
{
namespace tcp
{
namespace http
{

using ostk::core::type::Size;
using ostk::core::filesystem::File;
using ostk::core::filesystem::Directory;

using ostk::io::URL;
using ostk::io::ip::tcp::http::Request;
using ostk::io::ip::tcp::http::Response;

/// @brief                      Hypertext Transfer Protocol (HTTP) client
///
/// @ref                        https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol

class Client
{
   public:
    /// @brief              Default constructor (deleted)

    Client() = delete;

    /// @brief              Send a HTTP request
    ///
    /// @param              [in] aRequest A HTTP request
    /// @return             A HTTP response

    static Response Send(const Request& aRequest);

    /// @brief              Send a HTTP GET request
    ///
    /// @param              [in] aUrl A URL
    /// @return             A HTTP response

    static Response Get(const URL& aUrl);

    /// @brief              Fetch file over HTTP
    ///
    /// @param              [in] aUrl A URL
    /// @param              [in] aDirectory A destination directory
    /// @param              [in] (optional) aFollowCount Number of redirects to follow
    /// @return             A file

    static File Fetch(const URL& aUrl, const Directory& aDirectory, const Size& aFollowCount = 0);

    /// @brief              List files
    ///
    /// @param              [in] aUrl A URL
    /// @param              [in] aFile A destination file
    /// @param              [in] (optional) showNamesOnly If true, only show file names

    static void List(const URL& aUrl, const File& aFile, const bool showNamesOnly = false);
};

}  // namespace http
}  // namespace tcp
}  // namespace ip
}  // namespace io
}  // namespace ostk

#endif
