/// Apache License 2.0

#ifndef __OpenSpaceToolkit_IO_URL__
#define __OpenSpaceToolkit_IO_URL__

#include <OpenSpaceToolkit/Core/Type/Integer.hpp>
#include <OpenSpaceToolkit/Core/Type/String.hpp>

#include <OpenSpaceToolkit/IO/URL/Query.hpp>

namespace ostk
{
namespace io
{

using Integer = ostk::core::type::Integer;
using String = ostk::core::type::String;
using Query = ostk::io::url::Query;

/// @brief                      Uniform Resource Locator (URL)
///
/// @ref                        https://en.wikipedia.org/wiki/URL

class URL
{
   public:
    /// @brief              Default constructor (disabled)

    URL() = delete;

    /// @brief              Constructor
    ///
    /// @code
    ///                     URL url("http", "server.org", "/path/to/page.html", 80) ;
    /// @endcode
    ///
    /// @param              [in] aScheme A scheme
    /// @param              [in] aHost A host
    /// @param              [in] aPath A path
    /// @param              [in] aPort A port
    /// @param              [in] aUser A user
    /// @param              [in] aPassword A password
    /// @param              [in] aQuery A query
    /// @param              [in] aFragment A fragment

    URL(const String& aScheme,
        const String& aHost,
        const String& aPath = String::Empty(),
        const Integer& aPort = Integer::Undefined(),
        const String& aUser = String::Empty(),
        const String& aPassword = String::Empty(),
        const Query& aQuery = Query::Undefined(),
        const String& aFragment = String::Empty());

    /// @brief              Equal to operator
    ///
    /// @code
    ///                     URL("http", "server.org") == URL("http", "server.org") ; // True
    /// @endcode
    ///
    /// @param              [in] aURL A URL
    /// @return             True if URLs are equal

    bool operator==(const URL& aURL) const;

    /// @brief              Not equal to operator
    ///
    /// @code
    ///                     URL("http", "server.org") != URL("http", "server.com") ; // True
    /// @endcode
    ///
    /// @param              [in] aURL A URL
    /// @return             True if URLs are not equal

    bool operator!=(const URL& aURL) const;

    /// @brief              Addition operator
    ///
    ///                     Append element to URL path
    ///
    /// @code
    ///                     URL url("http", "server.org") ; // http://server.org
    ///                     URL newUrl = url + "/page.html" // http://server.org/page.html
    /// @endcode
    ///
    /// @param              [in] aUrlElement A path element
    /// @return             URL

    URL operator+(const String& aUrlElement) const;

    /// @brief              Addition assignment operator
    ///
    ///                     Append element to URL path
    ///
    /// @code
    ///                     URL url("http", "server.org") ; // http://server.org
    ///                     url += "/page.html" // http://server.org/page.html
    /// @endcode
    ///
    /// @param              [in] aUrlElement A path element
    /// @return             Reference to URL

    URL& operator+=(const String& aUrlElement);

    /// @brief              Output stream operator
    ///
    /// @code
    ///                     URL url("http", "server.org") ;
    ///                     std::cout << url ;
    /// @endcode
    ///
    /// @param              [in] anOutputStream An output stream
    /// @param              [in] aURL A URL
    /// @return             An output stream

    friend std::ostream& operator<<(std::ostream& anOutputStream, const URL& aURL);

    /// @brief              Check if URL is defined
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org") ;
    ///                     url.isDefined() ; // True
    /// @endcode
    ///
    /// @return             True if URL is defined

    bool isDefined() const;

    /// @brief              Get reference to URL scheme
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org") ;
    ///                     url.accessScheme() ; // &"http"
    /// @endcode
    ///
    /// @return             Reference to URL scheme

    const String& accessScheme() const;

    /// @brief              Get reference to URL host
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org") ;
    ///                     url.accessHost() ; // &"server.org"
    /// @endcode
    ///
    /// @return             Reference to URL host

    const String& accessHost() const;

    /// @brief              Get reference to URL path
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org/path/to/index.html") ;
    ///                     url.accessPath() ; // &"/path/to/index.html"
    /// @endcode
    ///
    /// @return             Reference to URL path

    const String& accessPath() const;

    /// @brief              Get reference to URL port
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org:80") ;
    ///                     url.accessPort() ; // &80
    /// @endcode
    ///
    /// @return             Reference to URL port

    const Integer& accessPort() const;

    /// @brief              Get reference to URL user
    ///
    /// @code
    ///                     URL url = URL::Parse("http://user:password@server.org") ;
    ///                     url.accessUser() ; // &"user"
    /// @endcode
    ///
    /// @return             Reference to URL user

    const String& accessUser() const;

    /// @brief              Get reference to URL password
    ///
    /// @code
    ///                     URL url = URL::Parse("http://user:password@server.org") ;
    ///                     url.accessPassword() ; // &"password"
    /// @endcode
    ///
    /// @return             Reference to URL password

    const String& accessPassword() const;

    /// @brief              Get reference to URL query
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org?key=value") ;
    ///                     url.accessQuery() ; // &"key=value"
    /// @endcode
    ///
    /// @return             Reference to URL query

    const Query& accessQuery() const;

    /// @brief              Get reference to URL fragment
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org#fragment") ;
    ///                     url.accessFragment() ; // &"fragment"
    /// @endcode
    ///
    /// @return             Reference to URL fragment

    const String& accessFragment() const;

    /// @brief              Get URL scheme
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org") ;
    ///                     url.getScheme() ; // "http"
    /// @endcode
    ///
    /// @return             URL scheme

    String getScheme() const;

    /// @brief              Get URL host
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org") ;
    ///                     url.getHost() ; // "server.org"
    /// @endcode
    ///
    /// @return             URL host

    String getHost() const;

    /// @brief              Get URL path
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org/path/to/index.html") ;
    ///                     url.getPath() ; // "/path/to/index.html"
    /// @endcode
    ///
    /// @return             URL path

    String getPath() const;

    /// @brief              Get URL port
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org:80") ;
    ///                     url.getPort() ; // 80
    /// @endcode
    ///
    /// @return             URL port

    Integer getPort() const;

    /// @brief              Get URL user
    ///
    /// @code
    ///                     URL url = URL::Parse("http://user:password@server.org") ;
    ///                     url.getUser() ; // "user"
    /// @endcode
    ///
    /// @return             URL user

    String getUser() const;

    /// @brief              Get URL password
    ///
    /// @code
    ///                     URL url = URL::Parse("http://user:password@server.org") ;
    ///                     url.getPassword() ; // "password"
    /// @endcode
    ///
    /// @return             URL password

    String getPassword() const;

    /// @brief              Get URL query
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org?key=value") ;
    ///                     url.getQuery() ; // "key=value"
    /// @endcode
    ///
    /// @return             URL query

    Query getQuery() const;

    /// @brief              Get URL fragment
    ///
    /// @code
    ///                     URL url = URL::Parse("http://server.org#fragment") ;
    ///                     url.getFragment() ; // "fragment"
    /// @endcode
    ///
    /// @return             URL fragment

    String getFragment() const;

    /// @brief              Get serialized URL
    ///
    /// @code
    ///                     URL url("http", "server.org", "/path/to/page.html", 80) ;
    ///                     url.toString() ; // "http://server.org:80/path/to/page.html"
    /// @endcode
    ///
    /// @param              [in] optional doSanitize If true, sanitize URL
    /// @return             Serialized URL

    String toString(const bool doSanitize = false) const;

    /// @brief              Set URL scheme
    ///
    /// @param              [in] aScheme A scheme

    void setScheme(const String& aScheme);

    /// @brief              Set URL host
    ///
    /// @param              [in] aHost A host

    void setHost(const String& aHost);

    /// @brief              Set URL path
    ///
    /// @param              [in] aPath A path

    void setPath(const String& aPath);

    /// @brief              Set URL port
    ///
    /// @param              [in] aPort A port

    void setPort(const Integer& aPort);

    /// @brief              Set URL user
    ///
    /// @param              [in] aUser A user

    void setUser(const String& aUser);

    /// @brief              Set URL password
    ///
    /// @param              [in] aPassword A password

    void setPassword(const String& aPassword);

    /// @brief              Set URL query
    ///
    /// @param              [in] aQuery A query

    void setQuery(const Query& aQuery);

    /// @brief              Set URL fragment
    ///
    /// @param              [in] aFragment A fragment

    void setFragment(const String& aFragment);

    /// @brief              Constructs an undefined URL
    ///
    /// @code
    ///                     URL url = URL::Undefined() ;
    ///                     url.isDefined() ; // False
    /// @endcode
    ///
    /// @return             Undefined URL

    static URL Undefined();

    /// @brief              Constructs a URL from a given string
    ///
    /// @code
    ///                     URL url = URL::Parse("https://www.google.com") ;
    /// @endcode
    ///
    /// @param              [in] aString A string
    /// @return             URL

    static URL Parse(const String& aString);

    /// @brief              Encode string
    ///
    /// @code
    ///                     String encodedString = URL::EncodeString("key=a_b_c") ; // "key%3Da_b_c"
    /// @endcode
    ///
    /// @param              [in] aString A string
    /// @return             URL

    static String EncodeString(const String& aString);

    /// @brief              Decode string
    ///
    /// @code
    ///                     String decodedString = URL::DecodeString("key%3Da_b_c") ; // "key=a_b_c"
    /// @endcode
    ///
    /// @param              [in] aString A string
    /// @return             URL

    static String DecodeString(const String& aString);

   private:
    String scheme_;
    String user_;
    String password_;
    String host_;
    Integer port_;
    String path_;
    Query query_;
    String fragment_;
};

}  // namespace io
}  // namespace ostk

#endif
