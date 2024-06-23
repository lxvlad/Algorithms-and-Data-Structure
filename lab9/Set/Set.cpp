#include <stdexcept>
#include <iostream>

class BitSet
{
private:
    static const int size = 8;
    unsigned int bits;

public:
    BitSet() : bits(0) {}

    void add(int index)
    {
        if (index >= 0 && index < size)
            bits |= (1 << index);
        else
            std::cerr << "Invalid index!\n";
    }

    void remove(int index)
    {
        if (index >= 0 && index < size)
            bits &= ~(1 << index);
        else
            std::cerr << "Invalid index!\n";
    }

    bool contains(int index) const
    {
        if (index >= 0 && index < size)
            return (bits & (1 << index)) != 0;
        else
            std::cerr << "Invalid index!\n";
    }

    void print() const
    {
        for (int i = size - 1; i >= 0; --i)
            std::cout << ((bits & (1 << i)) ? '1' : '0');
        std::cout << std::endl;
    }

    BitSet merge(const BitSet& bs) const
    {
        BitSet result;
        result.bits = bits | bs.bits;
        return result;
    }

    BitSet intersect(const BitSet& bs) const
    {
        BitSet result;
        result.bits = bits & bs.bits;
        return result;
    }

    BitSet difference(const BitSet& bs) const
    {
        BitSet result;
        result.bits = bits & ~bs.bits;
        return result;
    }
};

// class BitSet_Lit
// {
// private:
//     int set = 0;
// public:
//     void add(char symbol_to_add)
//     {
//         // check that symbol is in 'a'...'z' range
//         set = set | (1 << (symbol_to_add - 'a'));
//     }
// };


//
// Created by Vladyslav Lishchynskyi on 25.05.2024.
//

