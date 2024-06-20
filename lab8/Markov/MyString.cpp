#include <iostream>

class StringOnArray
{
private:
    size_t string_length;
    char* container;

public:
    StringOnArray()
    {
        string_length = 1;
        container = new char[string_length];
        container[string_length - 1] = '\0';
    }

    StringOnArray(const char* other)
    {
        string_length = strlen(other) + 1;
        container = new char[string_length];
        for (int i = 0; i < (string_length - 1); ++i)
        {
            container[i] = other[i];
        }
        container[(string_length - 1)] = '\0';
    }

    StringOnArray(const StringOnArray& other)
    {
        string_length = other.string_length;
        container = new char[string_length];
        for (int i = 0; i < (string_length - 1); ++i)
        {
            container[i] = other.container[i];
        }
        container[(string_length - 1)] = '\0';
    }

    ~StringOnArray()
    {
        delete[] container;
    }

    size_t length() const
    {
        return strlen(container);
    }

    const char& operator[](size_t i) const
    {
        return container[i];
    }

    char& operator[](size_t i)
    {
        return container[i];
    }

    StringOnArray& operator=(const StringOnArray& other)
    {
        delete[] container;
        string_length = other.string_length;
        container = new char[string_length];
        for (int i = 0; i < string_length - 1; ++i)
        {
            container[i] = other.container[i];
        }
        container[string_length - 1] = '\0';
        return *this;
    }

    void erase(unsigned index, unsigned length)
    {
        for (int i = index; i < string_length - length; ++i)
        {
            container[i] = container[i + length];
        }
        string_length -= length;
    }

    size_t find(const StringOnArray& other) const
    {
        size_t index = -1;
        bool isIn = false;
        for (int i = 0; i < length() - other.length() + 1; ++i)
        {
            size_t count = 0;
            if (container[i] == other[count])
            {
                isIn = true;
                ++count;
                while (isIn && count < other.length())
                {
                    if (container[count + i] != other[count])
                    {
                        isIn = false;
                        break;
                    }
                    ++count;
                }
                if (isIn)
                {
                    index = i;
                    break;
                }
            }
        }
        return index;
    }

    void replace(size_t index, size_t length, const StringOnArray& other)
    {
        if (length == other.length())
        {
            unsigned count = 0;
            for (int i = index; i < length + index; ++i)
            {
                container[i] = other[count];
                ++count;
            }
        }
        else
        {
            unsigned size = other.length();
            char* temp = new char[string_length + size - length];
            for (int i = 0; i < index; ++i)
            {
                temp[i] = container[i];
            }
            for (int i = index, j = 0; i < index + size; ++i, ++j)
            {
                temp[i] = other[j];
            }
            for (int i = index; i + length < string_length; ++i)
            {
                temp[i + size] = container[i + length];
            }
            string_length = string_length + size - length;
            delete[] container;
            container = temp;
            container[string_length - 1] = '\0';
        }
    }

    friend std::ostream& operator<< (std::ostream& out, const StringOnArray& other)
    {
        out << other.container;
        return out;
    }
};

