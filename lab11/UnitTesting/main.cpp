#include <gtest/gtest.h>
#include "../AVL tree/tree.cpp"


TEST(AVLTreeTest, InsertAndSearch)
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    EXPECT_TRUE(tree.search(30));
    EXPECT_TRUE(tree.search(20));
    EXPECT_FALSE(tree.search(15));
}

TEST(AVLTreeTest, DeleteNode)
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.deleteNode(30);

    EXPECT_FALSE(tree.search(30));
    EXPECT_TRUE(tree.search(40));
    EXPECT_EQ(tree.search(20), true);
    EXPECT_EQ(tree.search(50), true);
}

TEST(AVLTreeTest, InsertAndDeleteMultipleNodes)
{
    AVLTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.deleteNode(30);
    tree.deleteNode(20);
    tree.deleteNode(80);

    EXPECT_FALSE(tree.search(30));
    EXPECT_FALSE(tree.search(20));
    EXPECT_FALSE(tree.search(80));
    EXPECT_TRUE(tree.search(50));
    EXPECT_TRUE(tree.search(40));
    EXPECT_TRUE(tree.search(70));
    EXPECT_TRUE(tree.search(60));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
