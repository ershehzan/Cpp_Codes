#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition of a tree node
class Node
{
public:
    int data;        // Value of the node
    Node *left;      // Pointer to the left child
    Node *right;     // Pointer to the right child

    // Constructor to initialize a new node with a given value
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
    Helper function to find the leftmost and rightmost horizontal distances (HD) from the root.
    - pos: current horizontal distance from the root (root=0, left=-1, right=+1)
    - l: reference to variable tracking minimum HD (leftmost)
    - r: reference to variable tracking maximum HD (rightmost)
*/
void find(Node *root, int pos, int &l, int &r)
{
    if (!root)
        return;

    // Update the leftmost and rightmost positions
    l = min(l, pos);
    r = max(r, pos);

    // Recurse for left subtree with HD - 1
    find(root->left, pos - 1, l, r);

    // Recurse for right subtree with HD + 1
    find(root->right, pos + 1, l, r);
}

// Class to solve the vertical order traversal problem
class Solution
{
public:
    /*
        Function to perform vertical order traversal of a binary tree.
        Returns a vector of vectors, each inner vector contains node values in one vertical line.
    */
    vector<vector<int>> verticalOrder(Node *root)
    {
        int l = 0, r = 0; // Variables to store leftmost and rightmost HD
        find(root, 0, l, r); // Find the range of HDs

        // Separate vectors for negative and positive HDs
        vector<vector<int>> positive(r + 1);     // For HD >= 0
        vector<vector<int>> negative(abs(l) + 1); // For HD < 0

        queue<Node *> q;     // Queue for BFS traversal of nodes
        q.push(root);
        queue<int> index;    // Queue to store corresponding HDs
        index.push(0);

        // Standard BFS loop
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            // Store node value in appropriate vector based on HD
            if (pos >= 0)
            {
                positive[pos].push_back(temp->data);
            }
            else
            {
                negative[abs(pos)].push_back(temp->data);
            }

            // Enqueue left child with HD - 1
            if (temp->left)
            {
                q.push(temp->left);
                index.push(pos - 1);
            }
            // Enqueue right child with HD + 1
            if (temp->right)
            {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        // Combine negative and positive vectors to get the answer in left-to-right order
        vector<vector<int>> ans;
        // Add nodes from the negative side (left of root), rightmost first (i.e., most negative HD)
        for (int i = negative.size() - 1; i >= 0; i--)
        {
            if (!negative[i].empty())
                ans.push_back(negative[i]);
        }
        // Add nodes from the positive side (root and right of root)
        for (int i = 0; i < positive.size(); i++)
        {
            if (!positive[i].empty())
                ans.push_back(positive[i]);
        }
        return ans;
    }
};

// Helper function to build a sample binary tree for testing
Node *buildSampleTree()
{
    // Constructing the following tree:
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main()
{
    Node *root = buildSampleTree(); // Build the sample tree
    Solution sol;
    vector<vector<int>> result = sol.verticalOrder(root); // Get vertical order traversal

    cout << "Vertical Order Traversal:" << endl;
    // Print the result
    for (const auto &vec : result)
    {
        for (int val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
