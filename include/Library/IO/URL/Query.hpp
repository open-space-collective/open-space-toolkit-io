////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/URL/Query.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_IO_URL_Query__
#define __Library_IO_URL_Query__

#include <Library/Core/Containers/Array.hpp>
#include <Library/Core/Types/String.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace io
{
namespace url
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::String ;
using library::core::ctnr::Array ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Uniform Resource Locator (URL) query

class Query
{

    public:

        /// @brief              Uniform Resource Locator (URL) query parameter

        class Parameter
        {

            public:

                typedef String Name ;
                typedef String Value ;

                /// @brief      Constructor
                ///
                /// @code
                ///             Parameter parameter({"Key", "Value"}) ;
                /// @endcode
                ///
                /// @param      [in] aName A name
                /// @param      [in] aValue A value

                                Parameter                                   (   const   Parameter::Name&            aName,
                                                                                const   Parameter::Value&           aValue                                      ) ;

                /// @brief      Equal to operator
                ///
                /// @code
                ///             Parameter({"Key A", "Value A"}) == Parameter({"Key A", "Value A"}) ; // True
                /// @endcode
                ///
                /// @param      [in] aParameter A parameter
                /// @return     True if parameters are equal

                bool            operator ==                                 (   const   Parameter&                  aParameter                                  ) const ;

                /// @brief      Not equal to operator
                ///
                /// @code
                ///             Parameter({"Key A", "Value A"}) != Parameter({"Key B", "Value A"}) ; // True
                /// @endcode
                ///
                /// @param      [in] aParameter A parameter
                /// @return     True if parameters are not equal

                bool            operator !=                                 (   const   Parameter&                  aParameter                                  ) const ;

                /// @brief      Return true is parameter is defined
                ///
                /// @return     True if parameter is defined

                bool            isDefined                                   ( ) const ;

                /// @brief      Access parameter name
                ///
                /// @code
                ///             Parameter parameter({"Key", "Value"}) ;
                ///             parameter.accessName() ; // &"Key"
                /// @endcode
                ///
                /// @return     Reference to parameter name

                const Parameter::Name& accessName                           ( ) const ;

                /// @brief      Access parameter value
                ///
                /// @code
                ///             Parameter parameter({"Key", "Value"}) ;
                ///             parameter.accessValue() ; // &"Value"
                /// @endcode
                ///
                /// @return     Reference to parameter value

                const Parameter::Value& accessValue                         ( ) const ;

                /// @brief      Get parameter name
                ///
                /// @code
                ///             Parameter parameter({"Key", "Value"}) ;
                ///             parameter.getName() ; // "Key"
                /// @endcode
                ///
                /// @return     Parameter name

                Parameter::Name getName                                     ( ) const ;

                /// @brief      Get parameter value
                ///
                /// @code
                ///             Parameter parameter({"Key", "Value"}) ;
                ///             parameter.getValue() ; // "Value"
                /// @endcode
                ///
                /// @return     Parameter value

                Parameter::Value getValue                                   ( ) const ;

            private:

                Parameter::Name name_ ;
                Parameter::Value value_ ;

        } ;

        typedef                 Array<Query::Parameter>::ConstIterator          ConstIterator ;

        /// @brief              Constructor
        ///
        /// @code
        ///                     Query query({{"Key A", "Value A"}, {"Key B", "Value B"}}) ;
        /// @endcode
        ///
        /// @param              [in] aParameterArray A parameter array

                                Query                                       (   const   Array<Query::Parameter>&    aParameterArray                             ) ;

        /// @brief              Equal to operator
        ///
        /// @code
        ///                     Query({{"Key A", "Value A"}, {"Key B", "Value B"}}) == Query({{"Key B", "Value B"}, {"Key A", "Value A"}}) ; // True
        /// @endcode
        ///
        /// @param              [in] aQuery A query
        /// @return             True if queries are equal

        bool                    operator ==                                 (   const   Query&                      aQuery                                      ) const ;

        /// @brief              Not equal to operator
        ///
        /// @code
        ///                     Query({{"Key A", "Value A"}, {"Key B", "Value B"}}) != Query({{"Key A", "Value A"}, {"Key B", "Value C"}}) ; // True
        /// @endcode
        ///
        /// @param              [in] aQuery A query
        /// @return             True if queries are not equal

        bool                    operator !=                                 (   const   Query&                      aQuery                                      ) const ;

        /// @brief              Check if query is defined
        ///
        /// @code
        ///                     Query({{"Key A", "Value A"}, {"Key B", "Value B"}}).isDefined() ; // True
        /// @endcode
        ///
        /// @return             True if query is defined

        bool                    isDefined                                   ( ) const ;

        /// @brief              Check if query has parameter with a given name
        ///
        /// @code
        ///                     Query({{"Key A", "Value A"}}).hasParameterWithName("Key A") ; // True
        /// @endcode
        ///
        /// @param              [in] aName A parameter name
        /// @return             True if query has parameter with a given name

        bool                    hasParameterWithName                        (   const   Query::Parameter::Name&     aName                                       ) const ;

        /// @brief              Get parameter with a given name
        ///
        /// @code
        ///                     Query({{"Key A", "Value A"}}).getParameterWithName("Key A") ; // "Value A"
        /// @endcode
        ///
        /// @param              [in] aName A parameter name
        /// @return             Parameter

        String                  getParameterWithName                        (   const   Query::Parameter::Name&     aName                                       ) const ;

        /// @brief              Get serialized query
        ///
        /// @code
        ///                     Query({{"Key", "Value"}}).toString() ; // "?Key=Value"
        /// @endcode
        ///
        /// @return             Serialized query

        String                  toString                                    ( ) const ;

        /// @brief              Get begin const iterator
        ///
        /// @return             Begin const iterator

        Query::ConstIterator    begin                                       ( ) const ;

        /// @brief              Get end const iterator
        ///
        /// @return             End const iterator

        Query::ConstIterator    end                                         ( ) const ;

        /// @brief              Add parameter to query
        ///
        /// @code
        ///                     Query query({{"Key A", "Value A"}}) ;
        ///                     query.addParameter({"Key B", "Value B"}) ;
        /// @endcode
        ///
        /// @param              [in] aParameter A parameter
        
        void                    addParameter                                (   const   Query::Parameter&           aParameter                                  ) ;

        /// @brief              Constructs an undefined query
        ///
        /// @code
        ///                     Query query = Query::Undefined() ;
        ///                     query.isDefined() ; // False
        /// @endcode
        ///
        /// @return             Undefined query

        static Query            Undefined                                   ( ) ;

        /// @brief              Constructs query from a given string
        ///
        /// @code
        ///                     Query query = Query::Parse("key_A=value_A&key_B=value_B") ;
        /// @endcode
        ///
        /// @param              [in] aString A string
        /// @return             Query

        static Query            Parse                                       (   const   String&                     aString                                     ) ;
        
    private:

        Array<Query::Parameter> parameters_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////