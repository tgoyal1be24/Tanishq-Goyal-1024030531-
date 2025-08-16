/*1) Implement the Binary search algorithm regarded as a fast search algorithm with run-time complexity of
     Ο(log n) in comparison to the Linear Search.*/
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Avoid overflow
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

int main()
{
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element found at position (0-based index): " << result << endl;
    else
        cout << "Element not found.\n";

    return 0;
}
