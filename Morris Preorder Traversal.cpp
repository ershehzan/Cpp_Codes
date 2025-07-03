#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        vector<int> ans;
        while (root)
        {
            if (!root->left)
            {
                ans.push_back(root->data);
                root = root->right;
            }
            else
            {
                Node *curr = root->left;
                while (curr->right && curr->right != root)
                    curr = curr->right;
                if (curr->right == NULL)
                {
                    ans.push_back(root->data);
                    curr->right = root;
                    root = root->left;
                }
                else
                {
                    curr->right = NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};

// Helper function to create a simple binary tree for demonstration
Node *buildSampleTree()
{
    /*      1
           / \
          2   3
         / \
        4   5  */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main()
{
    Node *root = buildSampleTree();
    Solution sol;
    vector<int> preorder = sol.preOrder(root);
    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;
    // Clean up memory (not strictly necessary for small demo)
    // ... (free nodes if needed)
    return 0;
}