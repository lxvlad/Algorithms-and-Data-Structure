#include <iostream>
using namespace std;
template<typename T>
class SparseMatrix
{
private:
    struct MatrixElement
    {
        int row;
        int column;
        T value;
        MatrixElement* next;

        MatrixElement(int r, int c, T v) : row(r), column(c), value(v), next(nullptr) {}
    };

    int rows;
    int columns;
    int size;
    MatrixElement** data;                                                                         // двовимірний масив вказівників, який вказує на початок кожного рядка у матриці

public:
    SparseMatrix(int rows, int cols) : rows(rows), columns(cols), size(0)
    {
        data = new MatrixElement*[rows];

        for (int i = 0; i < rows; i++)
            data[i] = nullptr;
    }
    ~SparseMatrix()
    {
        clear();
    }

    void AddElement(int row, int col, T value)
    {
        if (row >= 0 && row < rows && col >= 0 && col < columns)
        {
            MatrixElement* newElement = new MatrixElement(row, col, value); // створюється об'єкт типу MatrixElement, представляє новий елемент матриці.

            if (!data[row] || data[row] -> column > col) // чи поточний рядок порожній або чи перший елемент у рядку має більший номер стовпця, ніж новий елемент
            {
                newElement->next = data[row];  // новий елемент додається на початок списку елементів цього рядка.
                data[row] = newElement;

                size++;
            }
            else // чи новий елемент не має потрапити між двома існуючими елементами у рядку
            {
                MatrixElement* curr = data[row];

                while (curr->next && curr->next->column < col)
                    curr = curr->next;

                newElement->next = curr->next;
                curr->next = newElement;

                size++;
            }
        }
        else
            cout << "Invalid row or column index!\n";
    }

    void UpdateElement(int row, int col, T value)
    {
        if (row >= 0 && row < rows && col >= 0 && col < columns)
        {
            MatrixElement* curr = data[row];

            while (curr)
            {
                if (curr->column == col) // пошук елемента який має той самий номер стовпця
                {
                    curr->value = value; // якщо такий елемент знайдено, змінюємо його
                    return;
                }
                curr = curr->next;
            }
        }
        else
            cout << "Invalid row or column index!\n";
    }

    void RemoveElement(int row, int col)
    {
        if (row >= 0 && row < rows && col >= 0 && col < columns)
        {
            if (!data[row]) // чи рядок, з якого ми хочемо видалити елемент, не порожній
            {
                cout << "Element not found!" << endl;
                return;
            }

            MatrixElement* curr = data[row]; // вказівник curr вказує на перший елемент списку зв'язаних елементів у рядку
            MatrixElement* prev = nullptr; // на попередній елемент перед curr

            while (curr)
            {
                if (curr->column == col) // пошук елемента в рядку за його номером стовпця
                {
                    if (prev) // якщо попередній елемент існує
                        prev->next = curr->next; // перенаправляє вказівник next на наступний елемент після curr
                    else
                        data[row] = curr->next; // означає, що curr - перший елемент у списку, тому data[row]

                    delete curr;
                    cout << "Element removed successfully!" << endl;
                    size--;
                    return;
                }

                prev = curr;
                curr = curr->next;
            }
            cout << "Element not found!" << endl;
        }
        else
            cout << "Invalid row or column index!\n";
    }

    T GetElement(int row, int col)
    {
        if (row >= 0 && row < rows && col >= 0 && col < columns)
        {
            MatrixElement* curr = data[row];
            while (curr)
            {
                if (curr->column == col)
                    return curr->value;
                curr = curr->next;
            }
        }
        else
            return 0;
    }

    bool FindElement(int row, int col) const
    {
        if (row >= 0 && row < rows && col >= 0 && col < columns)
        {
            MatrixElement* curr = data[row];
            while (curr)
            {
                if (curr->column == col)
                    return true;
                curr = curr->next;
            }
        }
        return false;
    }

    SparseMatrix transposeSparseMatrix()
    {
        SparseMatrix transposed(columns, rows);

        for (int i = 0; i < rows; i++)
        {
            MatrixElement* curr = data[i];
            while (curr)
            {
                transposed.AddElement(curr->column, curr->row, curr->value);
                curr = curr->next;
            }
        }
        return transposed;
    }

    void print()
    {
        for (size_t i = 0; i < rows; i++)
        {
            MatrixElement* curr = data[i];

            for (size_t j = 0; j < columns; j++)
            {
                if (curr && curr->column == j)
                {
                    cout << curr->value << " ";
                    curr = curr->next;
                }
                else
                    cout << "0 ";
            }

            cout << endl;
        }
    }

    void clear()
    {
        for (int i = 0; i < rows; i++)
        {
            MatrixElement* curr = data[i];
            while (curr)
            {
                MatrixElement* temp = curr;
                curr = curr->next;
                delete temp;
                size--;
            }
            data[i] = nullptr;
        }
    }

    bool isEmpty() const
    {
        for (int i = 0; i < rows; i++)
            if (data[i])
                return false;
        return true;
    }

    int& GetSize()
    {
        return size;
    }
};