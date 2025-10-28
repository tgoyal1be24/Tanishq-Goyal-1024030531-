#include <iostream>
using namespace std;

// ---------------------------------------------------
// Heapify function — maintains the max/min heap property
// ---------------------------------------------------
void heapify(int arr[], int n, int i, bool isMaxHeap)
{
    int extreme = i; // Index of largest (for max) or smallest (for min)
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // For increasing order — use Max Heap
    // For decreasing order — use Min Heap
    if (isMaxHeap)
    {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    }
    else
    {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    // If root is not extreme, swap and continue heapifying
    if (extreme != i)
    {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, isMaxHeap);
    }
}

// ---------------------------------------------------
// Build heap and perform HeapSort
// ---------------------------------------------------
void heapSort(int arr[], int n, bool increasing = true)
{
    bool isMaxHeap = increasing; // max-heap for ascending order

    // Step 1: Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Move root to end
        heapify(arr, i, 0, isMaxHeap);
    }

    // If decreasing order, reverse array
    if (!increasing)
    {
        for (int i = 0; i < n / 2; i++)
            swap(arr[i], arr[n - i - 1]);
    }
}

// ---------------------------------------------------
// Utility: Print array
// ---------------------------------------------------
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------------------------------------------------
// Main function
// ---------------------------------------------------
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n, true);
    cout << "Sorted in Increasing Order: ";
    printArray(arr, n);

    heapSort(arr, n, false);
    cout << "Sorted in Decreasing Order: ";
    printArray(arr, n);

    return 0;
}
