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

// Solution class with Morris Inorder Traversal
class Solution
{
public:
    vector<int> inOrder(Node *root)
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
                    curr->right = root;
                    root = root->left;
                }
                else
                {
                    curr->right = NULL;
                    ans.push_back(root->data);
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
     /*     1
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
    vector<int> inorder = sol.inOrder(root);

    cout << "Morris Inorder Traversal: ";
    for (int val : inorder)
    {
        cout << val << " ";
    }
    cout << endl;

    // Free allocated memory (not strictly necessary for small demo)
    // ... (tree deletion code can be added if needed)

    return 0;
}