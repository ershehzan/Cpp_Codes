#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
// Each node contains an integer value and pointers to left and right children.
struct Node
{
    int data;       // Value stored in the node
    Node *left;     // Pointer to the left child node
    Node *right;    // Pointer to the right child node

    // Constructor to initialize the node with a given value
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/*
    Recursive helper function to compute the right view of the tree.

    Parameters:
    - root: pointer to the current node being processed
    - level: current level in the tree (root is level 0)
    - ans: vector to store the rightmost node at each level

    Logic:
    - If the current node is NULL, return (base case).
    - If this is the first time visiting this level (ans.size() == level),
      add the node's data to ans (this ensures only the rightmost node at each level is added).
    - Recurse first on the right child, then on the left child (to ensure rightmost nodes are visited first).
*/
void rv(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    // If visiting this level for the first time, add the node's value
    if (level == static_cast<int>(ans.size()))
        ans.push_back(root->data);
    // Visit right subtree first to ensure rightmost nodes are considered first
    rv(root->right, level + 1, ans);
    // Then visit left subtree
    rv(root->left, level + 1, ans);
}

// Solution class encapsulates the logic for finding the right view
class Solution
{
public:
    /*
        Function to get the right view of a binary tree.

        Parameter:
        - root: pointer to the root node of the tree

        Returns:
        - A vector containing the right view (rightmost node at each level)
    */
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans; // If tree is empty, return empty vector
        rv(root, 0, ans); // Start recursion from level 0
        return ans;
    }
};

/*
    Example main function demonstrating usage.

    Builds the following binary tree:
           1
          / \
         2   3
          \   \
           5   4

    The right view would be: 1 3 4
*/
int main()
{
    // Create sample tree nodes
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    // Create Solution object and compute right view
    Solution sol;
    vector<int> result = sol.rightView(root);

    cout << "Right view of the binary tree: ";
    for (int val : result)
    {
        cout << val << " "; // Print each value in the right view
    }
    cout << endl;

    // Memory cleanup omitted for brevity

    return 0;
}
