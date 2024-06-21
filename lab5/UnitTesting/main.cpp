#include <gtest/gtest.h>
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/PolishNotation/ReverseEntry.cpp"

// Test the priority function
TEST(ReverseEntryTest, PriorityTest) {
    EXPECT_EQ(priority('^'), 3);
    EXPECT_EQ(priority('*'), 2);
    EXPECT_EQ(priority('/'), 2);
    EXPECT_EQ(priority('+'), 1);
    EXPECT_EQ(priority('-'), 1);
    EXPECT_EQ(priority('#'), 0);
    EXPECT_EQ(priority('('), 0);
    EXPECT_EQ(priority(')'), 0);
    EXPECT_EQ(priority('a'), -1); // for non-operator characters
}

// Test the isDigital function
TEST(ReverseEntryTest, IsDigitalTest) {
    EXPECT_TRUE(isDigital('0'));
    EXPECT_TRUE(isDigital('5'));
    EXPECT_TRUE(isDigital('9'));
    EXPECT_FALSE(isDigital('a'));
    EXPECT_FALSE(isDigital(' '));
}

// Test the isOperand function
TEST(ReverseEntryTest, IsOperandTest) {
    EXPECT_TRUE(isOperand('+'));
    EXPECT_TRUE(isOperand('-'));
    EXPECT_TRUE(isOperand('*'));
    EXPECT_TRUE(isOperand('/'));
    EXPECT_TRUE(isOperand('('));
    EXPECT_TRUE(isOperand(')'));
    EXPECT_TRUE(isOperand('^'));
    EXPECT_FALSE(isOperand('a'));
    EXPECT_FALSE(isOperand('1'));
}

// Test the applyOperator function
TEST(ReverseEntryTest, ApplyOperatorTest) {
    EXPECT_DOUBLE_EQ(applyOperator(3, 4, '+'), 7);
    EXPECT_DOUBLE_EQ(applyOperator(10, 3, '-'), 7);
    EXPECT_DOUBLE_EQ(applyOperator(2, 5, '*'), 10);
    EXPECT_DOUBLE_EQ(applyOperator(10, 2, '/'), 5);
    EXPECT_DOUBLE_EQ(applyOperator(2, 3, '^'), 8); // 2^3 = 8
}

// Test the toPostfix function
TEST(ReverseEntryTest, ToPostfixTest) {
    EXPECT_EQ(toPostfix("3+4"), "34+");
    EXPECT_EQ(toPostfix("2*3+4"), "23*4+");
    EXPECT_EQ(toPostfix("(1+2)*3"), "12+3*");
    EXPECT_EQ(toPostfix("3^2"), "32^");
}

// Test the calculate function
TEST(ReverseEntryTest, CalculateTest)
{
    // Provide additional output for debugging
    std::string expression;

    expression = "34+";
    EXPECT_EQ(calculate(expression), 7) << "Failed on expression: " << expression;

    expression = "23*4+";
    EXPECT_EQ(calculate(expression), 10) << "Failed on expression: " << expression;

    expression = "12+3*";
    EXPECT_EQ(calculate(expression), 9) << "Failed on expression: " << expression;

    expression = "32^";
    EXPECT_EQ(calculate(expression), 9) << "Failed on expression: " << expression;

    expression = "42/";
    EXPECT_EQ(calculate(expression), 2) << "Failed on expression: " << expression;
}

// Test the toInfix function
TEST(ReverseEntryTest, ToInfixTest) {
    EXPECT_EQ(toInfix("34+"), "(3+4)");
    EXPECT_EQ(toInfix("23*4+"), "((2*3)+4)");
    EXPECT_EQ(toInfix("12+3*"), "((1+2)*3)");
    EXPECT_EQ(toInfix("32^"), "(3^2)");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
