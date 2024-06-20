#include <iostream>
#include <gtest/gtest.h>
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab6/SparseMatrix/SparseMatrix.cpp"

TEST(SparseMatrixTest, AddElement)
{
    SparseMatrix<int> matrix(3, 3);
    matrix.AddElement(0, 0, 5);

    EXPECT_EQ(matrix.GetElement(0, 0), 5);
}

TEST(SparseMatrixTest, AddElementOutOfBounds)
{
    SparseMatrix<int> matrix(3, 3);
    matrix.AddElement(4, 4, 5);

    EXPECT_TRUE(matrix.isEmpty());
    EXPECT_EQ(matrix.GetSize(), 0);
}

TEST(SparseMatrixTest, UpdateElement)
{
    SparseMatrix<int> matrix(3, 3);

    EXPECT_TRUE(matrix.isEmpty());

    matrix.AddElement(0, 0, 5);
    matrix.UpdateElement(0, 0, 10);

    EXPECT_EQ(matrix.GetElement(0, 0), 10);
    EXPECT_NE(matrix.GetElement(0, 0), 5);
    EXPECT_EQ(matrix.GetSize(), 1);
}

TEST(SparseMatrixTest, UpdateNonExistingElement)
{
    SparseMatrix<int> matrix(3, 3);
    matrix.AddElement(0, 0, 5);
    matrix.UpdateElement(1, 1, 10);

    EXPECT_EQ(matrix.GetElement(0, 0), 5);
    EXPECT_FALSE(matrix.isEmpty());
}

TEST(SparseMatrixTest, RemoveElement)
{
    SparseMatrix<int> matrix(3, 3);
    matrix.AddElement(0, 0, 5);
    matrix.RemoveElement(0, 0);

    EXPECT_FALSE(matrix.FindElement(0, 0));
    EXPECT_NE(matrix.GetSize(), 1);
}

TEST(SparseMatrixTest, RemoveNonExistingElement)
{
    SparseMatrix<int> matrix(3, 3);
    matrix.AddElement(0, 0, 5);
    matrix.RemoveElement(1, 1);

    EXPECT_NE(matrix.GetElement(0, 0), 3);
    EXPECT_EQ(matrix.GetSize(), 1);
    EXPECT_FALSE(matrix.isEmpty());
}

TEST(SparseMatrixTest, TransposeSparseMatrix)
{
    SparseMatrix<int> matrix(2, 3);
    matrix.AddElement(0, 0, 1);
    matrix.AddElement(0, 2, 2);
    matrix.AddElement(1, 1, 3);

    matrix.print();

    SparseMatrix<int> transposed = matrix.transposeSparseMatrix();
    transposed.print();

    EXPECT_EQ(transposed.GetElement(0, 0), 1);
    EXPECT_EQ(transposed.GetElement(1, 1), 3);
    EXPECT_NE(transposed.GetElement(2, 0), 0);

    EXPECT_FALSE(transposed.isEmpty());
}

TEST(SparseMatrixTest, TransposeSparseMatrixEmpty)
{
    SparseMatrix<int> matrix(3, 3);
    SparseMatrix<int> transposed = matrix.transposeSparseMatrix();

    EXPECT_EQ(transposed.GetSize(), 0);
    EXPECT_TRUE(transposed.isEmpty());
}

TEST(SparseMatrixTest, Clear)
{
    SparseMatrix<int> matrix(3, 3);
    matrix.AddElement(0, 0, 5);
    matrix.AddElement(1, 1, 10);
    matrix.clear();

    EXPECT_EQ(matrix.GetSize(), 0);
    EXPECT_TRUE(matrix.isEmpty());
}

TEST(SparseMatrixTest, Size)
{
    SparseMatrix<int> matrix(3, 3);
    matrix.AddElement(0, 0, 5);
    matrix.AddElement(1, 1, 10);

    EXPECT_EQ(matrix.GetSize(), 2);

    EXPECT_FALSE(matrix.isEmpty());
}

TEST(SparseMatrixTest, FindElement)
{
    SparseMatrix<int> matrix(3, 3);
    matrix.AddElement(0, 0, 5);
    matrix.AddElement(2, 2, 1);

    EXPECT_TRUE(matrix.FindElement(0, 0));
    EXPECT_TRUE(matrix.FindElement(2, 2));
    EXPECT_FALSE(matrix.FindElement(1, 0));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}