#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;         // Data stored in the node
    Node *left;       // Pointer to the left child
    Node *right;      // Pointer to the right child

    // Constructor to initialize the node with data
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Helper function to traverse the tree in preorder and calculate the sum of all nodes.
// Parameters:
//   sum  - reference to the variable holding the cumulative sum
//   root - pointer to the current node
void pre(int &sum, Node *root)
{
    if (root == NULL)        // Base case: if node is null, do nothing
        return;
    sum += root->data;       // Add current node's data to sum
    pre(sum, root->left);    // Recursively add left subtree
    pre(sum, root->right);   // Recursively add right subtree
}

// Solution class containing the method to calculate the sum of all nodes in the tree.
class Solution
{
public:
    // Returns the sum of all nodes in the binary tree rooted at 'root'.
    int sumBT(Node *root)
    {
        int sum = 0;
        pre(sum, root);      // Use helper function to compute sum
        return sum;
    }
};

int main()
{
    // Construct a sample Binary Search Tree:
    //         10
    //        /  \
    //       5    15
    //      / \     \
    //     2   7     20

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    Solution sol;
    int sum = sol.sumBT(root);   // Calculate sum of all nodes
    cout << "Sum of all nodes in BST: " << sum << endl;

    // Free allocated memory to avoid memory leaks
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
