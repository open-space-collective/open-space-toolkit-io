////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/URL.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/URL.hpp>

#include <Library/Core/Error.hpp>
#include <Library/Core/Utilities.hpp>

#include <boost/network/uri.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace io
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                URL::URL                                    (   const   String&                     aScheme,
                                                                                const   String&                     aHost,
                                                                                const   String&                     aPath,
                                                                                const   Integer&                    aPort,
                                                                                const   String&                     aUser,
                                                                                const   String&                     aPassword,
                                                                                const   Query&                      aQuery,
                                                                                const   String&                     aFragment                                   )
                                :   scheme_(aScheme),
                                    user_(aUser),
                                    password_(aPassword),
                                    host_(aHost),
                                    port_(aPort),
                                    path_(aPath),
                                    query_(aQuery),
                                    fragment_(aFragment)
{

}

bool                            URL::operator ==                            (   const   URL&                        aURL                                        ) const
{

    if ((!this->isDefined()) || (!aURL.isDefined()))
    {
        return false ;
    }
    
    return (scheme_ == aURL.scheme_) 
        && (user_ == aURL.user_) 
        && (password_ == aURL.password_) 
        && (host_ == aURL.host_) 
        && (((!port_.isDefined()) && (!aURL.port_.isDefined())) ? true : (port_ == aURL.port_))
        && (path_ == aURL.path_) 
        && (query_ == aURL.query_) 
        && (fragment_ == aURL.fragment_) ;

}

bool                            URL::operator !=                            (   const   URL&                        aURL                                        ) const
{

    if ((!this->isDefined()) || (!aURL.isDefined()))
    {
        return true ;
    }

    return (scheme_ != aURL.scheme_) 
        || (user_ != aURL.user_) 
        || (password_ != aURL.password_) 
        || (host_ != aURL.host_) 
        || (port_ != aURL.port_) 
        || (path_ != aURL.path_) 
        || (query_ != aURL.query_) 
        || (fragment_ != aURL.fragment_) ;

}

URL                             URL::operator +                             (   const   String&                     aUrlElement                                 ) const
{
    return URL::Parse(this->toString() + aUrlElement) ;
}

URL&                            URL::operator +=                            (   const   String&                     aUrlElement                                 )
{

    (*this) = (*this) + aUrlElement ;

    return *this ;

}

std::ostream&                   operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   URL&                        aURL                                        )
{

    library::core::utils::Print::Header(anOutputStream, "Object") ;

    library::core::utils::Print::Line(anOutputStream) << "Scheme"               << (!aURL.scheme_.isEmpty() ? aURL.scheme_ : "Undefined") ;
    library::core::utils::Print::Line(anOutputStream) << "User"                 << (!aURL.user_.isEmpty() ? aURL.user_ : "Undefined") ;
    library::core::utils::Print::Line(anOutputStream) << "Password"             << (!aURL.password_.isEmpty() ? aURL.password_ : "Undefined") ;
    library::core::utils::Print::Line(anOutputStream) << "Host"                 << (!aURL.host_.isEmpty() ? aURL.host_ : "Undefined") ;
    library::core::utils::Print::Line(anOutputStream) << "Port"                 << (aURL.port_.isDefined() ? aURL.port_.toString() : "Undefined") ;
    library::core::utils::Print::Line(anOutputStream) << "Path"                 << (aURL.path_.isEmpty() ? aURL.path_ : "Undefined") ;
    library::core::utils::Print::Line(anOutputStream) << "Query"                << (aURL.query_.isDefined() ? aURL.query_.toString() : "Undefined") ;
    library::core::utils::Print::Line(anOutputStream) << "Fragment"             << (aURL.fragment_.isEmpty() ? aURL.fragment_ : "Undefined") ;

    library::core::utils::Print::Footer(anOutputStream) ;

    return anOutputStream ;

}

bool                            URL::isDefined                              ( ) const
{
    return (!scheme_.isEmpty()) && (!host_.isEmpty()) ;
}

const String&                   URL::accessScheme                           ( ) const
{
    return scheme_ ;
}

const String&                   URL::accessHost                             ( ) const
{
    return host_ ;
}

const String&                   URL::accessPath                             ( ) const
{
    return path_ ;
}

const Integer&                  URL::accessPort                             ( ) const
{
    return port_ ;
}

const String&                   URL::accessUser                             ( ) const
{
    return user_ ;
}

const String&                   URL::accessPassword                         ( ) const
{
    return password_ ;
}

const Query&                    URL::accessQuery                            ( ) const
{
    return query_ ;
}

const String&                   URL::accessFragment                         ( ) const
{
    return fragment_ ;
}

String                          URL::getScheme                              ( ) const
{
    return scheme_ ;
}

String                          URL::getHost                                ( ) const
{
    return host_ ;
}

String                          URL::getPath                                ( ) const
{
    return path_ ;
}

Integer                         URL::getPort                                ( ) const
{
    return port_ ;
}

String                          URL::getUser                                ( ) const
{
    return user_ ;
}

String                          URL::getPassword                            ( ) const
{
    return password_ ;
}

Query                           URL::getQuery                               ( ) const
{
    return query_ ;
}

String                          URL::getFragment                            ( ) const
{
    return fragment_ ;
}

String                          URL::toString                               ( ) const
{

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("URL") ;
    }

    String urlString = String::Format("{}://", scheme_) ;

    if ((!user_.isEmpty()) && (!password_.isEmpty()))
    {
        urlString += String::Format("{}:{}@", user_, password_) ;
    }
    else if (!user_.isEmpty())
    {
        urlString += String::Format("{}@", user_) ;
    }

    urlString += host_ ;

    if (port_.isDefined())
    {
        urlString += String::Format(":{}", port_.toString()) ;
    }

    if (!path_.isEmpty())
    {
        urlString += path_ ;
    }

    if (query_.isDefined())
    {
        urlString += String::Format("?{}", query_.toString()) ;
    }

    if (!fragment_.isEmpty())
    {
        urlString += String::Format("#{}", fragment_) ;
    }
    
    return urlString ;

}

void                            URL::setScheme                              (   const   String&                     aScheme                                     )
{
    scheme_ = aScheme ;
}

void                            URL::setHost                                (   const   String&                     aHost                                       )
{
    host_ = aHost ;
}

void                            URL::setPath                                (   const   String&                     aPath                                       )
{
    path_ = aPath ;
}

void                            URL::setPort                                (   const   Integer&                    aPort                                       )
{
    port_ = aPort ;
}

void                            URL::setUser                                (   const   String&                     aUser                                       )
{
    user_ = aUser ;
}

void                            URL::setPassword                            (   const   String&                     aPassword                                   )
{
    password_ = aPassword ;
}

void                            URL::setQuery                               (   const   Query&                      aQuery                                      )
{
    query_ = aQuery ;
}

void                            URL::setFragment                            (   const   String&                     aFragment                                   )
{
    fragment_ = aFragment ;
}

URL                             URL::Undefined                              ( )
{
    return { String::Empty(), String::Empty(), String::Empty(), Integer::Undefined(), String::Empty(), String::Empty(), Query::Undefined(), String::Empty() } ;
}

URL                             URL::Parse                                  (   const   String&                     aString                                     )
{

    if (aString.isEmpty())
    {
        throw library::core::error::runtime::Undefined("URL") ;
    }

    boost::network::uri::uri uri = { aString } ;

    if (!uri.is_valid())
	{
		throw library::core::error::runtime::Wrong(aString) ;
	}

    const String scheme = uri.scheme() ;
    const String user = boost::network::uri::username(uri) ;
    const String password = boost::network::uri::password(uri) ;
    const String host = uri.host() ;
    const Integer port = (!uri.port().empty()) ? Integer::Parse(uri.port()) : Integer::Undefined() ;
    const String path = uri.path() ;
    const Query query = (!uri.query().empty()) ? Query::Parse(uri.query()) : Query::Undefined() ;
    const String fragment = uri.fragment() ;

    if (scheme.isEmpty() || host.isEmpty())
    {
        throw library::core::error::runtime::Wrong(aString) ;
    }

    return { scheme, host, path, port, user, password, query, fragment } ;

}

// String                          URL::EncodeString                           (   const   String&                     aString                                     )
// {

// }

// String                          URL::DecodeString                           (   const   String&                     aString                                     )
// {

// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////