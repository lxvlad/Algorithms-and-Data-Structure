#include <gtest/gtest.h>
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab3/Table/KeyValueTable.cpp"

// Тест на додавання елементів
TEST(KeyValueTableTest, AddKeyValue)
{
    KeyValueTable<5> kvTable;
    kvTable.AddKeyValue("apple", 1);
    kvTable.AddKeyValue("banana", 2);

    EXPECT_EQ(kvTable.GetSize(), 2);
    EXPECT_EQ(kvTable.GetValue("apple"), 1);
    EXPECT_EQ(kvTable.GetValue("banana"), 2);
}

// Тест на видалення елементів
TEST(KeyValueTableTest, RemoveKey)
{
    KeyValueTable<5> kvTable;
    kvTable.AddKeyValue("apple", 1);
    kvTable.AddKeyValue("banana", 2);
    kvTable.RemoveKey("apple");

    EXPECT_EQ(kvTable.GetSize(), 1);
    EXPECT_EQ(kvTable.GetValue("apple"), -1);
    EXPECT_EQ(kvTable.GetValue("banana"), 2);
}

// Тест на отримання значення за ключем
TEST(KeyValueTableTest, GetValue)
{
    KeyValueTable<5> kvTable;
    kvTable.AddKeyValue("apple", 1);
    kvTable.AddKeyValue("banana", 2);

    EXPECT_EQ(kvTable.GetValue("apple"), 1);
    EXPECT_EQ(kvTable.GetValue("banana"), 2);
    EXPECT_EQ(kvTable.GetValue("cherry"), -1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
