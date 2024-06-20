#include <gtest/gtest.h>
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab7/Queue/Queue.cpp"

TEST(MyQueueTest, EmptyQueueIsEmpty)
{
    MyQueue<int> queue;
    EXPECT_TRUE(queue.isEmpty());
}

TEST(MyQueueTest, PushIncreasesSize)
{
    MyQueue<int> queue;
    queue.push(5);
    EXPECT_EQ(queue.getSize(), 1);
}

TEST(MyQueueTest, PushAndPop)
{
    MyQueue<int> queue;
    queue.push(5);
    queue.push(8);

    EXPECT_EQ(queue.getSize(), 2);
    queue.pop();

    EXPECT_FALSE(queue.isEmpty());

    queue.pop();
    ASSERT_TRUE(queue.isEmpty());
}


TEST(MyQueueTest, GetTop)
{
    MyQueue<int> queue;

    for (int i = 0; i < 5; i++)
        queue.push(i);

    EXPECT_EQ(queue.getSize(), 5);

    for (int i = 0; i < queue.getSize(); i++)
    {
        EXPECT_EQ(queue.getTop(), i);
        queue.pop();
    }
}


TEST(MyQueueTest, ClearQueue)
{
    MyQueue<int> queue;

    for (int i = 0; i < 7; i++)
    queue.push(i);

    EXPECT_EQ(queue.getSize(), 7);

    queue.clear();

    EXPECT_TRUE(queue.isEmpty());
}

// --- Test for MyPriorityQueue ---

TEST(MyPriorityQueueTest, EmptyQueueIsEmpty)
{
    MyPriorityQueue queue;

    EXPECT_TRUE(queue.isEmpty());
}

TEST(MyPriorityQueueTest, PushIncreasesSize)
{
    MyPriorityQueue queue;
    queue.push(5, 1);

    EXPECT_EQ(queue.getSize(), 1);
}

TEST(MyPriorityQueueTest, PushAndPop)
{
    MyPriorityQueue queue;
    queue.push(5, 1);

    ASSERT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.getSize(), 1);

    queue.pop();

    ASSERT_TRUE(queue.isEmpty());
}

TEST(MyPriorityQueueTest, GetTop)
{
    MyPriorityQueue queue;
    queue.push(5, 1);
    queue.push(54, 5);
    queue.push(81, 78);

    EXPECT_EQ(queue.getTop(), 81);

    queue.pop();
    EXPECT_EQ(queue.getTop(), 54);

    queue.pop();
    EXPECT_EQ(queue.getTop(), 5);
}

TEST(MyPriorityQueueTest, ClearQueue)
{
    MyPriorityQueue queue;
    queue.push(5, 1);
    queue.push(10, 2);

    EXPECT_EQ(queue.getSize(), 2);
    queue.clear();

    EXPECT_TRUE(queue.isEmpty());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}