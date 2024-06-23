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

    /// merge, intersection and difference

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

    // merge
    BitSet mergedSet = set_1.merge(set_2);
    std::cout << "Merged Set: ";
    mergedSet.print();

    // intersection
    BitSet intersectedSet = set_1.intersect(set_2);
    std::cout << "Intersected Set: ";
    intersectedSet.print();

    // difference
    BitSet differSet = set_1.difference(set_2);
    std::cout << "Difference Set: ";
    differSet.print();


    return 0;
}
