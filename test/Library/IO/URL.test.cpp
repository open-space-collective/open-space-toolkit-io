////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/URL.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/URL.hpp>

#include <Global.test.hpp>

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
        const Query query = { { { "key", "value" } } } ;
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
        const Query query = { { { "key", "value" } } } ;
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
        const Query query = { { { "key", "value" } } } ;
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
        const Query query = { { { "key", "value" } } } ;
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
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        EXPECT_TRUE(URL(scheme, host, path, port, user, password, query, fragment) != URL(scheme, host, path, 442, user, password, query, fragment)) ;

    }

    {

        EXPECT_TRUE(URL::Undefined() != URL::Undefined()) ;

    }
    
}

TEST (Library_IO_URL, AdditionOperator)
{

    using library::io::URL ;

    {

        const URL url = URL::Parse("https://domain.com") + "/path/to/file" ;

        EXPECT_EQ("https://domain.com/path/to/file", url.toString()) ;

    }

    {

        EXPECT_ANY_THROW(URL::Undefined() + "/path/to/file") ;

    }

}

TEST (Library_IO_URL, AdditionAssignmentOperator)
{

    using library::io::URL ;

    {

        URL url = URL::Parse("https://domain.com") ;

        url += "/path/to/file" ;

        EXPECT_EQ("https://domain.com/path/to/file", url.toString()) ;

    }

    {

        EXPECT_ANY_THROW(URL::Undefined() += "/path/to/file") ;

    }

}

TEST (Library_IO_URL, StreamOperator)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << url << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

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
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        EXPECT_TRUE(URL(scheme, host, path, port, user, password, query, fragment).isDefined()) ;

    }

    {

        EXPECT_FALSE(URL::Undefined().isDefined()) ;

    }

}

TEST (Library_IO_URL, AccessScheme)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(scheme, url.accessScheme()) ;

    }

}

TEST (Library_IO_URL, AccessHost)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(host, url.accessHost()) ;

    }

}

TEST (Library_IO_URL, AccessPath)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(path, url.accessPath()) ;

    }

}

TEST (Library_IO_URL, AccessPort)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(port, url.accessPort()) ;

    }

}

TEST (Library_IO_URL, AccessUser)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(user, url.accessUser()) ;

    }

}

TEST (Library_IO_URL, AccessPassword)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(password, url.accessPassword()) ;

    }

}

TEST (Library_IO_URL, AccessQuery)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(query, url.accessQuery()) ;

    }

}

TEST (Library_IO_URL, AccessFragment)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(fragment, url.accessFragment()) ;

    }

}

TEST (Library_IO_URL, GetScheme)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(scheme, url.getScheme()) ;

    }

}

TEST (Library_IO_URL, GetHost)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(host, url.getHost()) ;

    }

}

TEST (Library_IO_URL, GetPath)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(path, url.getPath()) ;

    }

}

TEST (Library_IO_URL, GetPort)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(port, url.getPort()) ;

    }

}

TEST (Library_IO_URL, GetUser)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(user, url.getUser()) ;

    }

}

TEST (Library_IO_URL, GetPassword)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(password, url.getPassword()) ;

    }

}

TEST (Library_IO_URL, GetQuery)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(query, url.getQuery()) ;

    }

}

TEST (Library_IO_URL, GetFragment)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(fragment, url.getFragment()) ;

    }

}

TEST (Library_IO_URL, ToString)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key_A", "value_1" }, { "key_B", "value_2" } } } ;
        const String fragment = "fragment" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ("https://user:password@domain.org:443/path/to/page?key_A=value_1&key_B=value_2#fragment", url.toString()) << url.toString() ;

    }

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key_A", "value 1" }, { "key_B", "value 2" } } } ;
        const String fragment = "fragment A" ;

        const URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ("https://user:password@domain.org:443/path/to/page?key_A=value%201&key_B=value%202#fragment%20A", url.toString(true)) << url.toString(true) ;

    }

    {

        EXPECT_ANY_THROW(URL::Undefined().toString()) ;

    }

}

TEST (Library_IO_URL, SetScheme)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(scheme, url.getScheme()) ;

        const String otherScheme = "http" ;

        url.setScheme(otherScheme) ;

        EXPECT_EQ(otherScheme, url.getScheme()) ;

    }

}

TEST (Library_IO_URL, SetHost)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(host, url.getHost()) ;

        const String otherHost = "other-domain.org" ;

        url.setHost(otherHost) ;

        EXPECT_EQ(otherHost, url.getHost()) ;

    }

}

TEST (Library_IO_URL, SetPath)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(path, url.getPath()) ;

        const String otherPath = "/path/to/other/page" ;

        url.setPath(otherPath) ;

        EXPECT_EQ(otherPath, url.getPath()) ;

    }

}

TEST (Library_IO_URL, SetPort)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(port, url.getPort()) ;

        const Integer otherPort = 80 ;

        url.setPort(otherPort) ;

        EXPECT_EQ(otherPort, url.getPort()) ;

    }

}

TEST (Library_IO_URL, SetUser)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(user, url.getUser()) ;

        const String otherUser = "other-user" ;

        url.setUser(otherUser) ;

        EXPECT_EQ(otherUser, url.getUser()) ;

    }

}

TEST (Library_IO_URL, SetPassword)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(password, url.getPassword()) ;

        const String otherPassword = "other-password" ;

        url.setPassword(otherPassword) ;

        EXPECT_EQ(otherPassword, url.getPassword()) ;

    }

}

TEST (Library_IO_URL, SetQuery)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(query, url.getQuery()) ;

        const Query otherQuery = { { { "key", "other_value" } } } ;

        url.setQuery(otherQuery) ;

        EXPECT_EQ(otherQuery, url.getQuery()) ;

    }

}

TEST (Library_IO_URL, SetFragment)
{

    using library::core::types::Integer ;
    using library::core::types::String ;
    using library::io::URL ;
    using library::io::url::Query ;

    {

        const String scheme = "https" ;
        const String host = "domain.org" ;
        const String path = "/path/to/page" ;
        const Integer port = 443 ;
        const String user = "user" ;
        const String password = "password" ;
        const Query query = { { { "key", "value" } } } ;
        const String fragment = "fragment" ;

        URL url = { scheme, host, path, port, user, password, query, fragment } ;

        EXPECT_EQ(fragment, url.getFragment()) ;

        const String otherFragment = "other-fragment" ;

        url.setFragment(otherFragment) ;

        EXPECT_EQ(otherFragment, url.getFragment()) ;

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

TEST (Library_IO_URL, Parse)
{

    using library::core::types::String ;
    using library::core::ctnr::Array ;
    
    using library::io::URL ;

    {

        const Array<String> urlStrings =
        {
            "http://localhost",
            "https://domain.com",
            "https://domain.com/",
            "https://user@domain.com/",
            "https://user:password@domain.com/",
            "http://localhost:80",
            "https://domain.com:443",
            "https://domain.com:443/",
            "https://user:password@domain.com:443",
            "https://user:password@domain.com:443/",
            "https://domain.com/path",
            "https://domain.com/path/",
            "https://domain.com/path//",
            "https://domain.com/path///",
            "https://domain.com/path///directory",
            "https://domain.com/path/directory",
            "https://domain.com/path/directory/",
            "https://domain.com/path/file.txt",
            "https://domain.com#fragment",
            "https://domain.com/#fragment",
            "https://domain.com/path/file.txt#fragment",
            // "https://domain.com?key=value",
            // "https://domain.com/path/file.txt?key=value",
            // "https://domain.com/path/file.txt?key=value&other_key=value",
            // "https://domain.com/path/file.txt?key=value#fragment",
        } ;

        for (const auto& urlString : urlStrings)
        {

            const URL url = URL::Parse(urlString) ;

            EXPECT_EQ(urlString, url.toString()) << String::Format("{} - {}", urlString, url.toString()) ;

        }

    }

    {

        const Array<String> urlStrings =
        {
            "",
            "https",
            "://",
            "https://",
            "domain.com",
            "://domain.com"
        } ;

        for (const auto& urlString : urlStrings)
        {

            EXPECT_ANY_THROW(URL::Parse(urlString)) << urlString ;

        }

    }

}

// TEST (Library_IO_URL, EncodeString)
// {

// }

// TEST (Library_IO_URL, DecodeString)
// {

// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////