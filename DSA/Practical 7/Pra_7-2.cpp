#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int patient;
        Node* next;
    };

    Node *front, *rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void arrive(int patient) {
        Node* newNode = new Node;
        newNode->patient = patient;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front: " << front->patient << endl;
    }

    void attend() {
        if (front == NULL) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << "Attended: " << front->patient << endl;

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;

        if (front != NULL)
            cout << "Front: " << front->patient << endl;
        else
            cout << "Front: Empty" << endl;
    }

    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    int operations;

    cout << "Enter the number of operations: ";
    cin >> operations;

    Queue q;

    for (int i = 0; i < operations; i++) {
        char operation;

        cout << "Enter operation (A for arrive, T for attend): ";
        cin >> operation;

        if (operation == 'A') {
            int patient;

            cout << "Enter patient number: ";
            cin >> patient;

            q.arrive(patient);
        }
        else if (operation == 'T') {
            q.attend();
        }
    }

    return 0;
}   