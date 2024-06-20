#include "MyString.cpp"
#include "Markov.cpp"

#include <string>

int main()
{
    // string from lib
    std::vector<Elements<std::string>> vP =
        {{"paris", "Paris"},
        {"I", "is"},
        {"T", "the"},
        {"H", "heart"},
        {"O", "of"},
        {"FR", "France"},
        {".", "@"}};

    std::string notMy = "paris I T H O FR.";
    std::cout << notMy << std::endl;

    MarkovAlgorithm(notMy, vP);
    std::cout << notMy << std::endl;


    std::cout << std::endl << std::endl << std::endl;


    // my string
    std::vector<Elements<StringOnArray>> vE;

    Elements<StringOnArray> one;
    one.before = "paris";
    one.after = "Paris";
    Elements<StringOnArray> two;
    two.before = "I";
    two.after = "is";
    Elements<StringOnArray> three;
    three.before = "T";
    three.after = "the";
    Elements<StringOnArray> four;
    four.before = "H";
    four.after = "heart";
    Elements<StringOnArray> five;
    five.before = "O";
    five.after = "of";
    Elements<StringOnArray> six;
    six.before = "FR";
    six.after = "France";
    Elements<StringOnArray> seven;
    seven.before = ".";
    seven.after = "@";

    vE.push_back(one);
    vE.push_back(two);
    vE.push_back(three);
    vE.push_back(four);
    vE.push_back(five);
    vE.push_back(six);
    vE.push_back(seven);

    StringOnArray my("paris I T H O FR.");
    std::cout << my << std::endl;
    MarkovAlgorithm<StringOnArray>(my, vE);
    std::cout << my << std::endl;

    return 0;
}