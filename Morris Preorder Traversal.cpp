#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node{
    int data;            // Value stored in the node
    Node *left;          // Pointer to the left child
    Node *right;         // Pointer to the right child
    Node(int val) : data(val), left(nullptr), right(nullptr) {} // Constructor initializes node
};

// Solution class encapsulating the Morris Preorder Traversal algorithm
class Solution
{
public:
    // Function to perform Morris Preorder Traversal on a binary tree.
    // Returns a vector containing the preorder traversal of the tree.
    vector<int> preOrder(Node *root)
    {
        vector<int> ans; // Vector to store preorder sequence
        while (root)
        {
            // Case 1: If there is no left child, visit the node and go right
            if (!root->left)
            {
                ans.push_back(root->data); // Visit current node
                root = root->right;        // Move to right child
            }
            else
            {
                // Case 2: Find the rightmost node in the left subtree
                // (which is the inorder predecessor of root)
                Node *curr = root->left;
                while (curr->right && curr->right != root)
                    curr = curr->right;

                // If the rightmost node's right pointer is NULL, make it point to root
                // This creates a temporary thread to return to root after left subtree
                if (curr->right == NULL)
                {
                    ans.push_back(root->data); // Visit the root node (preorder: node before left)
                    curr->right = root;        // Create a thread back to root
                    root = root->left;         // Move to left child
                }
                else
                {
                    // If the thread already exists, remove it and go to right subtree
                    curr->right = NULL;        // Remove the thread
                    root = root->right;        // Move to right child
                }
            }
        }
        return ans; // Return the preorder traversal result
    }
};

// Helper function to create a sample binary tree for demonstration
Node *buildSampleTree()
{
    /*      1
           / \
          2   3
         / \
        4   5  
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main()
{
    Node *root = buildSampleTree();        // Build a sample tree
    Solution sol;                          // Create Solution object
    vector<int> preorder = sol.preOrder(root); // Obtain preorder traversal using Morris Traversal

    // Print the preorder traversal result
    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;

    // Memory clean-up can be added here if needed for larger trees
    return 0;
}

