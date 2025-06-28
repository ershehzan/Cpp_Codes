#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
// Each node contains an integer value and pointers to its left and right children.
struct Node
{
    int data;           // Value stored in the node
    Node *left;         // Pointer to the left child node
    Node *right;        // Pointer to the right child node

    // Constructor to initialize the node with a value, left and right children set to NULL
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Solution class encapsulating the right view logic for a binary tree
class Solution
{
public:
    /*
        Function to return the right view of a binary tree.

        Parameter:
            - root: pointer to the root node of the tree

        Returns:
            - vector<int>: a vector containing the node values visible from the right side view
    */
    vector<int> rightView(Node *root)
    {
        vector<int> ans;            // Stores the result (right view nodes)
        if (root == NULL)
            return ans;             // Return empty if the tree is empty

        queue<Node *> q;            // Queue for level-order traversal (BFS)
        q.push(root);               // Start BFS from the root

        while (!q.empty())
        {
            // The first node in the queue at each level is the rightmost node (due to push order)
            ans.push_back(q.front()->data);

            int n = q.size();       // Number of nodes at the current level

            // Traverse all nodes at the current level
            while (n--)
            {
                Node *temp = q.front();
                q.pop();

                // IMPORTANT: Push right child before left child so that
                // rightmost nodes are processed first at the next level.
                if (temp->right)
                    q.push(temp->right);

                if (temp->left)
                    q.push(temp->left);
            }
        }
        return ans;
    }
};

// Helper function to build a sample binary tree for demonstration/testing
Node *buildSampleTree()
{
    // Tree structure:
    //      1
    //     / \
    //    2   3
    //     \   \
    //      5   4
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    return root;
}

int main()
{
    Node *root = buildSampleTree();          // Build the sample tree
    Solution sol;                            // Create Solution object
    vector<int> right_view = sol.rightView(root); // Get the right view

    cout << "Right view of the binary tree: ";
    for (int val : right_view)
    {
        cout << val << " ";                  // Output each value in the right view
    }
    cout << endl;

    // Free allocated memory if needed (not strictly necessary for this demo)

    return 0;
}
