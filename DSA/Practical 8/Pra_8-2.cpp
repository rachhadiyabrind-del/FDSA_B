#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int code;
    Node *left;
    Node *right;
    Node(int value) : code(value), left(NULL), right(NULL) {}
};

bool insertCode(Node *&root, int code)
{
    if (root == NULL)
    {
        root = new Node(code);
        return true;
    }
    Node *current = root;
    while (true)
    {
        if (code == current->code)
            return false;
        if (code < current->code)
        {
            if (current->left == NULL)
            {
                current->left = new Node(code);
                return true;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = new Node(code);
                return true;
            }
            current = current->right;
        }
    }
}

void inorder(Node *node, vector<int> &result)
{
    if (node == NULL)
        return;
    inorder(node->left, result);
    result.push_back(node->code);
    inorder(node->right, result);
}

void destroyTree(Node *node)
{
    if (node == NULL)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

int main()
{
    int count;
    cout << "Enter number of book codes: ";
    cin >> count;

    Node *root = NULL;
    cout << "Enter the book codes: ";
    for (int i = 0; i < count; i++)
    {
        int code;
        cin >> code;
        if (!insertCode(root, code))
            cout << "Duplicate code " << code << " ignored." << endl;
    }

    vector<int> sequence;
    inorder(root, sequence);

    cout << "Inorder sequence: ";
    if (sequence.empty())
        cout << "(empty)";
    for (size_t i = 0; i < sequence.size(); i++)
        cout << sequence[i] << " ";
    cout << endl;

    bool sorted = true;
    for (size_t i = 1; i < sequence.size(); i++)
        if (sequence[i - 1] >= sequence[i])
            sorted = false;
    cout << "Inorder is sorted: " << (sorted ? "Yes" : "No") << endl;

    destroyTree(root);
    return 0;
}
