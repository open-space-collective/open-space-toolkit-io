////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/URL.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/URL.hpp>
#include <iostream>

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

bool                            URL::isDefined                              ( ) const
{
    return (!scheme_.isEmpty()) && (!host_.isEmpty()) ;
}

URL                             URL::Undefined                              ( )
{
    return URL(String::Empty(), String::Empty(), String::Empty(), Integer::Undefined(), String::Empty(), String::Empty(), Query::Undefined(), String::Empty()) ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////