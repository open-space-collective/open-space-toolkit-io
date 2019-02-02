////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/IP/TCP/HTTP/Response.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/IP/TCP/HTTP/Response.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (Library_IO_IP_TCP_HTTP_Response, Constructor)
{

    using library::core::types::String ;
    
    using library::io::ip::tcp::http::Response ;

    {

        const Response::StatusCode statusCode = Response::StatusCode::Ok ;
        const String body = "Hello World!" ;

        EXPECT_NO_THROW(Response response (statusCode, body) ;) ;
        
    }

}

TEST (Library_IO_IP_TCP_HTTP_Response, StreamOperator)
{

    using library::core::types::String ;

    using library::io::ip::tcp::http::Response ;

    {

        const Response::StatusCode statusCode = Response::StatusCode::Ok ;
        const String body = "Hello World!" ;

        const Response response = { statusCode, body } ;

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << response << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;
        
    }

}

TEST (Library_IO_IP_TCP_HTTP_Response, IsDefined)
{

    using library::core::types::String ;
    
    using library::io::ip::tcp::http::Response ;

    {

        const Response::StatusCode statusCode = Response::StatusCode::Ok ;
        const String body = "Hello World!" ;

        const Response response = { statusCode, body } ;

        EXPECT_TRUE(response.isDefined()) ;

    }

    {

        EXPECT_FALSE(Response::Undefined().isDefined()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Response, IsOk)
{

    using library::core::types::String ;
    
    using library::io::ip::tcp::http::Response ;

    {

        const Response::StatusCode statusCode = Response::StatusCode::Ok ;
        const String body = "Hello World!" ;

        const Response response = { statusCode, body } ;

        EXPECT_TRUE(response.isOk()) ;

    }

    {

        const Response::StatusCode statusCode = Response::StatusCode::InternalServerError ;
        const String body = "Hello World!" ;

        const Response response = { statusCode, body } ;

        EXPECT_FALSE(response.isOk()) ;

    }

    {

        EXPECT_ANY_THROW(Response::Undefined().isOk()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Response, GetStatusCode)
{

    using library::core::types::String ;
    
    using library::io::ip::tcp::http::Response ;

    {

        const Response::StatusCode statusCode = Response::StatusCode::Ok ;
        const String body = "Hello World!" ;

        const Response response = { statusCode, body } ;

        EXPECT_EQ(statusCode, response.getStatusCode()) ;
        
    }

    {

        EXPECT_ANY_THROW(Response::Undefined().getStatusCode()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Response, GetBody)
{

    using library::core::types::String ;
    
    using library::io::ip::tcp::http::Response ;

    {

        const Response::StatusCode statusCode = Response::StatusCode::Ok ;
        const String body = "Hello World!" ;

        const Response response = { statusCode, body } ;

        EXPECT_EQ(body, response.getBody()) ;
        
    }

    {

        EXPECT_ANY_THROW(Response::Undefined().getBody()) ;

    }

}

TEST (Library_IO_IP_TCP_HTTP_Response, Undefined)
{

    using library::io::ip::tcp::http::Response ;

    {

        EXPECT_NO_THROW(Response::Undefined()) ;
        EXPECT_FALSE(Response::Undefined().isDefined()) ;
        
    }

}

TEST (Library_IO_IP_TCP_HTTP_Response, StringFromStatusCode)
{

    using library::io::ip::tcp::http::Response ;

    {

        EXPECT_EQ("Undefined", Response::StringFromStatusCode(Response::StatusCode::Undefined)) ;
        EXPECT_EQ("Continue", Response::StringFromStatusCode(Response::StatusCode::Continue)) ;
        EXPECT_EQ("SwitchingProtocols", Response::StringFromStatusCode(Response::StatusCode::SwitchingProtocols)) ;
        EXPECT_EQ("Processing", Response::StringFromStatusCode(Response::StatusCode::Processing)) ;
        EXPECT_EQ("EarlyHints", Response::StringFromStatusCode(Response::StatusCode::EarlyHints)) ;
        EXPECT_EQ("Ok", Response::StringFromStatusCode(Response::StatusCode::Ok)) ;
        EXPECT_EQ("Created", Response::StringFromStatusCode(Response::StatusCode::Created)) ;
        EXPECT_EQ("Accepted", Response::StringFromStatusCode(Response::StatusCode::Accepted)) ;
        EXPECT_EQ("NonAuthoritativeInformation", Response::StringFromStatusCode(Response::StatusCode::NonAuthoritativeInformation)) ;
        EXPECT_EQ("NoContent", Response::StringFromStatusCode(Response::StatusCode::NoContent)) ;
        EXPECT_EQ("ResetContent", Response::StringFromStatusCode(Response::StatusCode::ResetContent)) ;
        EXPECT_EQ("PartialContent", Response::StringFromStatusCode(Response::StatusCode::PartialContent)) ;
        EXPECT_EQ("MultiStatus", Response::StringFromStatusCode(Response::StatusCode::MultiStatus)) ;
        EXPECT_EQ("AlreadyReported", Response::StringFromStatusCode(Response::StatusCode::AlreadyReported)) ;
        EXPECT_EQ("IMUsed", Response::StringFromStatusCode(Response::StatusCode::IMUsed)) ;
        EXPECT_EQ("MultipleChoices", Response::StringFromStatusCode(Response::StatusCode::MultipleChoices)) ;
        EXPECT_EQ("MovedPermanently", Response::StringFromStatusCode(Response::StatusCode::MovedPermanently)) ;
        EXPECT_EQ("Found", Response::StringFromStatusCode(Response::StatusCode::Found)) ;
        EXPECT_EQ("SeeOther", Response::StringFromStatusCode(Response::StatusCode::SeeOther)) ;
        EXPECT_EQ("NotModified", Response::StringFromStatusCode(Response::StatusCode::NotModified)) ;
        EXPECT_EQ("UseProxy", Response::StringFromStatusCode(Response::StatusCode::UseProxy)) ;
        EXPECT_EQ("SwitchProxy", Response::StringFromStatusCode(Response::StatusCode::SwitchProxy)) ;
        EXPECT_EQ("TemporaryRedirect", Response::StringFromStatusCode(Response::StatusCode::TemporaryRedirect)) ;
        EXPECT_EQ("PermanentRedirect", Response::StringFromStatusCode(Response::StatusCode::PermanentRedirect)) ;
        EXPECT_EQ("BadRequest", Response::StringFromStatusCode(Response::StatusCode::BadRequest)) ;
        EXPECT_EQ("Unauthorized", Response::StringFromStatusCode(Response::StatusCode::Unauthorized)) ;
        EXPECT_EQ("PaymentRequired", Response::StringFromStatusCode(Response::StatusCode::PaymentRequired)) ;
        EXPECT_EQ("Forbidden", Response::StringFromStatusCode(Response::StatusCode::Forbidden)) ;
        EXPECT_EQ("NotFound", Response::StringFromStatusCode(Response::StatusCode::NotFound)) ;
        EXPECT_EQ("MethodNotAllowed", Response::StringFromStatusCode(Response::StatusCode::MethodNotAllowed)) ;
        EXPECT_EQ("NotAcceptable", Response::StringFromStatusCode(Response::StatusCode::NotAcceptable)) ;
        EXPECT_EQ("ProxyAuthenticationRequired", Response::StringFromStatusCode(Response::StatusCode::ProxyAuthenticationRequired)) ;
        EXPECT_EQ("RequestTimeout", Response::StringFromStatusCode(Response::StatusCode::RequestTimeout)) ;
        EXPECT_EQ("Conflict", Response::StringFromStatusCode(Response::StatusCode::Conflict)) ;
        EXPECT_EQ("Gone", Response::StringFromStatusCode(Response::StatusCode::Gone)) ;
        EXPECT_EQ("LengthRequired", Response::StringFromStatusCode(Response::StatusCode::LengthRequired)) ;
        EXPECT_EQ("PreconditionFailed", Response::StringFromStatusCode(Response::StatusCode::PreconditionFailed)) ;
        EXPECT_EQ("PayloadTooLarge", Response::StringFromStatusCode(Response::StatusCode::PayloadTooLarge)) ;
        EXPECT_EQ("URITooLong", Response::StringFromStatusCode(Response::StatusCode::URITooLong)) ;
        EXPECT_EQ("UnsupportedMediaType", Response::StringFromStatusCode(Response::StatusCode::UnsupportedMediaType)) ;
        EXPECT_EQ("RangeNotSatisfiable", Response::StringFromStatusCode(Response::StatusCode::RangeNotSatisfiable)) ;
        EXPECT_EQ("ExpectationFailed", Response::StringFromStatusCode(Response::StatusCode::ExpectationFailed)) ;
        EXPECT_EQ("ImATeapot", Response::StringFromStatusCode(Response::StatusCode::ImATeapot)) ;
        EXPECT_EQ("MisdirectedRequest", Response::StringFromStatusCode(Response::StatusCode::MisdirectedRequest)) ;
        EXPECT_EQ("UnprocessableEntity", Response::StringFromStatusCode(Response::StatusCode::UnprocessableEntity)) ;
        EXPECT_EQ("Locked", Response::StringFromStatusCode(Response::StatusCode::Locked)) ;
        EXPECT_EQ("FailedDependency", Response::StringFromStatusCode(Response::StatusCode::FailedDependency)) ;
        EXPECT_EQ("UpgradeRequired", Response::StringFromStatusCode(Response::StatusCode::UpgradeRequired)) ;
        EXPECT_EQ("PreconditionRequired", Response::StringFromStatusCode(Response::StatusCode::PreconditionRequired)) ;
        EXPECT_EQ("TooManyRequests", Response::StringFromStatusCode(Response::StatusCode::TooManyRequests)) ;
        EXPECT_EQ("RequestHeaderFieldsTooLarge", Response::StringFromStatusCode(Response::StatusCode::RequestHeaderFieldsTooLarge)) ;
        EXPECT_EQ("UnavailableForLegalReasons", Response::StringFromStatusCode(Response::StatusCode::UnavailableForLegalReasons)) ;
        EXPECT_EQ("InternalServerError", Response::StringFromStatusCode(Response::StatusCode::InternalServerError)) ;
        EXPECT_EQ("NotImplemented", Response::StringFromStatusCode(Response::StatusCode::NotImplemented)) ;
        EXPECT_EQ("BadGateway", Response::StringFromStatusCode(Response::StatusCode::BadGateway)) ;
        EXPECT_EQ("ServiceUnavailable", Response::StringFromStatusCode(Response::StatusCode::ServiceUnavailable)) ;
        EXPECT_EQ("GatewayTimeout", Response::StringFromStatusCode(Response::StatusCode::GatewayTimeout)) ;
        EXPECT_EQ("HTTPVersionNotSupported", Response::StringFromStatusCode(Response::StatusCode::HTTPVersionNotSupported)) ;
        EXPECT_EQ("VariantAlsoNegotiates", Response::StringFromStatusCode(Response::StatusCode::VariantAlsoNegotiates)) ;
        EXPECT_EQ("InsufficientStorage", Response::StringFromStatusCode(Response::StatusCode::InsufficientStorage)) ;
        EXPECT_EQ("LoopDetected", Response::StringFromStatusCode(Response::StatusCode::LoopDetected)) ;
        EXPECT_EQ("NotExtended", Response::StringFromStatusCode(Response::StatusCode::NotExtended)) ;
        EXPECT_EQ("NetworkAuthenticationRequire", Response::StringFromStatusCode(Response::StatusCode::NetworkAuthenticationRequire)) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////