#include "SparseMatrix.cpp"

int main()
{
    SparseMatrix<int> matrix(3, 4);

    matrix.AddElement(0, 0, 1);
    matrix.AddElement(0, 2, 2);
    matrix.AddElement(1, 1, 3);
    matrix.AddElement(2, 2, 5);
    matrix.AddElement(1, 3, 8);
    matrix.print();
    cout << endl;

    cout << "Check if element exist:\n";
    cout << matrix.FindElement(0, 0) << endl;
    cout << matrix.FindElement(0, 1) << endl;
    cout << endl;

    cout << "Get Element:\n";
    cout << matrix.GetElement(1, 3) << endl;
    cout << matrix.GetElement(5, 5) << endl;
    cout << endl;

    cout << "Updated Matrix:\n";
    matrix.UpdateElement(1, 1, 4);
    matrix.print();
    cout << endl;


    cout << "Matrix after removing:\n";
    matrix.RemoveElement(1, 1);
    // matrix.RemoveElement(0, 1);
    // matrix.RemoveElement(5, 5);
    matrix.print();
    cout << endl;


    cout << "Matrix after transposing:\n";
    SparseMatrix<int> transposed = matrix.transposeSparseMatrix();
    transposed.print();
    cout << endl;

    cout << "Matrix after clearing:\n";
    matrix.clear();
    cout << matrix.isEmpty() << endl;
    cout << "Size: " << matrix.GetSize() << endl;
    matrix.print();
    cout << endl;

    return 0;
}