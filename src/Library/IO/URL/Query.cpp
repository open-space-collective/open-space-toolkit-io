////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/URL/Query.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/URL/Query.hpp>

#include <Library/Core/Error.hpp>
#include <Library/Core/Utilities.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace io
{
namespace url
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Query::Parameter::Parameter                 (   const   Query::Parameter::Name&     aName,
                                                                                const   Query::Parameter::Value&    aValue                                      )
                                :   name_(aName),
                                    value_(aValue)
{
    
}

bool                            Query::Parameter::operator ==               (   const   Query::Parameter&           aParameter                                  ) const
{
    return (name_ == aParameter.name_) && (value_ == aParameter.value_) ;
}

bool                            Query::Parameter::operator !=               (   const   Query::Parameter&           aParameter                                  ) const
{
    return (name_ != aParameter.name_) || (value_ != aParameter.value_) ;
}

bool                            Query::Parameter::isDefined                 ( ) const
{
    return (!name_.isEmpty()) && (!value_.isEmpty()) ;
}

const Query::Parameter::Name&   Query::Parameter::accessName                ( ) const
{
    return name_ ;
}

const Query::Parameter::Value&  Query::Parameter::accessValue               ( ) const
{
    return value_ ;
}

Query::Parameter::Name          Query::Parameter::getName                   ( ) const
{
    return name_ ;
}

Query::Parameter::Value         Query::Parameter::getValue                  ( ) const
{
    return value_ ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Query::Query                                (   const   Array<Query::Parameter>&    aParameterArray                             )
                                :   parameters_(aParameterArray)
{

}

bool                            Query::operator ==                          (   const   Query&                      aQuery                                      ) const
{
    return parameters_ == aQuery.parameters_ ;
}

bool                            Query::operator !=                          (   const   Query&                      aQuery                                      ) const
{
    return parameters_ != aQuery.parameters_ ;
}

bool                            Query::isDefined                            ( ) const
{
    return !parameters_.isEmpty() ;
}

bool                            Query::hasParameterWithName                 (   const   Query::Parameter::Name&     aName                                       ) const
{

    for (const auto& parameter : parameters_)
    {

        if (parameter.accessName() == aName)
        {
            return true ;
        }

    }

    return false ;

}

String                          Query::getParameterWithName                 (   const   Query::Parameter::Name&     aName                                       ) const
{

    for (const auto& parameter : parameters_)
    {

        if (parameter.accessName() == aName)
        {
            return parameter.accessValue() ;
        }

    }

    throw library::core::error::RuntimeError("No parameter with name [{}].", aName) ;

    return String::Empty() ;

}

String                          Query::toString                             ( ) const
{

    String queryString = String::Empty() ;

    for (const auto& parameter : parameters_)
    {

        if (!queryString.isEmpty())
        {
            queryString += "&" ;
        }
        
        queryString += String::Format("{}={}", parameter.accessName(), parameter.accessValue()) ;

    }

    return queryString ;

}

Query::ConstIterator            Query::begin                                ( ) const
{
    return parameters_.begin() ;
}

Query::ConstIterator            Query::end                                  ( ) const
{
    return parameters_.end() ;
}

void                            Query::addParameter                         (   const   Query::Parameter&           aParameter                                  )
{

    if (!aParameter.isDefined())
    {
        throw library::core::error::runtime::Undefined("Parameter") ;
    }
    
    parameters_.add(aParameter) ;

}

Query                           Query::Undefined                            ( )
{
    return { Array<Query::Parameter>::Empty() } ;
}

Query                           Query::Parse                                (   const   String&                     aString                                     )
{

    if (aString.isEmpty())
    {
        return Query::Undefined() ;
    }

    throw library::core::error::runtime::ToBeImplemented("Query :: Parse") ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////