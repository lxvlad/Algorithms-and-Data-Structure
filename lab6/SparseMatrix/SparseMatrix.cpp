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
            // Створення нового елементу MatrixElement з переданими значеннями row, col і value
            MatrixElement* newElement = new MatrixElement(row, col, value);

            // Перевірка, чи рядок data[row] є порожнім або чи стовпець нового елементу менший за стовпець першого елементу в рядку
            if (!data[row] || data[row]->column > col)
            {
                // новий елемент стає першим в рядку
                newElement->next = data[row];
                data[row] = newElement;

                // Збільшення лічильника кількості елементів в матриці
                size++;
            }
            else
            {
                // Якщо умова вище не справджується, то потрібно вставити новий елемент відповідно до порядку стовпців
                MatrixElement* curr = data[row];

                // Прохід по зв'язаному списку у поточному рядку, щоб знайти місце для вставки нового елементу
                while (curr->next && curr->next->column < col)
                    curr = curr->next;

                // Вставка нового елементу після поточного, який має стовпець менший за col
                newElement->next = curr->next;
                curr->next = newElement;

                // Збільшення лічильника кількості елементів в матриці
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
            // Починаємо з першого елемента в рядку data[row]
            MatrixElement* curr = data[row];

            // Прохід по зв'язаному списку у поточному рядку, щоб знайти елемент з вказаним стовпцем col
            while (curr)
            {
                // Якщо знайдено елемент зі стовпцем col, оновлюємо його значення на нове value
                if (curr->column == col)
                {
                    curr->value = value;
                    return; // Після оновлення виходимо з функції
                }
                curr = curr->next; // Переходимо до наступного елементу у зв'язаному списку
            }
        }
        else
            cout << "Invalid row or column index!\n";
    }


    void RemoveElement(int row, int col)
    {
        if (row >= 0 && row < rows && col >= 0 && col < columns)
        {
            // Перевірка, чи існує хоча б один елемент в рядку data[row]
            if (!data[row])
            {
                cout << "Element not found!" << endl;
                return;
            }

            // Ініціалізація двох вказівників для проходу по зв'язаному списку в рядку data[row]
            MatrixElement* curr = data[row];
            MatrixElement* prev = nullptr;

            // Прохід по зв'язаному списку, щоб знайти елемент з вказаним стовпцем col
            while (curr)
            {
                if (curr->column == col)
                {
                    // Якщо знайдено елемент зі стовпцем col, видаляємо його зі зв'язаного списку
                    if (prev)
                        prev->next = curr->next; // Пов'язуємо попередній елемент з наступним
                    else
                        data[row] = curr->next; // Якщо видаляємо перший елемент, змінюємо початок рядка

                    delete curr; // Видаляємо поточний елемент
                    cout << "Element removed successfully!" << endl;
                    size--; // Зменшуємо лічильник кількості елементів в матриці
                    return;
                }

                prev = curr; // Переміщуємо попередній елемент на поточний
                curr = curr->next; // Переходимо до наступного елементу у зв'язаному списку
            }

            // Якщо не знайдено елемента зі стовпцем col, виводимо повідомлення про помилку
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

        // Прохід по кожному рядку поточної матриці
        for (int i = 0; i < rows; i++)
        {
            // Отримання першого елементу в поточному рядку data[i]
            MatrixElement* curr = data[i];

            // Прохід по зв'язаному списку елементів у поточному рядку
            while (curr)
            {
                // Додавання елементу до транспонованої матриці з обміненими координатами (curr->column, curr->row)
                transposed.AddElement(curr->column, curr->row, curr->value);

                // Перехід до наступного елементу у поточному рядку
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