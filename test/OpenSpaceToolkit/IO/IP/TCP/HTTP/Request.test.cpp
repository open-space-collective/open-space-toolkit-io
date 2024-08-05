/// Apache License 2.0

#include <iostream>

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Request.hpp>

#include <Global.test.hpp>

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, Constructor)
{
    using ostk::core::type::String;

    using ostk::io::ip::tcp::http::Request;
    using ostk::io::URL;

    {
        const Request::Method method = Request::Method::Get;
        const URL url = URL::Parse("https://www.google.com");
        const String body = "body";

        EXPECT_NO_THROW(Request request(method, url, body););
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, StreamOperator)
{
    using ostk::core::type::String;

    using ostk::io::ip::tcp::http::Request;
    using ostk::io::URL;

    {
        const Request::Method method = Request::Method::Get;
        const URL url = URL::Parse("https://www.google.com");
        const String body = "body";

        const Request request = {method, url, body};

        testing::internal::CaptureStdout();

        EXPECT_NO_THROW(std::cout << request << std::endl);

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty());
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, IsDefined)
{
    using ostk::core::type::String;

    using ostk::io::ip::tcp::http::Request;
    using ostk::io::URL;

    {
        const Request::Method method = Request::Method::Get;
        const URL url = URL::Parse("https://www.google.com");
        const String body = "body";

        const Request request = {method, url, body};

        EXPECT_TRUE(request.isDefined());
    }

    {
        EXPECT_FALSE(Request::Undefined().isDefined());
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, GetMethod)
{
    using ostk::core::type::String;

    using ostk::io::ip::tcp::http::Request;
    using ostk::io::URL;

    {
        const Request::Method method = Request::Method::Get;
        const URL url = URL::Parse("https://www.google.com");
        const String body = "body";

        const Request request = {method, url, body};

        EXPECT_EQ(method, request.getMethod());
    }

    {
        EXPECT_ANY_THROW(Request::Undefined().getMethod());
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, GetUrl)
{
    using ostk::core::type::String;

    using ostk::io::ip::tcp::http::Request;
    using ostk::io::URL;

    {
        const Request::Method method = Request::Method::Get;
        const URL url = URL::Parse("https://www.google.com");
        const String body = "body";

        const Request request = {method, url, body};

        EXPECT_EQ(url, request.getUrl());
    }

    {
        EXPECT_ANY_THROW(Request::Undefined().getUrl());
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, GetBody)
{
    using ostk::core::type::String;

    using ostk::io::ip::tcp::http::Request;
    using ostk::io::URL;

    {
        const Request::Method method = Request::Method::Get;
        const URL url = URL::Parse("https://www.google.com");
        const String body = "Hello World!";

        const Request request = {method, url, body};

        EXPECT_EQ(body, request.getBody());
    }

    {
        EXPECT_ANY_THROW(Request::Undefined().getBody());
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, Undefined)
{
    using ostk::io::ip::tcp::http::Request;

    {
        EXPECT_NO_THROW(Request::Undefined());
        EXPECT_FALSE(Request::Undefined().isDefined());
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, Get)
{
    using ostk::io::ip::tcp::http::Request;
    using ostk::io::URL;

    {
        const URL url = URL::Parse("https://www.google.com");

        EXPECT_EQ(Request::Method::Get, Request::Get(url).getMethod());
    }

    {
        const URL url = URL::Parse("http://this-address-does-not-exist.com");

        EXPECT_EQ(Request::Method::Get, Request::Get(url).getMethod());
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Request, StringFromMethod)
{
    using ostk::io::ip::tcp::http::Request;

    {
        EXPECT_EQ("Undefined", Request::StringFromMethod(Request::Method::Undefined));
        EXPECT_EQ("Get", Request::StringFromMethod(Request::Method::Get));
        EXPECT_EQ("Head", Request::StringFromMethod(Request::Method::Head));
        EXPECT_EQ("Post", Request::StringFromMethod(Request::Method::Post));
        EXPECT_EQ("Put", Request::StringFromMethod(Request::Method::Put));
        EXPECT_EQ("Delete", Request::StringFromMethod(Request::Method::Delete));
        EXPECT_EQ("Trace", Request::StringFromMethod(Request::Method::Trace));
        EXPECT_EQ("Options", Request::StringFromMethod(Request::Method::Options));
        EXPECT_EQ("Connect", Request::StringFromMethod(Request::Method::Connect));
        EXPECT_EQ("Patch", Request::StringFromMethod(Request::Method::Patch));
    }
}
