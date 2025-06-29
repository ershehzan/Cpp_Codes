#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;           // Value stored in the node
    Node *left;         // Pointer to the left child
    Node *right;        // Pointer to the right child
    Node(int val) : data(val), left(NULL), right(NULL) {} // Constructor
};

class Solution
{
public:
    // Function to return the postorder traversal of the binary tree iteratively
    vector<int> postOrder(Node *root)
    {
        stack<Node *> s;     // Stack to help with traversal
        vector<int> ans;     // Vector to store postorder traversal result

        // If the tree is empty, return an empty vector
        if (root == NULL)
            return ans;

        s.push(root);        // Start traversal from the root node

        while (!s.empty())
        {
            Node *temp = s.top(); // Get the node on top of the stack
            s.pop();              // Remove it from the stack
            ans.push_back(temp->data); // Add its value to the result

            // Push the left child first so that the right child is processed first (since stack is LIFO)
            if (temp->left)
                s.push(temp->left);

            // Push the right child
            if (temp->right)
                s.push(temp->right);
        }
        // The above process gives us a reversed postorder (root-right-left), so we reverse it
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Helper function to create a simple binary tree for demonstration
Node *buildSampleTree()
{
    /*   Constructs the following tree:
            1
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
    Node *root = buildSampleTree(); // Build a sample tree
    Solution sol;
    vector<int> result = sol.postOrder(root); // Get postorder traversal

    cout << "Postorder Traversal: ";
    // Print the result
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Free allocated memory (not strictly necessary for small demo)
    // ... (You can add code to delete the tree if needed)

    return 0;
}
