#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition of a tree node
struct Node {
    int data;           // Value stored in the node
    Node* left;         // Pointer to the left child
    Node* right;        // Pointer to the right child

    // Constructor to initialize a new node with a value and null children
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    // Function to perform iterative inorder traversal of a binary tree
    vector<int> inOrder(Node* root) {
        stack<Node*> s;         // Stack to store the nodes to be visited
        stack<bool> visited;    // Stack to keep track if a node has been visited (1) or not (0)
        vector<int> ans;        // Stores the inorder traversal result

        // If tree is empty, return empty result
        if (!root) return ans;

        // Start traversal from the root node, mark as not visited
        s.push(root);
        visited.push(0);

        // Continue until all nodes are processed
        while (!s.empty()) {
            Node* temp = s.top();      // Current node to process
            s.pop();
            bool flag = visited.top(); // Visit status of current node
            visited.pop();

            if (flag == 0) {
                // If node has not been visited, process its children and itself
                // Push right child first (so it is processed after current node)
                if (temp->right) {
                    s.push(temp->right);
                    visited.push(0);   // Mark right child as not visited
                }
                // Push current node back, mark as visited for next time
                s.push(temp);
                visited.push(1);

                // Push left child last (so it's processed next)
                if (temp->left) {
                    s.push(temp->left);
                    visited.push(0);   // Mark left child as not visited
                }
            } else {
                // If node has been visited, add its data to result
                ans.push_back(temp->data);
            }
        }
        return ans;
    }
};

// Helper function to create a simple binary tree for testing
Node* createSampleTree() {
    /*   Constructed tree:
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
    Node* root = createSampleTree();     // Build a sample tree
    Solution sol;
    vector<int> inorder = sol.inOrder(root); // Get iterative inorder traversal

    cout << "Inorder Traversal: ";
    for (int val : inorder) {
        cout << val << " ";              // Output traversal result
    }
    cout << endl;

    // Free allocated memory if needed (not necessary for small test/demo)
    // ... (delete nodes if you want to avoid memory leaks in larger code)

    return 0;
}
