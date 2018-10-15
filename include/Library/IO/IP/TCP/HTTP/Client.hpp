////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/IP/TCP/HTTP/Client.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_IO_IP_TCP_HTTP_Client__
#define __Library_IO_IP_TCP_HTTP_Client__

#include <Library/IO/IP/TCP/HTTP/Response.hpp>
#include <Library/IO/IP/TCP/HTTP/Request.hpp>
#include <Library/IO/URL.hpp>

#include <Library/Core/FileSystem/Directory.hpp>
#include <Library/Core/FileSystem/File.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
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

using library::core::fs::File ;
using library::core::fs::Directory ;

using library::io::URL ;
using library::io::ip::tcp::http::Request ;
using library::io::ip::tcp::http::Response ;

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