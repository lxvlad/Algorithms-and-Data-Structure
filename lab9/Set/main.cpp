#include <iostream>
#include "Set.cpp";

int main()
{
    BitSet mySet;

    mySet.add(1);
    mySet.add(3);
    mySet.print();

    std::cout << "Check if contains 1: " << std::boolalpha << mySet.contains(1) << std::endl;
    std::cout << "Check if contains 2: " << std::boolalpha << mySet.contains(2) << std::endl;

    mySet.remove(3);
    mySet.print();

    /// merge

    BitSet set_1, set_2;

    set_1.add(1);
    set_1.add(3);
    set_1.add(5);

    set_2.add(2);
    set_2.add(4);
    set_2.add(5);

    std::cout << "set_1: ";
    set_1.print();

    std::cout << "set_2: ";
    set_2.print();

    BitSet mergedSet = set_1.merge(set_2);
    std::cout << "Merged Set: ";
    mergedSet.print();

    return 0;
}
