#include "storage/file/block.hpp"
#include <gtest/gtest.h>

namespace lunadb::storage
{

TEST(BlockTest, ConstructorAndGetters)
{
    Block b("test.db", 42);
    EXPECT_EQ(b.filename(), "test.db");
    EXPECT_EQ(b.number(), 42);
}

TEST(BlockTest, CopySemantics)
{
    Block b1("data.db", 1);
    Block b2 = b1; // Copy constructor

    EXPECT_EQ(b2.filename(), "data.db");
    EXPECT_EQ(b2.number(), 1);

    Block b3("other.db", 99);
    b3 = b1; // Assignment operator

    EXPECT_EQ(b3.filename(), "data.db");
    EXPECT_EQ(b3.number(), 1);
}

TEST(BlockTest, ToString)
{
    Block b("my_db", 123);
    EXPECT_EQ(b.to_string(), "my_db:123");
}

} // namespace lunadb::storage
