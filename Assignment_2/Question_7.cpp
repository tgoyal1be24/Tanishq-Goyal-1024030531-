/*7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
if these numbers are out of order, i.e., i < j but A[i]>A[j ].
Write a program to count the number of inversions in an array.*/
#include <iostream>
using namespace std;

int countInversions(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int inversions = countInversions(arr, n);

    if (inversions == 0)
        cout << "No inversions present" << endl;
    else
        cout << "Number of inversions present: " << inversions << endl;

    return 0;
}
