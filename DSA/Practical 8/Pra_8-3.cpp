#include <iostream>
using namespace std;

struct Node
{
    int score;
    Node *left;
    Node *right;
    Node(int value) : score(value), left(NULL), right(NULL) {}
};

void insertScore(Node *&root, int score)
{
    if (root == NULL)
    {
        root = new Node(score);
        return;
    }
    if (score < root->score)
        insertScore(root->left, score);
    else if (score > root->score)
        insertScore(root->right, score);
}

void kthSmallest(Node *node, int k, int &visited, int &answer, bool &found)
{
    if (node == NULL || found)
        return;
    kthSmallest(node->left, k, visited, answer, found);
    if (found)
        return;
    visited++;
    if (visited == k)
    {
        answer = node->score;
        found = true;
        return;
    }
    kthSmallest(node->right, k, visited, answer, found);
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
    int count, k;
    cout << "Enter number of scores: ";
    cin >> count;

    Node *root = NULL;
    cout << "Enter the scores: ";
    for (int i = 0; i < count; i++)
    {
        int score;
        cin >> score;
        insertScore(root, score);
    }

    cout << "Enter k: ";
    cin >> k;

    int visited = 0, answer = 0;
    bool found = false;
    if (k >= 1)
        kthSmallest(root, k, visited, answer, found);

    if (found)
        cout << "Score ranked k = " << k << " from the bottom: " << answer << endl;
    else
        cout << "Error: k is out of range (tree has fewer than " << k << " nodes)" << endl;

    destroyTree(root);
    return 0;
}
