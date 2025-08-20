#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct Node
{
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child
    Node(int x) : data(x), left(NULL), right(NULL) {} // Constructor
};

// Helper function to determine the maximum diagonal depth in the tree.
// pos: current diagonal index
// l: reference to the maximum diagonal index found so far
void find(Node* root, int pos, int &l) 
{
    if (!root)
        return;
    l = max(pos, l);                    // Update maximum diagonal if needed
    find(root->left, pos + 1, l);       // Left child increases diagonal index
    find(root->right, pos, l);          // Right child stays on same diagonal
}

// Helper function to collect nodes on each diagonal.
// pos: current diagonal index
// ans: vector of vectors to store nodes at each diagonal
void dig(Node* root, int pos, vector<vector<int>>& ans) 
{
    if (!root)
        return;
    ans[pos].push_back(root->data);     // Place node's data in its diagonal group
    dig(root->left, pos + 1, ans);      // Left child is on next diagonal
    dig(root->right, pos, ans);         // Right child is on same diagonal
}

class Solution 
{
  public:
    // Main function to return the diagonal traversal of a binary tree.
    vector<int> diagonal(Node *root) {
        int l = 0;                          // Maximum diagonal index
        find(root, 0, l);                   // Find the max diagonal depth
        vector<vector<int>> ans(l + 1);     // Prepare storage for each diagonal
        dig(root, 0, ans);                  // Fill diagonals with node values
        vector<int> temp;                   // Store final traversal result
        for (size_t i = 0; i < ans.size(); i++) {
            for (size_t j = 0; j < ans[i].size(); j++) {
                temp.push_back(ans[i][j]);  // Flatten diagonals into one list
            }
        }
        return temp;                        // Return diagonal traversal order
    }
};

// Utility function to build a binary tree from level-order input.
// Returns pointer to root of the tree.
Node* buildTree()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n == 0) return NULL;
    vector<Node*> nodes(n, NULL);
    cout << "Enter node values (use -1 for NULL): ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val != -1)
            nodes[i] = new Node(val);   // Create node if value is not -1
    }
    // Link children based on level order
    for (int i = 0, j = 1; j < n; ++i) {
        if (nodes[i]) {
            if (j < n) nodes[i]->left = nodes[j++];   // Assign left child
            if (j < n) nodes[i]->right = nodes[j++];  // Assign right child
        }
    }
    return nodes[0];    // Return root node
}

int main() {
    Node* root = buildTree();                // Build the tree from user input
    Solution solution;
    vector<int> result = solution.diagonal(root); // Get diagonal traversal
    cout << "Diagonal Traversal: ";
    for (int x : result) {
        cout << x << " ";                    // Print the traversal
    }
    cout << endl;
    return 0;
}






