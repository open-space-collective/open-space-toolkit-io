////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ I/O
/// @file           Library/IO/IP/TCP/HTTP/Request.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/IP/TCP/HTTP/Request.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (Library_IO_IP_TCP_HTTP_Request, Constructor)
{

    using library::core::types::String ;

    using library::io::URL ;
    using library::io::ip::tcp::http::Request ;

    {

        const Request::Method method = Request::Method::Get ;
        const URL url = URL::Parse("https://www.google.com") ;
        const String body = "body" ;

        EXPECT_NO_THROW(Request request (method, url, body) ;) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Request, StreamOperator)
{

    using library::core::types::String ;

    using library::io::URL ;
    using library::io::ip::tcp::http::Request ;

    {

        const Request::Method method = Request::Method::Get ;
        const URL url = URL::Parse("https://www.google.com") ;
        const String body = "body" ;

        const Request request = { method, url, body } ;

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << request << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Request, IsDefined)
{

    using library::core::types::String ;

    using library::io::URL ;
    using library::io::ip::tcp::http::Request ;

    {

        const Request::Method method = Request::Method::Get ;
        const URL url = URL::Parse("https://www.google.com") ;
        const String body = "body" ;

        const Request request = { method, url, body } ;

        EXPECT_TRUE(request.isDefined()) ;

    }

    {

        EXPECT_FALSE(Request::Undefined().isDefined()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Request, GetMethod)
{

    using library::core::types::String ;

    using library::io::URL ;
    using library::io::ip::tcp::http::Request ;

    {

        const Request::Method method = Request::Method::Get ;
        const URL url = URL::Parse("https://www.google.com") ;
        const String body = "body" ;

        const Request request = { method, url, body } ;

        EXPECT_EQ(method, request.getMethod()) ;

    }

    {

        EXPECT_ANY_THROW(Request::Undefined().getMethod()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Request, GetUrl)
{

    using library::core::types::String ;

    using library::io::URL ;
    using library::io::ip::tcp::http::Request ;

    {

        const Request::Method method = Request::Method::Get ;
        const URL url = URL::Parse("https://www.google.com") ;
        const String body = "body" ;

        const Request request = { method, url, body } ;

        EXPECT_EQ(url, request.getUrl()) ;

    }

    {

        EXPECT_ANY_THROW(Request::Undefined().getUrl()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Request, GetBody)
{

    using library::core::types::String ;

    using library::io::URL ;
    using library::io::ip::tcp::http::Request ;

    {

        const Request::Method method = Request::Method::Get ;
        const URL url = URL::Parse("https://www.google.com") ;
        const String body = "Hello World!" ;

        const Request request = { method, url, body } ;

        EXPECT_EQ(body, request.getBody()) ;

    }

    {

        EXPECT_ANY_THROW(Request::Undefined().getBody()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Request, Undefined)
{

    using library::io::ip::tcp::http::Request ;

    {

        EXPECT_NO_THROW(Request::Undefined()) ;
        EXPECT_FALSE(Request::Undefined().isDefined()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Request, Get)
{

    using library::io::URL ;
    using library::io::ip::tcp::http::Request ;

    {

        const URL url = URL::Parse("https://www.google.com") ;

        EXPECT_EQ(Request::Method::Get, Request::Get(url).getMethod()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Request, StringFromMethod)
{

    using library::io::ip::tcp::http::Request ;

    {

        EXPECT_EQ("Undefined", Request::StringFromMethod(Request::Method::Undefined)) ;
        EXPECT_EQ("Get", Request::StringFromMethod(Request::Method::Get)) ;
        EXPECT_EQ("Head", Request::StringFromMethod(Request::Method::Head)) ;
        EXPECT_EQ("Post", Request::StringFromMethod(Request::Method::Post)) ;
        EXPECT_EQ("Put", Request::StringFromMethod(Request::Method::Put)) ;
        EXPECT_EQ("Delete", Request::StringFromMethod(Request::Method::Delete)) ;
        EXPECT_EQ("Trace", Request::StringFromMethod(Request::Method::Trace)) ;
        EXPECT_EQ("Options", Request::StringFromMethod(Request::Method::Options)) ;
        EXPECT_EQ("Connect", Request::StringFromMethod(Request::Method::Connect)) ;
        EXPECT_EQ("Patch", Request::StringFromMethod(Request::Method::Patch)) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
