#include <gtest/gtest.h>
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab2/Stack/Stack.cpp"

TEST(StackTest, ConstructorAndEmpty)
{
    Stack s;
    EXPECT_TRUE(s.empty());
}

TEST(StackTest, PushAndTop)
{
    Stack s;
    s.push(5);
    EXPECT_EQ(s.top(), 5);
    EXPECT_FALSE(s.empty());

    s.push(14);
    EXPECT_EQ(s.top(), 14);
}

TEST(StackTest, Pop)
{
    Stack s;
    s.push(7);
    s.push(9);
    EXPECT_EQ(s.pop(), 9);
    EXPECT_EQ(s.top(), 7);
    EXPECT_EQ(s.pop(), 7);
    EXPECT_TRUE(s.empty());
}

TEST(StackTest, PopEmptyStack)
{
    Stack s;
    EXPECT_EQ(s.pop(), 0);
    EXPECT_TRUE(s.empty());
}

TEST(StackTest, LargeNumberOfElements)
{
    Stack s;
    const int largeNumber = 1000;

    for (int i = 0; i < largeNumber; ++i)
        s.push(i);

    for (int i = largeNumber - 1; i >= 0; --i)
        EXPECT_EQ(s.pop(), i);

    EXPECT_TRUE(s.empty());
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}