#include <iostream>
#include <string>
#include <list>
#include "HashTable.cpp"

using namespace std;

int main()
{
    HashTable ht;
    cout << "Is hash table is empty? - " << std::boolalpha << ht.isEmpty() << endl;

    ht.push(500, "Kyiv");
    ht.push(600, "Lniv");
    ht.push(750, "Novoyavorivks");
    ht.push(300, "Warsaw");
    ht.push(250, "Madrid");
    ht.push(100, "Antalya");
    ht.push(50, "Prague");
    ht.push(50, "Krakow");

    ht.printTable();

    ht.pop(750);
    ht.pop(60);

    cout << "Is hash table is empty? - " << std::boolalpha << ht.isEmpty() << endl;



    return 0;
}