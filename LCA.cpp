#include <iostream>
using namespace std;

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert function to build BST
Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

class Solution
{
public:
    Node *LCA(Node *root, Node *n1, Node *n2)
    {
        if (!root)
            return NULL;

        if (root->data > n1->data && root->data > n2->data)
            return LCA(root->left, n1, n2);
        else if (root->data < n1->data && root->data < n2->data)
            return LCA(root->right, n1, n2);
        else
            return root;
    }
};

int main()
{
    // Create a sample BST
    Node *root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    Node *n1 = root->left->left;  // Node with value 4
    Node *n2 = root->left->right; // Node with value 12

    Solution sol;
    Node *lca = sol.LCA(root, n1, n2);

    if (lca)
        cout << "LCA of " << n1->data << " and " << n2->data << " is: " << lca->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
