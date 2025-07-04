#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Solution class as provided
class Solution
{
public:
    void flatten(Node *root)
    {
        while (root)
        {
            if (!root->left)
                root = root->right;
            else
            {
                Node *curr = root->left;
                while (curr->right)
                    curr = curr->right;
                curr->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};

// Helper function to print the flattened tree
void printRightLinkedList(Node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main()
{
    /* Example: Constructing the following tree
          1
         / \
        2   5
       / \   \
      3   4   6*/

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Solution sol;
    sol.flatten(root);

    // Print the flattened tree
    printRightLinkedList(root);

    // Free memory (not strictly necessary for short-lived programs)
    // In practice, you'd want to delete all nodes.

    return 0;
}