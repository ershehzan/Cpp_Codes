#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node{
    int data;           // Value stored in the node
    Node *left;         // Pointer to the left child
    Node *right;        // Pointer to the right child
    Node(int val) : data(val), left(NULL), right(NULL) {} // Constructor to initialize node
};

// Solution class containing the flatten method
class Solution{
public:
    // Function to flatten the binary tree into a linked list in-place
    void flatten(Node *root){
        // Traverse the tree starting from the root
        while (root)
        {
            // If there is no left subtree, move to the right subtree
            if (!root->left)
                root = root->right;
            else
            {
                // Find the rightmost node in the left subtree
                Node *curr = root->left;
                while (curr->right)
                    curr = curr->right;
                // Rewire the rightmost node's right pointer to point to the current root's right subtree
                curr->right = root->right;
                // Move the left subtree to the right, and set left to NULL
                root->right = root->left;
                root->left = NULL;
                // Move to the next right node
                root = root->right;
            }
        }
    }
};

// Helper function to print the flattened tree as a right-skewed linked list
void printRightLinkedList(Node *root){
    while (root)
    {
        cout << root->data << " "; // Print current node's data
        root = root->right;        // Move to the next node in the linked list
    }
    cout << endl;
}

int main()
{
    /* Example: Constructing the following binary tree
          1
         / \
        2   5
       / \   \
      3   4   6
    */

    // Construct the binary tree nodes
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Solution sol;          // Create an instance of Solution
    sol.flatten(root);     // Flatten the tree

    // Print the flattened tree
    printRightLinkedList(root);

    // Note: Memory cleanup is omitted for brevity. In a real program, delete all nodes to avoid memory leaks.

    return 0;
}




