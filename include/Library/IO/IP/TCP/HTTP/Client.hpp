////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           Library/IO/IP/TCP/HTTP/Client.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __OpenSpaceToolkit_IO_IP_TCP_HTTP_Client__
#define __OpenSpaceToolkit_IO_IP_TCP_HTTP_Client__

#include <Library/IO/IP/TCP/HTTP/Response.hpp>
#include <Library/IO/IP/TCP/HTTP/Request.hpp>
#include <Library/IO/URL.hpp>

#include <OpenSpaceToolkit/Core/FileSystem/Directory.hpp>
#include <OpenSpaceToolkit/Core/FileSystem/File.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using ostk::core::fs::File ;
using ostk::core::fs::Directory ;

using ostk::io::URL ;
using ostk::io::ip::tcp::http::Request ;
using ostk::io::ip::tcp::http::Response ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Hypertext Transfer Protocol (HTTP) client
///
/// @ref                        https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol

class Client
{

    public:

        /// @brief              Default constructor (deleted)

                                Client                                      ( ) = delete ;

        /// @brief              Send a HTTP request
        ///
        /// @param              [in] aRequest A HTTP request
        /// @return             A HTTP response

        static Response         Send                                        (   const   Request&                    aRequest                                    ) ;

        /// @brief              Send a HTTP GET request
        ///
        /// @param              [in] aUrl A URL
        /// @return             A HTTP response

        static Response         Get                                         (   const   URL&                        aUrl                                        ) ;

        /// @brief              Fetch file over HTTP
        ///
        /// @param              [in] aUrl A URL
        /// @param              [in] aDirectory A destination directory
        /// @return             A file

        static File             Fetch                                       (   const   URL&                        aUrl,
                                                                                const   Directory&                  aDirectory                                  ) ;

        /// @brief              List files
        ///
        /// @param              [in] aUrl A URL
        /// @param              [in] aFile A destination file
        /// @param              [in] (optional) showNamesOnly If true, only show file names

        static void             List                                        (   const   URL&                        aUrl,
                                                                                const   File&                       aFile,
                                                                                const   bool                        showNamesOnly                               =   false ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
