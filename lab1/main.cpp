#include <iostream>
#include <cstdlib>
#include <ctime>

void Initialize(int arr[], int size);
void Show(const int arr[], int size);

void QuickSort(int arr[], int first, int last);

void Merge(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left, int right);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int SIZE = 20;
    int arr1[SIZE];
    int arr2[SIZE];

    Initialize(arr1, SIZE);
    Initialize(arr2, SIZE);

    std::cout << "Arrays before sorting:\n";
    Show(arr1, SIZE);
    Show(arr2, SIZE);

    QuickSort(arr1, 0, SIZE - 1);
    MergeSort(arr2, 0, SIZE - 1);

    std::cout << "Array1 after Quick Sorting:\n";
    Show(arr1, SIZE);
    std::cout << "Array2 after Merge Sorting:\n";
    Show(arr2, SIZE);

    return 0;
}

void Initialize(int arr[], int size)
{
    for (size_t i = 0; i < size; ++i)
        arr[i] = rand() % 100;
}

void Show(const int arr[], int size)
{
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void QuickSort(int arr[], int first, int last)
{
    int middle = arr[(first + last) / 2];
    int i = first;
    int j = last;

    do
    {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;

        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;

        }
    } while (i <= j);

    if (i < last)
        QuickSort(arr, i, last);
    if (j > first)
        QuickSort(arr, first, j);
}

void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}
