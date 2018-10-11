////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/IO
/// @file           Library/IO/URL/Query.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/IO/URL/Query.hpp>

#include <Library/Core/Types/Index.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


TEST (Library_IO_URL_Query, Constructor)
{

    using library::io::url::Query ;

    {

        EXPECT_NO_THROW(Query query({ { "key A", "value 1" }, { "key B", "value 2" } }) ;) ;

    }

}

TEST (Library_IO_URL_Query, EqualToOperator)
{

    using library::io::url::Query ;

    {

        const Query query = { { { "key", "value" } } } ;

        EXPECT_TRUE(query == query) ;

    }

    {

        const Query firstQuery = { { { "key A", "value 1" }, { "key B", "value 2" } } } ;
        const Query secondQuery = { { { "key A", "value 1" }, { "key B", "value 2" } } } ;

        EXPECT_TRUE(firstQuery == secondQuery) ;

    }

    {

        const Query firstQuery = { { { "key A", "value 1" }, { "key B", "value 2" } } } ;
        const Query secondQuery = { { { "key A", "value 1" }, { "key B", "value 3" } } } ;

        EXPECT_FALSE(firstQuery == secondQuery) ;

    }

    {

        const Query firstQuery = { { { "key A", "value 1" }, { "key B", "value 2" } } } ;
        const Query secondQuery = { { { "key A", "value 1" }, { "key C", "value 2" } } } ;

        EXPECT_FALSE(firstQuery == secondQuery) ;

    }

    {

        const Query query = { { { "key", "value" } } } ;

        EXPECT_FALSE(Query::Undefined() == query) ;
        EXPECT_FALSE(query == Query::Undefined()) ;
        
        EXPECT_TRUE(Query::Undefined() == Query::Undefined()) ;

    }

}

TEST (Library_IO_URL_Query, NotEqualToOperator)
{

    using library::io::url::Query ;

    {

        const Query query = { { { "key", "value" } } } ;

        EXPECT_FALSE(query != query) ;

    }

    {

        const Query firstQuery = { { { "key A", "value 1" }, { "key B", "value 2" } } } ;
        const Query secondQuery = { { { "key A", "value 1" }, { "key B", "value 2" } } } ;

        EXPECT_FALSE(firstQuery != secondQuery) ;

    }

    {

        const Query firstQuery = { { { "key A", "value 1" }, { "key B", "value 2" } } } ;
        const Query secondQuery = { { { "key A", "value 1" }, { "key B", "value 3" } } } ;

        EXPECT_TRUE(firstQuery != secondQuery) ;

    }

    {

        const Query firstQuery = { { { "key A", "value 1" }, { "key B", "value 2" } } } ;
        const Query secondQuery = { { { "key A", "value 1" }, { "key C", "value 2" } } } ;

        EXPECT_TRUE(firstQuery != secondQuery) ;

    }

    {

        const Query query = { { { "key", "value" } } } ;

        EXPECT_TRUE(Query::Undefined() != query) ;
        EXPECT_TRUE(query != Query::Undefined()) ;

        EXPECT_FALSE(Query::Undefined() != Query::Undefined()) ;

    }

}

TEST (Library_IO_URL_Query, IsDefined)
{

    using library::io::url::Query ;

    {

        const Query query = { { { "key", "value" } } } ;

        EXPECT_TRUE(query.isDefined()) ;

    }

    {

        EXPECT_FALSE(Query::Undefined().isDefined()) ;

    }

}

TEST (Library_IO_URL_Query, HasParameterWithName)
{

    using library::io::url::Query ;

    {

        const Query query = { { { "key", "value" } } } ;

        EXPECT_TRUE(query.hasParameterWithName("key")) ;
        EXPECT_FALSE(query.hasParameterWithName("other_key")) ;

    }

    {

        EXPECT_FALSE(Query::Undefined().hasParameterWithName("key")) ;

    }

}

TEST (Library_IO_URL_Query, GetParameterWithName)
{

    using library::io::url::Query ;

    {

        const Query query = { { { "key", "value" } } } ;

        EXPECT_EQ("value", query.getParameterWithName("key")) ;
        
        EXPECT_ANY_THROW(query.getParameterWithName("other_key")) ;

    }

    {

        EXPECT_ANY_THROW(Query::Undefined().getParameterWithName("key")) ;

    }

}

TEST (Library_IO_URL_Query, ToString)
{

    using library::io::url::Query ;

    {

        const Query query = { { { "key", "value" } } } ;

        EXPECT_EQ("key=value", query.toString()) ;

    }

    {

        const Query query = { { { "key_A", "value_1" }, { "key_B", "value_2" } } } ;

        EXPECT_EQ("key_A=value_1&key_B=value_2", query.toString()) ;

    }

    {

        EXPECT_EQ("", Query::Undefined().toString()) ;

    }

}

TEST (Library_IO_URL_Query, ConstIterator)
{

    using library::core::types::Index ;

    using library::io::url::Query ;

    {

        const Query query = { { { "key_A", "value_1" }, { "key_B", "value_2" } } } ;

        Index index = 0 ;

        for (const auto& parameter : query)
        {

            EXPECT_TRUE(parameter == parameter) ;
            EXPECT_FALSE(parameter != parameter) ;
            
            EXPECT_TRUE(parameter.isDefined()) ;

            EXPECT_EQ("key", parameter.accessName().getHead(3)) ;
            EXPECT_EQ("value", parameter.accessValue().getHead(5)) ;

            EXPECT_EQ("key", parameter.getName().getHead(3)) ;
            EXPECT_EQ("value", parameter.getValue().getHead(5)) ;

            index++ ;

        }

        EXPECT_EQ(2, index) ;

    }

}

TEST (Library_IO_URL_Query, AddParameter)
{

    using library::io::url::Query ;

    {

        Query query = { { { "key_A", "value_1" } } } ;

        query.addParameter({ "key_B", "value_2" }) ;

        EXPECT_EQ("value_2", query.getParameterWithName("key_B")) ;

    }

}

TEST (Library_IO_URL_Query, Undefined)
{

    using library::io::url::Query ;

    {

        EXPECT_NO_THROW(Query::Undefined()) ;
        EXPECT_FALSE(Query::Undefined().isDefined()) ;

    }

}

TEST (Library_IO_URL_Query, Parse)
{

    using library::io::url::Query ;

    {

        // [TBI]

        EXPECT_ANY_THROW(Query::Parse("key=value")) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////