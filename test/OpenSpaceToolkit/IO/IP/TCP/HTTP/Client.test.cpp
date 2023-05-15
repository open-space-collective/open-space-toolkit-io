/// Apache License 2.0

#include <OpenSpaceToolkit/IO/IP/TCP/HTTP/Client.hpp>

#include <Global.test.hpp>

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Client, Send)
{
    using ostk::io::URL;
    using ostk::io::ip::tcp::http::Request;
    using ostk::io::ip::tcp::http::Response;
    using ostk::io::ip::tcp::http::Client;

    {
        const URL url = URL::Parse("https://www.google.com");

        const Response response = Client::Send(Request::Get(url));

        EXPECT_TRUE(response.isOk()) << response;
        EXPECT_FALSE(response.getBody().isEmpty());
    }

    {
        EXPECT_ANY_THROW(Client::Send(Request::Undefined()));
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Client, Get)
{
    using ostk::io::URL;
    using ostk::io::ip::tcp::http::Response;
    using ostk::io::ip::tcp::http::Client;

    {
        const URL url = URL::Parse("http://www.google.com");

        const Response response = Client::Get(url);

        EXPECT_TRUE(response.isOk()) << response;
        EXPECT_FALSE(response.getBody().isEmpty());
    }

    {
        const URL url = URL::Parse("https://www.google.com");

        const Response response = Client::Get(url);

        EXPECT_TRUE(response.isOk()) << response;
        EXPECT_FALSE(response.getBody().isEmpty());
    }

    {
        const URL url = URL::Parse("https://www.google.com/this-page-does-not-exist");

        const Response response = Client::Get(url);

        EXPECT_EQ(Response::StatusCode::NotFound, response.getStatusCode()) << response;
    }

    {
        const URL url = URL::Parse("http://this-address-does-not-exist.com");

        EXPECT_ANY_THROW(Client::Get(url));
    }

    {
        const URL url = URL::Parse("https://this-address-does-not-exist.com");

        EXPECT_ANY_THROW(Client::Get(url));
    }

    {
        EXPECT_ANY_THROW(Client::Get(URL::Undefined()));
    }
}

TEST(OpenSpaceToolkit_IO_IP_TCP_HTTP_Client, Fetch)
{
    using ostk::core::fs::Path;
    using ostk::core::fs::File;
    using ostk::core::fs::Directory;

    using ostk::io::URL;
    using ostk::io::ip::tcp::http::Client;

    {
        const URL url =
            URL::Parse("https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_272x92dp.png");

        const Directory directory = Directory::Path(Path::Parse("/tmp"));

        const File file = Client::Fetch(url, directory);

        EXPECT_TRUE(file.exists());
        EXPECT_EQ("googlelogo_color_272x92dp.png", file.getName());
    }

    {
        const URL url =
            URL::Parse("https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_272x92dp.png");

        const Directory directory = Directory::Path(Path::Parse("/tmp"));

        EXPECT_ANY_THROW(Client::Fetch(url, Directory::Undefined()));
        EXPECT_ANY_THROW(Client::Fetch(URL::Undefined(), directory));
        EXPECT_ANY_THROW(Client::Fetch(URL::Undefined(), Directory::Undefined()));
    }
}

// Disabling as Travis CI does not seem to support FTP anymore
// https://blog.travis-ci.com/2018-07-23-the-tale-of-ftp-at-travis-ci

// TEST (OpenSpaceToolkit_IO_IP_TCP_HTTP_Client, List)
// {

//     using ostk::core::fs::Path ;
//     using ostk::core::fs::File ;
//     using ostk::core::fs::Directory ;

//     using ostk::io::URL ;
//     using ostk::io::ip::tcp::http::Client ;

//     {

//         const URL url = URL::Parse("ftp://naif.jpl.nasa.gov/pub/naif/generic_kernels/") ;

//         File file = File::Path(Path::Parse("/tmp/listing.txt")) ;

//         Client::List(url, file, false) ;

//         EXPECT_TRUE(file.exists()) ;
//         EXPECT_EQ("listing.txt", file.getName()) ;

//         file.remove() ;

//         Client::List(url, file, true) ;

//         EXPECT_TRUE(file.exists()) ;
//         EXPECT_EQ("listing.txt", file.getName()) ;
//         EXPECT_FALSE(file.getContents().isEmpty()) ;

//         file.remove() ;

//     }

//     {

//         const URL url = URL::Parse("ftp://naif.jpl.nasa.gov/pub/naif/generic_kernels/") ;

//         File file = File::Path(Path::Parse("/tmp/listing.txt")) ;

//         EXPECT_ANY_THROW(Client::List(url, File::Undefined())) ;
//         EXPECT_ANY_THROW(Client::List(URL::Undefined(), file)) ;
//         EXPECT_ANY_THROW(Client::List(URL::Undefined(), File::Undefined())) ;

//     }

// }
