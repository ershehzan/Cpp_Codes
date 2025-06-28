#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;            // Value stored in the node
    Node *left;          // Pointer to the left child
    Node *right;         // Pointer to the right child
    Node(int x) : data(x), left(NULL), right(NULL) {} // Constructor initializes data and sets children to NULL
};

/*
    Solution class containing the method to compute the right view of a binary tree.
    The right view contains the set of nodes visible when the tree is viewed from the right side.
*/
class Solution
{
public:
    /*
        Function to return the right view of a binary tree.

        Parameter:
            - root: pointer to the root node of the tree

        Returns:
            - vector<int> containing the node values visible from the right view
    */
    vector<int> rightView(Node *root)
    {
        vector<int> ans;           // Stores the result (right view nodes)
        if (root == NULL)
            return ans;            // Return empty if tree is empty

        queue<Node *> q;           // Queue for level-order traversal (BFS)
        q.push(root);              // Start from the root

        while (!q.empty())
        {
            ans.push_back(q.front()->data); // Add the first node at this level (rightmost due to queue order)

            int n = q.size();      // Number of nodes at current level

            while (n--)
            {
                Node *temp = q.front();
                q.pop();

                // Push left child first, then right child.
                // Due to queue order, the rightmost node at this level will be at the front in the next iteration.
                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};

/*
    Helper function to build a simple binary tree for demonstration purposes.

    Structure built:
           1
          / \
         2   3
          \   \
           5   4

    Returns:
        - Pointer to the root of the constructed tree.
*/
Node *buildSampleTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    return root;
}

int main()
{
    Node *root = buildSampleTree();           // Build the sample tree
    Solution sol;                             // Create Solution object
    vector<int> right_view = sol.rightView(root); // Get the right view

    cout << "Right view of the binary tree: ";
    for (int val : right_view)
    {
        cout << val << " ";                   // Output each value in the right view
    }
    cout << endl;

    // Free allocated memory (not strictly necessary for small demo)
    // ... (free nodes if needed)

    return 0;
}
