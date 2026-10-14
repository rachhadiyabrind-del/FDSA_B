#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

Node *buildTree(const vector<int> &values)
{
    if (values.empty() || values[0] == -1)
        return NULL;

    Node *root = new Node(values[0]);
    queue<Node *> pending;
    pending.push(root);

    size_t i = 1;
    while (!pending.empty() && i < values.size())
    {
        Node *current = pending.front();
        pending.pop();

        if (i < values.size() && values[i] != -1)
        {
            current->left = new Node(values[i]);
            pending.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1)
        {
            current->right = new Node(values[i]);
            pending.push(current->right);
        }
        i++;
    }
    return root;
}

void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> line;
    line.push(root);
    while (!line.empty())
    {
        Node *current = line.front();
        line.pop();
        cout << current->data << " ";
        if (current->left)
            line.push(current->left);
        if (current->right)
            line.push(current->right);
    }
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
    cout << "Enter number of entries in level-order input (use -1 for no node): ";
    cin >> count;

    vector<int> values(count);
    cout << "Enter the " << count << " values: ";
    for (int i = 0; i < count; i++)
        cin >> values[i];

    Node *root = buildTree(values);

    if (root == NULL)
    {
        cout << "Tree is empty. Nothing to print." << endl;
        return 0;
    }

    cout << "Inorder   (HR)      : ";
    inorder(root);
    cout << endl;
    cout << "Preorder  (Archive) : ";
    preorder(root);
    cout << endl;
    cout << "Postorder (Payroll) : ";
    postorder(root);
    cout << endl;
    cout << "Level order (Floor) : ";
    levelOrder(root);
    cout << endl;

    destroyTree(root);
    return 0;
}
