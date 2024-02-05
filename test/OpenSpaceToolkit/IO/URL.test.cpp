/// Apache License 2.0

#include <OpenSpaceToolkit/IO/URL.hpp>

#include <Global.test.hpp>

TEST(OpenSpaceToolkit_IO_URL, Constructor)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";

        EXPECT_NO_THROW(URL(scheme, host));
    }

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        EXPECT_NO_THROW(URL(scheme, host, path, port, user, password, query, fragment));
    }
}

TEST(OpenSpaceToolkit_IO_URL, EqualToOperator)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";

        EXPECT_TRUE(URL(scheme, host) == URL(scheme, host));
    }

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        EXPECT_TRUE(
            URL(scheme, host, path, port, user, password, query, fragment) ==
            URL(scheme, host, path, port, user, password, query, fragment)
        );
    }

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        EXPECT_FALSE(
            URL(scheme, host, path, port, user, password, query, fragment) ==
            URL(scheme, host, path, 442, user, password, query, fragment)
        );
    }

    {
        EXPECT_FALSE(URL::Undefined() == URL::Undefined());
    }
}

TEST(OpenSpaceToolkit_IO_URL, NotEqualToOperator)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";

        EXPECT_FALSE(URL(scheme, host) != URL(scheme, host));
    }

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        EXPECT_FALSE(
            URL(scheme, host, path, port, user, password, query, fragment) !=
            URL(scheme, host, path, port, user, password, query, fragment)
        );
    }

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        EXPECT_TRUE(
            URL(scheme, host, path, port, user, password, query, fragment) !=
            URL(scheme, host, path, 442, user, password, query, fragment)
        );
    }

    {
        EXPECT_TRUE(URL::Undefined() != URL::Undefined());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AdditionOperator)
{
    using ostk::io::URL;

    {
        const URL url = URL::Parse("https://domain.com") + "/path/to/file";

        EXPECT_EQ("https://domain.com/path/to/file", url.toString());
    }

    {
        EXPECT_ANY_THROW(URL::Undefined() + "/path/to/file");
    }
}

TEST(OpenSpaceToolkit_IO_URL, AdditionAssignmentOperator)
{
    using ostk::io::URL;

    {
        URL url = URL::Parse("https://domain.com");

        url += "/path/to/file";

        EXPECT_EQ("https://domain.com/path/to/file", url.toString());
    }

    {
        EXPECT_ANY_THROW(URL::Undefined() += "/path/to/file");
    }
}

TEST(OpenSpaceToolkit_IO_URL, StreamOperator)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        testing::internal::CaptureStdout();

        EXPECT_NO_THROW(std::cout << url << std::endl);

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty());
    }
}

TEST(OpenSpaceToolkit_IO_URL, IsDefined)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";

        EXPECT_TRUE(URL(scheme, host).isDefined());
    }

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        EXPECT_TRUE(URL(scheme, host, path, port, user, password, query, fragment).isDefined());
    }

    {
        EXPECT_FALSE(URL::Undefined().isDefined());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AccessScheme)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(scheme, url.accessScheme());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AccessHost)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(host, url.accessHost());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AccessPath)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(path, url.accessPath());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AccessPort)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(port, url.accessPort());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AccessUser)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(user, url.accessUser());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AccessPassword)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(password, url.accessPassword());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AccessQuery)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(query, url.accessQuery());
    }
}

TEST(OpenSpaceToolkit_IO_URL, AccessFragment)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(fragment, url.accessFragment());
    }
}

TEST(OpenSpaceToolkit_IO_URL, GetScheme)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(scheme, url.getScheme());
    }
}

TEST(OpenSpaceToolkit_IO_URL, GetHost)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(host, url.getHost());
    }
}

TEST(OpenSpaceToolkit_IO_URL, GetPath)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(path, url.getPath());
    }
}

TEST(OpenSpaceToolkit_IO_URL, GetPort)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(port, url.getPort());
    }
}

TEST(OpenSpaceToolkit_IO_URL, GetUser)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(user, url.getUser());
    }
}

TEST(OpenSpaceToolkit_IO_URL, GetPassword)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(password, url.getPassword());
    }
}

TEST(OpenSpaceToolkit_IO_URL, GetQuery)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(query, url.getQuery());
    }
}

TEST(OpenSpaceToolkit_IO_URL, GetFragment)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(fragment, url.getFragment());
    }
}

TEST(OpenSpaceToolkit_IO_URL, ToString)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key_A", "value_1"}, {"key_B", "value_2"}}};
        const String fragment = "fragment";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(
            "https://user:password@domain.org:443/path/to/page?key_A=value_1&key_B=value_2#fragment", url.toString()
        ) << url.toString();
    }

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key_A", "value 1"}, {"key_B", "value 2"}}};
        const String fragment = "fragment A";

        const URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(
            "https://user:password@domain.org:443/path/to/page?key_A=value%201&key_B=value%202#fragment%20A",
            url.toString(true)
        ) << url.toString(true);
    }

    {
        EXPECT_ANY_THROW(URL::Undefined().toString());
    }
}

TEST(OpenSpaceToolkit_IO_URL, SetScheme)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(scheme, url.getScheme());

        const String otherScheme = "http";

        url.setScheme(otherScheme);

        EXPECT_EQ(otherScheme, url.getScheme());
    }
}

TEST(OpenSpaceToolkit_IO_URL, SetHost)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(host, url.getHost());

        const String otherHost = "other-domain.org";

        url.setHost(otherHost);

        EXPECT_EQ(otherHost, url.getHost());
    }
}

TEST(OpenSpaceToolkit_IO_URL, SetPath)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(path, url.getPath());

        const String otherPath = "/path/to/other/page";

        url.setPath(otherPath);

        EXPECT_EQ(otherPath, url.getPath());
    }
}

TEST(OpenSpaceToolkit_IO_URL, SetPort)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(port, url.getPort());

        const Integer otherPort = 80;

        url.setPort(otherPort);

        EXPECT_EQ(otherPort, url.getPort());
    }
}

TEST(OpenSpaceToolkit_IO_URL, SetUser)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(user, url.getUser());

        const String otherUser = "other-user";

        url.setUser(otherUser);

        EXPECT_EQ(otherUser, url.getUser());
    }
}

TEST(OpenSpaceToolkit_IO_URL, SetPassword)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(password, url.getPassword());

        const String otherPassword = "other-password";

        url.setPassword(otherPassword);

        EXPECT_EQ(otherPassword, url.getPassword());
    }
}

TEST(OpenSpaceToolkit_IO_URL, SetQuery)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(query, url.getQuery());

        const Query otherQuery = {{{"key", "other_value"}}};

        url.setQuery(otherQuery);

        EXPECT_EQ(otherQuery, url.getQuery());
    }
}

TEST(OpenSpaceToolkit_IO_URL, SetFragment)
{
    using ostk::core::type::Integer;
    using ostk::core::type::String;
    using ostk::io::URL;
    using ostk::io::url::Query;

    {
        const String scheme = "https";
        const String host = "domain.org";
        const String path = "/path/to/page";
        const Integer port = 443;
        const String user = "user";
        const String password = "password";
        const Query query = {{{"key", "value"}}};
        const String fragment = "fragment";

        URL url = {scheme, host, path, port, user, password, query, fragment};

        EXPECT_EQ(fragment, url.getFragment());

        const String otherFragment = "other-fragment";

        url.setFragment(otherFragment);

        EXPECT_EQ(otherFragment, url.getFragment());
    }
}

TEST(OpenSpaceToolkit_IO_URL, Undefined)
{
    using ostk::io::URL;

    {
        EXPECT_NO_THROW(URL::Undefined());
    }

    {
        EXPECT_FALSE(URL::Undefined().isDefined());
    }
}

TEST(OpenSpaceToolkit_IO_URL, Parse)
{
    using ostk::core::type::String;
    using ostk::core::container::Array;

    using ostk::io::URL;

    {
        const Array<String> urlStrings = {
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
        };

        for (const auto& urlString : urlStrings)
        {
            const URL url = URL::Parse(urlString);

            EXPECT_EQ(urlString, url.toString()) << String::Format("{} - {}", urlString, url.toString());
        }
    }

    {
        const Array<String> urlStrings = {"", "https", "://", "https://", "domain.com", "://domain.com"};

        for (const auto& urlString : urlStrings)
        {
            EXPECT_ANY_THROW(URL::Parse(urlString)) << urlString;
        }
    }
}

// TEST (OpenSpaceToolkit_IO_URL, EncodeString)
// {

// }

// TEST (OpenSpaceToolkit_IO_URL, DecodeString)
// {

// }
