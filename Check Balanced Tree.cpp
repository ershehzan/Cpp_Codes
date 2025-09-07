#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Binary tree node structure
class Node {
    public:
        int data;      // Value stored in the node
        Node* left;    // Pointer to the left child
        Node* right;   // Pointer to the right child

        // Constructor to initialize node with a value
        Node(int val) {
                data = val;
                left = NULL;
                right = NULL;
        }
};

// Helper function to compute the height of the tree and check if it's balanced
// Returns the height of the subtree rooted at 'root'
// Sets 'valid' to false if the tree is found unbalanced at any node
int h(Node* root, bool &valid) {
        if (!root)
                return 0; // Base case: empty subtree has height 0

        // Recursively compute the height of left and right subtrees
        int l = h(root->left, valid);
        int r = h(root->right, valid);

        // If the height difference is more than 1, it's not balanced
        if (abs(l - r) > 1)
                valid = 0;

        // Return height of current subtree
        return 1 + max(l, r);
}

class Solution {
    public:
        // Main function to check if a binary tree is balanced
        bool isBalanced(Node* root) {
                bool valid = 1;    // Assume tree is balanced initially
                h(root, valid);    // Check balance and compute height
                return valid;      // Return result
        }
};

int main() {
        // Example 1: create a balanced binary tree
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);

        Solution sol;
        if (sol.isBalanced(root))
                cout << "Tree is balanced" << endl;
        else
                cout << "Tree is not balanced" << endl;

        // Example 2: create an unbalanced binary tree
        Node* root2 = new Node(1);
        root2->left = new Node(2);
        root2->left->left = new Node(3);

        if (sol.isBalanced(root2)){
                cout << "Tree is balanced" << endl;
        }
        else{
                cout << "Tree is not balanced" << endl;
        }
        // Note: In a real program, you should delete the allocated nodes to avoid memory leaks.
        // For simplicity, this example omits manual deletion.

        return 0;
}




