#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "/Users/vlish21/University/Algorithms-and-Data-Structure/lab8/Markov/Markov.cpp"

// заміна по правилу із завершенням '@'
TEST(MarkovAlgorithmTest, ReplaceWithTerminationSymbol) {
    std::string input = "ab";
    std::vector<Elements<std::string>> rules = {
        {"ab", "c@"}
    };

    MarkovAlgorithm(input, rules);
    EXPECT_EQ(input, "c");
}

// заміна за декількома правилами
TEST(MarkovAlgorithmTest, MultipleReplacements) {
    std::string input = "abc";
    std::vector<Elements<std::string>> rules = {
        {"a", "x"},
        {"b", "y"},
        {"c", "z@"}
    };

    MarkovAlgorithm(input, rules);
    EXPECT_EQ(input, "xyz");
}

// без заміни
TEST(MarkovAlgorithmTest, NoReplacement) {
    std::string input = "abc";
    std::vector<Elements<std::string>> rules = {
        {"d", "x"},
        {"e", "y"},
        {"f", "z@"}
    };

    MarkovAlgorithm(input, rules);
    EXPECT_EQ(input, "abc");
}

// перевірка на пустий рядок
TEST(MarkovAlgorithmTest, EmptyString) {
    std::string input = "";
    std::vector<Elements<std::string>> rules = {
        {"a", "b@"}
    };

    MarkovAlgorithm(input, rules);
    EXPECT_EQ(input, "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

