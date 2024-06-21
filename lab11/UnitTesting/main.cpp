#include <gtest/gtest.h>
#include "../AVL tree/tree.cpp"

class TreeTests : public ::testing::Test {
protected:
    Node* root;

    void SetUp() override {
        root = nullptr;
    }
};

TEST_F(TreeTests, TestInsertAndSearch) {
    // Вставка елементів
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 5);

    // Перевірка вставки
    EXPECT_NE(search(root, 10), nullptr);
    EXPECT_NE(search(root, 20), nullptr);
    EXPECT_NE(search(root, 30), nullptr);
    EXPECT_NE(search(root, 15), nullptr);
    EXPECT_NE(search(root, 5), nullptr);

    // Видалення елемента
    root = deleteNode(root, 20);

    // Перевірка видалення
    EXPECT_EQ(search(root, 20), nullptr);
}

TEST_F(TreeTests, TestBalanceAfterInsertion) {
    // Вставка елементів
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 25);

    // Перевірка балансування
    EXPECT_EQ(height(root), 3);
    EXPECT_EQ(getBalance(root), -1);
}

TEST_F(TreeTests, TestInsertDeleteAndSearch) {
    // Вставка елементів
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    // Перевірка вставки
    EXPECT_NE(search(root, 5), nullptr);
    EXPECT_NE(search(root, 3), nullptr);
    EXPECT_NE(search(root, 8), nullptr);
    EXPECT_NE(search(root, 2), nullptr);
    EXPECT_NE(search(root, 4), nullptr);
    EXPECT_NE(search(root, 7), nullptr);
    EXPECT_NE(search(root, 9), nullptr);

    // Видалення елементів
    root = deleteNode(root, 3);
    root = deleteNode(root, 8);

    // Перевірка видалення
    EXPECT_EQ(search(root, 3), nullptr);
    EXPECT_EQ(search(root, 8), nullptr);
}

TEST_F(TreeTests, TestBalanceAfterMultipleInsertions) {
    // Вставка елементів
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);

    // Перевірка балансування
    EXPECT_EQ(height(root), 3);
    EXPECT_EQ(getBalance(root), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
