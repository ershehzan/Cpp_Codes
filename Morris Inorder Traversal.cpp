#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct Node{
    int data;          // Value stored in the node
    Node *left;        // Pointer to the left child
    Node *right;       // Pointer to the right child
    Node(int val) : data(val), left(nullptr), right(nullptr) {} // Constructor to initialize node
};

// Solution class with Morris Inorder Traversal
class Solution{
public:
    // Function to perform Morris Inorder Traversal on a binary tree.
    // Returns a vector containing the inorder traversal of the tree.
    vector<int> inOrder(Node *root)
    {
        vector<int> ans; // This will store the inorder sequence
        while (root)
        {
            // If there is no left child, visit this node and go right
            if (!root->left)
            {
                ans.push_back(root->data); // Visit the current node
                root = root->right;        // Move to the right child
            }
            else{
                // Find the rightmost node in the left subtree or the inorder predecessor of root
                Node *curr = root->left;
                while (curr->right && curr->right != root)
                    curr = curr->right;

                // If the rightmost node's right pointer is null, make it point to root (threading)
                if (curr->right == NULL)
                {
                    curr->right = root;    // Create a temporary thread to root
                    root = root->left;     // Move root to left child to continue traversal
                }
                else
                {
                    // If the thread already exists, break it and visit the node
                    curr->right = NULL;    // Remove the thread
                    ans.push_back(root->data); // Visit the root node
                    root = root->right;         // Move to the right child
                }
            }
        }
        return ans; // Return the inorder traversal
    }
};

// Helper function to create a simple binary tree for demonstration
Node *buildSampleTree(){
    
    /*     1
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
    Node *root = buildSampleTree();  // Build a sample tree
    Solution sol;                    // Create Solution object
    vector<int> inorder = sol.inOrder(root); // Get inorder traversal using Morris Traversal

    cout << "Morris Inorder Traversal: ";
    for (int val : inorder)
    {
        cout << val << " "; // Print each node's value in inorder
    }
    cout << endl;

    // Free allocated memory (not strictly necessary for small demo)
    // ... (tree deletion code can be added if needed)

    return 0;
}






