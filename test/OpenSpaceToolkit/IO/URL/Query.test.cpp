/// Apache License 2.0

#include <OpenSpaceToolkit/Core/Type/Index.hpp>

#include <OpenSpaceToolkit/IO/URL/Query.hpp>

#include <Global.test.hpp>

TEST(OpenSpaceToolkit_IO_URL_Query, Constructor)
{
    using ostk::io::url::Query;

    {
        EXPECT_NO_THROW(Query query({{"key A", "value 1"}, {"key B", "value 2"}}););
    }
}

TEST(OpenSpaceToolkit_IO_URL_Query_Parameter, Constructor)
{
    using ostk::io::url::Query;

    {
        EXPECT_NO_THROW(Query::Parameter("key", "value"));
    }

    {
        EXPECT_ANY_THROW(Query::Parameter("", "value"));
        EXPECT_ANY_THROW(Query::Parameter("key", ""));
        EXPECT_ANY_THROW(Query::Parameter("", ""));
    }
}

TEST(OpenSpaceToolkit_IO_URL_Query, EqualToOperator)
{
    using ostk::io::url::Query;

    {
        const Query query = {{{"key", "value"}}};

        EXPECT_TRUE(query == query);
    }

    {
        const Query firstQuery = {{{"key A", "value 1"}, {"key B", "value 2"}}};
        const Query secondQuery = {{{"key A", "value 1"}, {"key B", "value 2"}}};

        EXPECT_TRUE(firstQuery == secondQuery);
    }

    {
        const Query firstQuery = {{{"key A", "value 1"}, {"key B", "value 2"}}};
        const Query secondQuery = {{{"key A", "value 1"}, {"key B", "value 3"}}};

        EXPECT_FALSE(firstQuery == secondQuery);
    }

    {
        const Query firstQuery = {{{"key A", "value 1"}, {"key B", "value 2"}}};
        const Query secondQuery = {{{"key A", "value 1"}, {"key C", "value 2"}}};

        EXPECT_FALSE(firstQuery == secondQuery);
    }

    {
        const Query query = {{{"key", "value"}}};

        EXPECT_FALSE(Query::Parse("") == query);
        EXPECT_FALSE(query == Query::Parse(""));

        EXPECT_TRUE(Query::Parse("") == Query::Parse(""));
    }
}

TEST(OpenSpaceToolkit_IO_URL_Query, NotEqualToOperator)
{
    using ostk::io::url::Query;

    {
        const Query query = {{{"key", "value"}}};

        EXPECT_FALSE(query != query);
    }

    {
        const Query firstQuery = {{{"key A", "value 1"}, {"key B", "value 2"}}};
        const Query secondQuery = {{{"key A", "value 1"}, {"key B", "value 2"}}};

        EXPECT_FALSE(firstQuery != secondQuery);
    }

    {
        const Query firstQuery = {{{"key A", "value 1"}, {"key B", "value 2"}}};
        const Query secondQuery = {{{"key A", "value 1"}, {"key B", "value 3"}}};

        EXPECT_TRUE(firstQuery != secondQuery);
    }

    {
        const Query firstQuery = {{{"key A", "value 1"}, {"key B", "value 2"}}};
        const Query secondQuery = {{{"key A", "value 1"}, {"key C", "value 2"}}};

        EXPECT_TRUE(firstQuery != secondQuery);
    }

    {
        const Query query = {{{"key", "value"}}};

        EXPECT_TRUE(Query::Parse("") != query);
        EXPECT_TRUE(query != Query::Parse(""));

        EXPECT_FALSE(Query::Parse("") != Query::Parse(""));
    }
}

TEST(OpenSpaceToolkit_IO_URL_Query, HasParameterWithName)
{
    using ostk::io::url::Query;

    {
        const Query query = {{{"key", "value"}}};

        EXPECT_TRUE(query.hasParameterWithName("key"));
        EXPECT_FALSE(query.hasParameterWithName("other_key"));
    }

    {
        EXPECT_FALSE(Query::Parse("").hasParameterWithName("key"));
    }

    {
        EXPECT_ANY_THROW(Query::Parse("").hasParameterWithName(""));
    }
}

TEST(OpenSpaceToolkit_IO_URL_Query, GetParameterWithName)
{
    using ostk::io::url::Query;

    {
        const Query query = {{{"key", "value"}}};

        EXPECT_EQ("value", query.getParameterWithName("key"));

        EXPECT_ANY_THROW(query.getParameterWithName("other_key"));
    }

    {
        const Query query = {{{"key", "value"}}};

        EXPECT_ANY_THROW(query.getParameterWithName(""));
        EXPECT_ANY_THROW(Query::Parse("").getParameterWithName("key"));
    }
}

TEST(OpenSpaceToolkit_IO_URL_Query, ToString)
{
    using ostk::io::url::Query;

    {
        const Query query = {{{"key", "value"}}};

        EXPECT_EQ("key=value", query.toString());
    }

    {
        const Query query = {{{"key_A", "value_1"}, {"key_B", "value_2"}}};

        EXPECT_EQ("key_A=value_1&key_B=value_2", query.toString());
    }

    {
        EXPECT_EQ("", Query::Parse("").toString());
    }
}

TEST(OpenSpaceToolkit_IO_URL_Query, ConstIterator)
{
    using ostk::core::type::Index;

    using ostk::io::url::Query;

    {
        const Query query = {{{"key_A", "value_1"}, {"key_B", "value_2"}}};

        Index index = 0;

        for (const auto& parameter : query)
        {
            EXPECT_TRUE(parameter == parameter);
            EXPECT_FALSE(parameter != parameter);

            EXPECT_EQ("key", parameter.accessName().getHead(3));
            EXPECT_EQ("value", parameter.accessValue().getHead(5));

            EXPECT_EQ("key", parameter.getName().getHead(3));
            EXPECT_EQ("value", parameter.getValue().getHead(5));

            index++;
        }

        EXPECT_EQ(2, index);
    }
}

TEST(OpenSpaceToolkit_IO_URL_Query, AddParameter)
{
    using ostk::io::url::Query;

    {
        Query query = {{{"key_A", "value_1"}}};

        query.addParameter({"key_B", "value_2"});

        EXPECT_EQ("value_2", query.getParameterWithName("key_B"));

    }
}

TEST(OpenSpaceToolkit_IO_URL_Query, Parse)
{
    using ostk::io::url::Query;

    {
        EXPECT_NO_THROW(Query::Parse(""));
        EXPECT_EQ(Query::Parse(""), Query(ostk::core::container::Array<Query::Parameter>::Empty()));
    }

    {
        // [TBI]

        EXPECT_ANY_THROW(Query::Parse("key=value"));
    }
}
