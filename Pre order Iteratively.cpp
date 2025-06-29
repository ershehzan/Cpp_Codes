#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;               // Value stored in the node
    Node* left;             // Pointer to the left child
    Node* right;            // Pointer to the right child

    // Constructor to initialize the node with a value, and set children to nullptr
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    // Function to perform iterative preorder traversal of a binary tree.
    // Preorder: Root -> Left -> Right
    vector<int> preOrder(Node* root) {
        stack<Node*> s;        // Stack to help with the traversal
        vector<int> ans;       // Stores the preorder traversal result

        // If tree is empty, return an empty vector
        if (!root) return ans;

        // Start traversal from the root node
        s.push(root);

        // Loop until we have processed all nodes
        while (!s.empty()) {
            Node* temp = s.top(); // Get the top node on the stack
            s.pop();              // Remove it from the stack
            ans.push_back(temp->data); // Visit the node (add its value to result)

            // Push right child first so that left child is processed first (stack is LIFO)
            if (temp->right)
                s.push(temp->right);

            // Push left child
            if (temp->left)
                s.push(temp->left);
        }

        // Return the preorder traversal as a vector
        return ans;
    }
};

// Helper function to create a simple binary tree for demonstration
Node* createSampleTree() {
    /*   Constructs the following tree:
            1
           / \
          2   3
         / \
        4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main() {
    Node* root = createSampleTree();         // Build a sample tree
    Solution sol;
    vector<int> result = sol.preOrder(root); // Get preorder traversal

    cout << "Preorder Traversal: ";
    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Free allocated memory (not strictly necessary for small demo)
    // ... (free nodes if needed)

    return 0;
}
