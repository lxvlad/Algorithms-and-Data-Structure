#include <iostream>
#include <string>

using namespace std;

template <size_t SIZE>
class KeyValueTable
{
private:
    string keys[SIZE];
    int values[SIZE];
    int size;

public:
    KeyValueTable() : size(0) {}

    void AddKeyValue(const string& key, int value)
    {
        if (size >= SIZE)
        {
            cout << "Таблиця повна, не можна додати новий елемент" << endl;
            return;
        }

        for (size_t i = 0; i < size; ++i)
        {
            if (keys[i] == key)
            {
                cout << "Неможливо додати до таблиці, оскільки цей ключ вже існує" << endl;
                return;
            }
        }

        keys[size] = key;
        values[size] = value;
        ++size;

        cout << "Додано: " << key << " - " << value << endl;
    }

    void RemoveKey(const string& key)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (keys[i] == key)
            {
                keys[i] = keys[size - 1];
                values[i] = values[size - 1];
                size--;

                cout << "Видалено пару з ключем: " << key << endl;
                return;
            }
        }

        cout << "Ключ: " << key << " не знайдено. Неможливо видалити" << endl;
    }

    int GetValue(const string& key)
    {
        for (size_t i = 0; i < size; ++i)
            if (keys[i] == key)
                return values[i];

        return -1;
    }

    void GetTable()
    {
        for (size_t i = 0; i < size; ++i)
            cout << keys[i] << ": " << values[i] << endl;
    }

    int GetSize() const
    {
        return size;
    }
};
