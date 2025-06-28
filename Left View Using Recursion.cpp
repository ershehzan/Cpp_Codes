#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;           // Value stored in the node
    Node *left;         // Pointer to the left child
    Node *right;        // Pointer to the right child
    Node(int x)
    {
        data = x;
        left = right = NULL; // Initialize left and right children as NULL
    }
};

/*
    Recursive helper function to compute the left view of the tree.

    Parameters:
    - root: pointer to the current node
    - level: current level in the tree (root is level 0)
    - ans: vector to store the leftmost node at each level

    Logic:
    - If the current node is NULL, return (base case).
    - If this is the first time visiting this level (ans.size() == level),
      add the node's data to ans (this ensures only the leftmost node at each level is added).
    - Recurse first on the left child, then on the right child (to ensure leftmost nodes are visited first).
*/
void lv(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (level == static_cast<int>(ans.size()))
        ans.push_back(root->data); // Add the first node encountered at this level to the answer
    lv(root->left, level + 1, ans);  // Recurse on left subtree
    lv(root->right, level + 1, ans); // Recurse on right subtree
}

// Solution class encapsulates the logic for finding the left view
class Solution
{
public:
    /*
        Function to get the left view of a binary tree.

        Parameter:
        - root: pointer to the root of the tree

        Returns:
        - A vector containing the left view of the tree
    */
    vector<int> leftView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans; // If tree is empty, return empty vector
        lv(root, 0, ans); // Start recursion from level 0
        return ans;
    }
};

/*
    Utility function to build a simple binary tree from user input in level order.

    Returns:
    - Pointer to the root of the constructed binary tree

    Logic:
    - Reads number of nodes.
    - Reads node values (use -1 for NULL).
    - Constructs nodes and assigns left/right children according to level order.
*/
Node *buildTree()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n == 0)
        return NULL;
    vector<Node *> nodes(n, NULL);
    cout << "Enter node values (use -1 for NULL): ";
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        if (val != -1)
            nodes[i] = new Node(val); // Create node if value is not -1
    }
    // Assign left and right children for each node in level order
    for (int i = 0, j = 1; j < n; ++i)
    {
        if (nodes[i])
        {
            if (j < n)
                nodes[i]->left = nodes[j++]; // Assign left child
            if (j < n)
                nodes[i]->right = nodes[j++]; // Assign right child
        }
    }
    return nodes[0]; // Return root node
}

int main()
{
    Node *root = buildTree(); // Build the tree from user input
    Solution solution;
    vector<int> result = solution.leftView(root); // Get the left view of the tree
    cout << "Left view of the tree: ";
    for (int x : result)
    {
        cout << x << " "; // Print each element of the left view
    }
    cout << endl;
    return 0;
}
