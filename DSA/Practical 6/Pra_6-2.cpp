#include <iostream>
using namespace std;

class Stack
{
    struct Node
    {
        string page;
        Node *next;
    };
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void visit()
    {
        string page;
        cout << "Enter page: ";
        cin >> page;
        Node *newNode = new Node;
        newNode->page = page;
        newNode->next = top;
        top = newNode;
        cout << "Page Visited\n";
    }
    void back()
    {
        if (top == NULL)
        {
            cout << "No History Available\n";
            return;
        }
        Node *temp = top;
        cout << "Going Back From: " << top->page << endl;
        top = top->next;
        delete temp;
        if (top == NULL)
            cout << "No Previous Page\n";
        else
            cout << "Current Page: " << top->page << endl;
    }
    void current()
    {
        if (top == NULL)
            cout << "No Page Available\n";
        else
            cout << "Current Page: " << top->page << endl;
    }
};
int main()
{
    Stack s;
    int choice;
    do
    {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Current Page";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.visit();
            break;
        case 2:
            s.back();
            break;
        case 3:
            s.current();
            break;
        case 4:
            cout << "Program Ended\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}