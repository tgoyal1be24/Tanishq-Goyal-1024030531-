/*6) Write a program to implement the following operations on a Sparse Matrix, assuming the matrix
is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.*/
#include <iostream>
#include <vector>
using namespace std;

struct Term
{
    int row, col, val;
};

// Display triplet
void display(const vector<Term> &t)
{
    cout << "Row Col Val\n";
    for (auto &x : t)
        cout << x.row << " " << x.col << " " << x.val << "\n";
}

// (a) Transpose
vector<Term> transpose(const vector<Term> &a)
{
    vector<Term> b;
    b.push_back({a[0].col, a[0].row, a[0].val}); // header
    for (int c = 0; c < a[0].col; c++)
        for (int i = 1; i <= a[0].val; i++)
            if (a[i].col == c)
                b.push_back({a[i].col, a[i].row, a[i].val});
    return b;
}

// (b) Addition
vector<Term> add(const vector<Term> &a, const vector<Term> &b)
{
    if (a[0].row != b[0].row || a[0].col != b[0].col)
    {
        cout << "Addition not possible!\n";
        return {};
    }
    vector<Term> c;
    c.push_back({a[0].row, a[0].col, 0});
    int i = 1, j = 1;
    while (i <= a[0].val && j <= b[0].val)
    {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col))
            c.push_back(a[i++]);
        else if (b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col))
            c.push_back(b[j++]);
        else
        {
            c.push_back({a[i].row, a[i].col, a[i].val + b[j].val});
            i++;
            j++;
        }
    }
    while (i <= a[0].val)
        c.push_back(a[i++]);
    // while (j <= b[0].val)
    c.push_back(b[j++]);
    c[0].val = c.size() - 1;
    return c;
}

// (c) Multiplication
vector<Term> multiply(const vector<Term> &a, const vector<Term> &b)
{
    if (a[0].col != b[0].row)
    {
        cout << "Multiplication not possible!\n";
        return {};
    }
    vector<Term> bt = transpose(b), c;
    c.push_back({a[0].row, b[0].col, 0});
    for (int i = 1; i <= a[0].val; i++)
    {
        for (int j = 1; j <= bt[0].val; j++)
        {
            if (a[i].col == bt[j].col)
            {
                int r = a[i].row, col = bt[j].row, sum = a[i].val * bt[j].val;
                bool found = false;
                for (int k = 1; k < c.size(); k++)
                    if (c[k].row == r && c[k].col == col)
                    {
                        c[k].val += sum;
                        found = true;
                        break;
                    }
                if (!found)
                    c.push_back({r, col, sum});
            }
        }
    }
    c[0].val = c.size() - 1;
    return c;
}

// ----------------- MAIN -----------------
int main()
{
    vector<Term> A, B, T, C;

    int r, c, n;
    cout << "Enter rows, cols, non-zero count of A: ";
    cin >> r >> c >> n;
    A.push_back({r, c, n});
    cout << "Enter triplets (row col val):\n";
    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        A.push_back({x, y, v});
    }

    cout << "Enter rows, cols, non-zero count of B: ";
    cin >> r >> c >> n;
    B.push_back({r, c, n});
    cout << "Enter triplets (row col val):\n";
    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        B.push_back({x, y, v});
    }

    // Transpose
    T = transpose(A);
    cout << "\nTranspose of A:\n";
    display(T);

    // Addition
    C = add(A, B);
    if (!C.empty())
    {
        cout << "\nAddition (A + B):\n";
        display(C);
    }

    // Multiplication
    C = multiply(A, B);
    if (!C.empty())
    {
        cout << "\nMultiplication (A * B):\n";
        display(C);
    }

    return 0;
}
