#include <bits/stdc++.h>

using namespace std;

#define MAX 100

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << val << endl;
            return;
        }
        arr[++top] = val;
        cout << val << " pushed to stack." << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "Top element is " << arr[top] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, val;

    cout << "\n--- Stack Menu ---\n";
    cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n";
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is Empty." : "Stack is Not Empty.") << endl;
            break;
        case 5:
            cout << (s.isFull() ? "Stack is Full." : "Stack is Not Full.") << endl;
            break;
        case 6:
            s.display();
            break;
        case 7:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
