#include <iostream>
#include <list>
#include <string>

using namespace std;

class HashTable
{
private:
    static const int tableSize = 10;
    list<pair<int, string>> table[tableSize]; // масив списків пар (ключ, значення)

public:
    bool isEmpty() const
    {
        for (int i = 0; i < tableSize; ++i)
            if (!table[i].empty())
                return false;

        return true;
    }

    int hashFunction(int key) const
    {
        return key % tableSize;
    }

    void push(int key, string value)
    {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        for (auto& pair : cell) // перевірка наявності ключа
        {
            if (pair.first == key)
            {
                pair.second = value; // заміна значення, якщо ключ вже існує
                cout << "Error. Key exists. Value replaced." << endl;
                return;
            }
        }
        cell.emplace_back(key, value); // вставка нової пари, якщо ключ не знайдено
    }

    void pop(int key)
    {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        for (auto it = cell.begin(); it != cell.end(); ++it)
        {
            if (it->first == key)
            {
                cell.erase(it); // видалення пари, якщо ключ знайдено
                cout << "Pair removed." << endl;
                return;
            }
        }
        cout << "Error. Key not found. Pair not removed." << endl;
    }

    void printTable() const
    {
        for (int i = 0; i < tableSize; ++i)
        {
            if (table[i].empty()) continue; // пропуск порожніх списків
            for (const auto& pair : table[i])
            {
                cout << "Key: " << pair.first << " Value: " << pair.second << endl;
            }
        }
    }

    // для тестів
    string getValue(int key) const
    {
        int hashValue = hashFunction(key);
        const auto& cell = table[hashValue];
        for (const auto& pair : cell)
        {
            if (pair.first == key)
                return pair.second;
        }
        return "";
    }
    // для тестів
    bool hasKey(int key) const
    {
        int hashValue = hashFunction(key);
        const auto& cell = table[hashValue];
        for (const auto& pair : cell)
        {
            if (pair.first == key)
                return true;
        }
        return false;
    }
};


