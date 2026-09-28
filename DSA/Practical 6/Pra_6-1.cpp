#include <iostream>
using namespace std;

class Stack
{
    int a[50];
    int top, size;

public:
    Stack()
    {
        top = -1;
    }
    void create()
    {
        cout << "Enter size: ";
        cin >> size;
    }
    void push()
    {
        int x;
        if (top == size - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        cout << "Enter value: ";
        cin >> x;
        top++;
        a[top] = x;
        cout << "Inserted successfully\n";
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Deleted: " << a[top] << endl;
        top--;
    }
    void peek()
    {
        if (top == -1)
            cout << "Stack is Empty\n";
        else
            cout << "Top: " << a[top] << endl;
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << a[i] << " ";

        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice;
    s.create();
    do
    {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Program Ended\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 5);
    return 0;
}