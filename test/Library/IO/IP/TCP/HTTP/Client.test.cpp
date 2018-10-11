////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/IP/TCP/HTTP/Client.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Global.test.hpp>

#include <Library/IO/IP/TCP/HTTP/Client.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (Library_IO_IP_TCP_HTTP_Client, Send)
{

    using library::io::URL ;
    using library::io::ip::tcp::http::Request ;
    using library::io::ip::tcp::http::Response ;
    using library::io::ip::tcp::http::Client ;

    {

        const URL url = URL::Parse("https://www.google.com") ;

        const Response response = Client::Send(Request::Get(url)) ;

        EXPECT_TRUE(response.isOk()) ;
        EXPECT_FALSE(response.getBody().isEmpty()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Client, Get)
{

    using library::io::URL ;
    using library::io::ip::tcp::http::Response ;
    using library::io::ip::tcp::http::Client ;

    {

        const URL url = URL::Parse("http://www.google.com") ;

        const Response response = Client::Get(url) ;

        EXPECT_TRUE(response.isOk()) ;
        EXPECT_FALSE(response.getBody().isEmpty()) ;

    }

    {

        const URL url = URL::Parse("https://www.google.com") ;

        const Response response = Client::Get(url) ;

        EXPECT_TRUE(response.isOk()) ;
        EXPECT_FALSE(response.getBody().isEmpty()) ;

    }

    {

        const URL url = URL::Parse("https://www.google.com/this-page-does-not-exist") ;

        const Response response = Client::Get(url) ;

        EXPECT_EQ(Response::StatusCode::NotFound, response.getStatusCode()) ;

    }

    {

        const URL url = URL::Parse("http://this-address-does-not-exist.com") ;

        EXPECT_ANY_THROW(Client::Get(url)) ;

    }

    {

        const URL url = URL::Parse("https://this-address-does-not-exist.com") ;

        EXPECT_ANY_THROW(Client::Get(url)) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Client, Fetch)
{

    using library::core::fs::Path ;
    using library::core::fs::File ;
    using library::core::fs::Directory ;
    
    using library::io::URL ;
    using library::io::ip::tcp::http::Client ;

    {

        const URL url = URL::Parse("https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_272x92dp.png") ;

        const Directory directory = Directory::Path(Path::Parse("/tmp")) ;

        const File file = Client::Fetch(url, directory) ;

        EXPECT_TRUE(file.exists()) ;
        EXPECT_EQ("googlelogo_color_272x92dp.png", file.getName()) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////