/*5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming array
is used to store elements of the following matrices, implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix*/
#include <iostream>
#include <vector>
using namespace std;

// (a) Diagonal Matrix storage
void diagonalMatrix()
{
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;
    vector<int> diag(n, 0);
    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++)
        cin >> diag[i];
    cout << "Stored elements: ";
    for (int i : diag)
        cout << i << " ";
    cout << endl;
}

// (b) Tri-diagonal Matrix storage
void tridiagonalMatrix()
{
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;
    vector<int> tri(3 * n - 2, 0); // 3n - 2 non-zero elements
    cout << "Enter tri-diagonal elements:\n";
    for (int i = 0; i < 3 * n - 2; i++)
        cin >> tri[i];
    cout << "Stored elements: ";
    for (int i : tri)
        cout << i << " ";
    cout << endl;
}

// (c) Lower triangular Matrix storage
void lowerTriangularMatrix()
{
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;
    vector<int> lower(n * (n + 1) / 2, 0);
    cout << "Enter lower triangular elements row-wise:\n";
    for (int i = 0; i < lower.size(); i++)
        cin >> lower[i];
    cout << "Stored elements: ";
    for (int i : lower)
        cout << i << " ";
    cout << endl;
}

// (d) Upper triangular Matrix storage
void upperTriangularMatrix()
{
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;
    vector<int> upper(n * (n + 1) / 2, 0);
    cout << "Enter upper triangular elements row-wise:\n";
    for (int i = 0; i < upper.size(); i++)
        cin >> upper[i];
    cout << "Stored elements: ";
    for (int i : upper)
        cout << i << " ";
    cout << endl;
}

// (e) Symmetric Matrix storage
void symmetricMatrix()
{
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;
    vector<int> sym(n * (n + 1) / 2, 0);
    cout << "Enter lower triangular (or upper) elements:\n";
    for (int i = 0; i < sym.size(); i++)
        cin >> sym[i];
    cout << "Stored elements: ";
    for (int i : sym)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\nSPECIAL MATRICES MENU\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            diagonalMatrix();
            break;
        case 2:
            tridiagonalMatrix();
            break;
        case 3:
            lowerTriangularMatrix();
            break;
        case 4:
            upperTriangularMatrix();
            break;
        case 5:
            symmetricMatrix();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}