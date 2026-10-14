#include <iostream>
using namespace std;

const int SHELVES = 10;

struct Node {
    int code;
    Node *next;
    Node(int value) : code(value), next(NULL) {}
};

void addBook(Node *shelves[], int code) {
    int shelf = code % SHELVES;
    if (shelf < 0) shelf += SHELVES;

    Node *book = new Node(code);
    if (shelves[shelf] == NULL) {
        shelves[shelf] = book;
    } else {
        Node *current = shelves[shelf];
        while (current->next != NULL) current = current->next;
        current->next = book;
    }
}

int main() {
    Node *shelves[SHELVES];
    for (int i = 0; i < SHELVES; i++) shelves[i] = NULL;

    int count;
    cout << "Enter number of books: ";
    cin >> count;

    cout << "Enter the book codes: ";
    for (int i = 0; i < count; i++) {
        int code;
        cin >> code;
        addBook(shelves, code);
    }

    cout << "Final shelves:" << endl;
    int longest = 0;
    for (int i = 0; i < SHELVES; i++) {
        cout << "Shelf " << i << ": ";
        int length = 0;
        if (shelves[i] == NULL) cout << "Empty";
        for (Node *current = shelves[i]; current != NULL; current = current->next) {
            cout << current->code;
            if (current->next != NULL) cout << " -> ";
            length++;
        }
        cout << endl;
        if (length > longest) longest = length;
    }
    cout << "Longest shelf holds " << longest << " book(s)." << endl;

    for (int i = 0; i < SHELVES; i++) {
        Node *current = shelves[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    return 0;
}
