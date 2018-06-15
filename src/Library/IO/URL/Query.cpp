////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/URL/Query.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/URL/Query.hpp>

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

Query                           Query::Undefined                            ( )
{
    return Query(Array<Query::Parameter>::Empty()) ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////