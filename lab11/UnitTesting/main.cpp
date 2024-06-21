#include <gtest/gtest.h>
#include "../AVL tree/tree.cpp"

class AVLTreeTest : public ::testing::Test {
protected:
    Node* root;
    AVLTreeTest() : root(nullptr) {}

    void SetUp() override {
        // Initialize AVL Tree for testing
        root = nullptr;
    }

};

TEST_F(AVLTreeTest, InsertNodes)
{
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    ASSERT_NE(root, nullptr);
    ASSERT_EQ(root->data, 30);
    ASSERT_EQ(root->left->data, 20);
    ASSERT_EQ(root->right->data, 40);
}

TEST_F(AVLTreeTest, DeleteNode)
{
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    root = deleteNode(root, 10);
    root = deleteNode(root, 20);

    ASSERT_NE(root, nullptr);
    ASSERT_EQ(root->data, 30);
    ASSERT_EQ(root->left->data, 25);
    ASSERT_EQ(root->right->data, 40);
}

TEST_F(AVLTreeTest, SearchNode)
{
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    Node* result = search(root, 30);
    ASSERT_NE(result, nullptr);
    ASSERT_EQ(result->data, 30);

    result = search(root, 15);
    ASSERT_EQ(result, nullptr);
}

TEST_F(AVLTreeTest, GetHeight)
{
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    ASSERT_EQ(height(root), 2);

    root = insert(root, 40);
    ASSERT_EQ(height(root), 3);
}

TEST_F(AVLTreeTest, GetBalance)
{
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    ASSERT_EQ(getBalance(root), -1);

    root = insert(root, 40);
    ASSERT_EQ(getBalance(root), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
