#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Solution class as provided
class Solution
{
public:
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            ans.push_back(q.front()->data);
            int n = q.size();

            while (n--)
            {
                Node *temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};

// Helper function to build a simple binary tree for demonstration
Node *buildSampleTree()
{
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
    Node *root = buildSampleTree();
    Solution sol;
    vector<int> right_view = sol.rightView(root);

    cout << "Right view of the binary tree: ";
    for (int val : right_view)
    {
        cout << val << " ";
    }
    cout << endl;

    // Free allocated memory (not strictly necessary for small demo)
    // ... (free nodes if needed)

    return 0;
}