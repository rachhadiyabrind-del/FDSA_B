#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    Queue(int n) {
        capacity = n;
        arr = new int[n];
        front = -1;
        rear = -1;
        size = 0;
    }

    void join(int token) {
        if (size == capacity) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        size++;

        cout << "Front: " << arr[front] << endl;
    }

    void serve() {
        if (size == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << "Served: " << arr[front] << endl;

        if (size == 1) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;

        if (size > 0)
            cout << "Front: " << arr[front] << endl;
        else
            cout << "Front: Empty" << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int n, operations;
    cout << "Enter the size of the queue: ";
    cin >> n;
    cout << "Enter the number of operations: ";
    cin >> operations;

    Queue q(n);

    for (int i = 0; i < operations; i++) {
        char operation;
        cout << "Enter operation (J for join, S for serve): ";
        cin >> operation;

        if (operation == 'J') {
            int token;
            cout << "Enter token to join: ";
            cin >> token;
            q.join(token);
        }
        else if (operation == 'S') {
            q.serve();
        }
    }

    return 0;
}