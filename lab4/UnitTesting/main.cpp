#include <gtest/gtest.h>
#include "../HashTable/HashTable.cpp"

// Тест на перевірку, чи порожня хеш-таблиця
TEST(HashTableTest, IsEmptyInitially) {
    HashTable ht;
    EXPECT_TRUE(ht.isEmpty());
}

// Тест на вставку елемента та перевірку наявності ключа
TEST(HashTableTest, InsertItem) {
    HashTable ht;
    ht.push(1, "One");
    EXPECT_FALSE(ht.isEmpty());
    EXPECT_TRUE(ht.hasKey(1));
    EXPECT_EQ(ht.getValue(1), "One");
}

// Тест на заміну значення існуючого ключа
TEST(HashTableTest, ReplaceValue) {
    HashTable ht;
    ht.push(1, "One");
    ht.push(1, "NewOne");
    EXPECT_TRUE(ht.hasKey(1));
    EXPECT_EQ(ht.getValue(1), "NewOne");
}

// Тест на видалення елемента
TEST(HashTableTest, RemoveItem) {
    HashTable ht;
    ht.push(1, "One");
    ht.pop(1);
    EXPECT_FALSE(ht.hasKey(1));
    EXPECT_TRUE(ht.isEmpty());
}

// Тест на спробу видалення неіснуючого елемента
TEST(HashTableTest, RemoveNonExistingItem) {
    HashTable ht;
    ht.push(1, "One");
    ht.pop(2);
    EXPECT_TRUE(ht.hasKey(1));
    EXPECT_EQ(ht.getValue(1), "One");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
