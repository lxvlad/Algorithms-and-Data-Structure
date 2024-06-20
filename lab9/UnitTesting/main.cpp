#include <gtest/gtest.h>
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab9/Set/Set.cpp"

TEST(BitSetTest, Add_ValidIndex)
{
    BitSet bs;
    bs.add(2);
    EXPECT_TRUE(bs.contains(2));
}

TEST(BitSetTest, Add_InvalidIndex)
{
    BitSet bs;
    bs.add(8);
    EXPECT_FALSE(bs.contains(8));
}

TEST(BitSetTest, Remove_ValidIndex)
{
    BitSet bs;
    bs.add(2);
    bs.remove(2);
    EXPECT_FALSE(bs.contains(2));
}

TEST(BitSetTest, Contains_ValidIndex)
{
    BitSet bs;
    bs.add(2);
    EXPECT_TRUE(bs.contains(2));
    EXPECT_FALSE(bs.contains(3));
}

TEST(BitSetTest, Merge_CombinesBits)
{
    BitSet bs1;
    bs1.add(1);
    BitSet bs2;
    bs2.add(2);
    BitSet result = bs1.merge(bs2);
    EXPECT_TRUE(result.contains(1));
    EXPECT_TRUE(result.contains(2));
}

TEST(BitSetTest, Print_PrintsBitsCorrectly)
{
    BitSet bs;
    bs.add(1);
    bs.add(3);
    testing::internal::CaptureStdout();
    bs.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "00001010\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
