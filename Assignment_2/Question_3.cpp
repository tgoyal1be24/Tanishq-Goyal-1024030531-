/*3) Design the Logic to Find a Missing Number in a Sorted Array.*/
// Works for an array containing consecutive numbers with one missing element.
#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n)
{
    int start = 0, end = n - 1;
    int diff = arr[0] - 0; // Expected difference between index and value

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] - mid != diff)
        {
            if (mid == 0 || arr[mid - 1] - (mid - 1) == diff)
                return mid + diff;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1; // No missing number found
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted array (one number missing): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int missing = findMissingNumber(arr, n);
    if (missing != -1)
        cout << "Missing number is: " << missing << endl;
    else
        cout << "No missing number.\n";

    return 0;
}
