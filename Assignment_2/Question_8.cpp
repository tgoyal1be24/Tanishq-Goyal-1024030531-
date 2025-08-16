/*8) Write a program to count the total number of distinct elements in an array of length n.*/
#include <bits/stdc++.h>
using namespace std;

int no_of_distinct_elements(int arr[], int n)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
    return s.size();
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

    int count = no_of_distinct_elements(arr, n);
    if (count == 0)
        cout << "No distinct elements present" << endl;
    else
        cout << "Number of distinct elements present: " << count << endl;

    return 0;
}