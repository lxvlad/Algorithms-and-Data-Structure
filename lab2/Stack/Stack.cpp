#include <stdexcept>

class Stack
{
private:
    int size;
    int top_index;
    int* arr;

    void resize()
    {
        size *= 2;
        int* new_arr = new int[size];
        for (int i = 0; i < top_index; ++i)
            new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
    }

public:
    Stack() : size(5), top_index(0), arr(new int[size]) {}
    ~Stack() { delete[] arr; }

    void push(int value)
    {
        if (top_index >= size)
            resize();
        arr[top_index++] = value;
    }

    int pop()
    {
        if (!empty())
            return arr[--top_index];

        return 0; // стек пустий
        // throw std::out_of_range("Stack is empty!\n");
    }

    int top() const
    {
        if (!empty())
            return arr[top_index - 1];
        return 0; // стек пустий
        // throw std::out_of_range("Stack is empty!\n");
    }

    bool empty() const
    {
        return (top_index == 0);
    }
};

//
// Created by Vladyslav Lishchynskyi on 25.05.2024.
//
