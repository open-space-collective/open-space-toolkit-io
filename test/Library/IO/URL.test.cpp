////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/URL.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Global.test.hpp>

#include <Library/IO/URL.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (Library_IO_URL, Constructor)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;

        EXPECT_NO_THROW(URL(scheme, host)) ;

    }

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = {{{"key", "value"}}} ;
        const String fragment = "fragment" ;

        EXPECT_NO_THROW(URL(scheme, host, path, port, user, password, query, fragment)) ;

    }

}

TEST (Library_IO_URL, EqualToOperator)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;

        EXPECT_TRUE(URL(scheme, host) == URL(scheme, host)) ;

    }

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = {{{"key", "value"}}} ;
        const String fragment = "fragment" ;

        EXPECT_TRUE(URL(scheme, host, path, port, user, password, query, fragment) == URL(scheme, host, path, port, user, password, query, fragment)) ;

    }

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = {{{"key", "value"}}} ;
        const String fragment = "fragment" ;

        EXPECT_FALSE(URL(scheme, host, path, port, user, password, query, fragment) == URL(scheme, host, path, 442, user, password, query, fragment)) ;

    }

    {

        EXPECT_FALSE(URL::Undefined() == URL::Undefined()) ;

    }

}

TEST (Library_IO_URL, NotEqualToOperator)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;

        EXPECT_FALSE(URL(scheme, host) != URL(scheme, host)) ;

    }

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = {{{"key", "value"}}} ;
        const String fragment = "fragment" ;

        EXPECT_FALSE(URL(scheme, host, path, port, user, password, query, fragment) != URL(scheme, host, path, port, user, password, query, fragment)) ;

    }

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = {{{"key", "value"}}} ;
        const String fragment = "fragment" ;

        EXPECT_TRUE(URL(scheme, host, path, port, user, password, query, fragment) != URL(scheme, host, path, 442, user, password, query, fragment)) ;

    }

    {

        EXPECT_TRUE(URL::Undefined() != URL::Undefined()) ;

    }
    
}

TEST (Library_IO_URL, IsDefined)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;

        EXPECT_TRUE(URL(scheme, host).isDefined()) ;

    }

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = {{{"key", "value"}}} ;
        const String fragment = "fragment" ;

        EXPECT_TRUE(URL(scheme, host, path, port, user, password, query, fragment).isDefined()) ;

    }

    {

        EXPECT_FALSE(URL::Undefined().isDefined()) ;

    }

}

TEST (Library_IO_URL, Undefined)
{

    using library::io::URL ;

    {

        EXPECT_NO_THROW(URL::Undefined()) ;

    }

    {

        EXPECT_FALSE(URL::Undefined().isDefined()) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////