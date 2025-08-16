/*4) String Related Programs (a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string. (c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.*/
#include <bits/stdc++.h>
using namespace std;

// a) Concatenate one string to another
void concatenateStrings()
{
    string str1, str2;
    cout << "Enter first string: ";
    cin.ignore();
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    str1 += str2;
    cout << "Concatenated string: " << str1 << endl;
}

// b) Reverse a string
void reverseString()
{
    string str;
    cout << "Enter string: ";
    cin.ignore();
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
}

// c) Delete all vowels from a string
void deleteVowels()
{
    string str;
    cout << "Enter string: ";
    cin.ignore();
    getline(cin, str);
    string result;
    for (char ch : str)
    {
        char lower = tolower(ch);
        if (!(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'))
            result += ch;
    }
    cout << "String without vowels: " << result << endl;
}

// d) Sort strings in alphabetical order
void sortStrings()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    string arr[n];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++)
        getline(cin, arr[i]);
    sort(arr, arr + n);
    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

// e) Convert a character from uppercase to lowercase
void convertToLowercase()
{
    char ch;
    cout << "Enter uppercase character: ";
    cin >> ch;
    if (isupper(ch))
        ch = tolower(ch);
    cout << "Lowercase: " << ch << endl;
}

int main()
{
    int choice = 0;
    cout << "\nSTRING OPERATIONS MENU\n";
    cout << "1. Concatenate Strings\n";
    cout << "2. Reverse String\n";
    cout << "3. Delete Vowels\n";
    cout << "4. Sort Strings Alphabetically\n";
    cout << "5. Convert Uppercase to Lowercase\n";
    cout << "6. Exit\n";
    while (true)
    {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            concatenateStrings();
            break;
        case 2:
            reverseString();
            break;
        case 3:
            deleteVowels();
            break;
        case 4:
            sortStrings();
            break;
        case 5:
            convertToLowercase();
            break;
        case 6:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
