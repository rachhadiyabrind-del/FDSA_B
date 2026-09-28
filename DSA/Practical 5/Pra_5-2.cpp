#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *next;

    Node(string n)
    {
        name = n;
        next = NULL;
    }
};

class CircularList
{
    Node *last;

public:
    CircularList()
    {
        last = NULL;
    }

    void join(string name)
    {
        Node *newNode = new Node(name);

        if (last == NULL)
        {
            last = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }

        display();
    }

    void leave(string name)
    {
        if (last == NULL)
        {
            cout << "Circle is empty" << endl;
            return;
        }

        Node *current = last->next;
        Node *previous = last;

        do
        {
            if (current->name == name)
            {

                if (current == last && current->next == last)
                {
                    last = NULL;
                }
                else
                {
                    previous->next = current->next;

                    if (current == last)
                        last = previous;
                }

                delete current;
                display();
                return;
            }

            previous = current;
            current = current->next;

        } while (current != last->next);

        cout << "Student not found" << endl;
        display();
    }

    void display()
    {
        if (last == NULL)
        {
            cout << "Circle: Empty" << endl;
            return;
        }

        Node *temp = last->next;

        cout << "Circle: ";

        do
        {
            cout << temp->name << "";
            temp = temp->next;
        } while (temp != last->next);

        cout << endl;
    }
};

int main()
{
    CircularList c;

    int choice;
    string name;

    do
    {
        cout << "\n1. Join";
        cout << "\n2. Leave";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter student name: ";
            cin >> name;
            c.join(name);
            break;

        case 2:
            cout << "Enter student name: ";
            cin >> name;
            c.leave(name);
            break;

        case 3:
            c.display();
            break;

        case 4:
            cout << "Program ended";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}