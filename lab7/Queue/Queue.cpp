#include <iostream>
using namespace std;

template <typename T>
class MyQueue
{
private:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
    };

    Node* head; // місце вилучення
    Node* tail; // місце включення
    size_t size;

public:
    MyQueue() : head(nullptr), tail(nullptr), size(0) {}

    void push(const T& value)
    {
        // якщо черга порожня то новий елемент стає стає і головою і хвостом
        if (size == 0)
        {
            head = new Node{value, tail, nullptr};
            tail = head;
        }
        // інакше новий елемент додається в кінець черги
        else
        {
            tail->next = new Node{value, tail, nullptr};
            tail = tail->next;
        }

        size++;
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "No any elements to delete!";
            return;
        }

        // якщо в черзі тільки один елемент, то видаляєм його, і, відповідно зануляєм head та tail
        if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            head->previous = nullptr;
            delete temp;
        }

        size--;
    }

    void showQueue() const
    {
        if (size == 0)
        {
            cout << "Queue is empty!";
            return;
        }

        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        size = 0;
    }

    T& getTop()
    {
        return head->data;
    }

    size_t getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }
};

class MyPriorityQueue
{
private:
    struct Node
    {
        int data;
        int priority;
        Node* previous;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    MyPriorityQueue() : head(nullptr), tail(nullptr), size(0) {}

    void push(int value, int priority)
    {
        Node* newNode = new Node{value, priority, nullptr, nullptr};

        // якшо черга порожня, новий елемент (вузол) стає і головою, і хвостом.
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        // інакше знаходимо правильне місце для нового елемента на основі його пріоритету
        else
        {
            Node* current = head;

            while (current && current->priority >= priority)
                current = current->next;

            // якщо досягнуто кінець черги (current дорівнює nullptr), новий вузол додається в кінець черги
            if (!current)
            {
                newNode->previous = tail;
                tail->next = newNode;
                tail = newNode;
            }
            // якщо новий вузол має пріоритет вищий, ніж у голови черги, він вставляється на початок.
            else if (current == head)
            {
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            }
            // вставка вузла в середину черги
            else
            {
                newNode->previous = current -> previous;
                newNode->next = current;
                current->previous -> next = newNode;
                current->previous = newNode;
            }
        }

        size++;
    }

    void pop()
    {
        if (!head)
        {
            cerr << "No any elements to delete!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head)
            head->previous = nullptr;
        else
            tail = nullptr;

        delete temp;
        size--;
    }

    void showPriorityQueue() const
    {
        if (size == 0)
            return;

        Node* current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        size = 0;
    }

    int& getTop()
    {
        return head->data;
    }

    size_t getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }
};