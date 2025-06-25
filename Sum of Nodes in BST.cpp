#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void pre(int &sum, Node *root)
{
    if (root == NULL)
        return;
    sum += root->data;
    pre(sum, root->left);
    pre(sum, root->right);
}

class Solution
{
public:
    int sumBT(Node *root)
    {
        int sum = 0;
        pre(sum, root);
        return sum;
    }
};

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    Solution sol;
    int sum = sol.sumBT(root);
    cout << "Sum of all nodes in BST: " << sum << endl;

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}