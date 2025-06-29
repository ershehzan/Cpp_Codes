#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        stack<Node *> s;
        vector<int> ans;
        if (root == NULL)
            return ans;
        s.push(root);

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            ans.push_back(temp->data);

            if (temp->left)
                s.push(temp->left);

            if (temp->right)
                s.push(temp->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Helper function to create a simple binary tree for demonstration
Node *buildSampleTree()
{
    /*   1
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
    vector<int> result = sol.postOrder(root);

    cout << "Postorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Free allocated memory (not strictly necessary for small demo)
    // ... (You can add code to delete the tree if needed)

    return 0;
}