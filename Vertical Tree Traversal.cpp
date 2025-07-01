#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void find(Node *root, int pos, int &l, int &r)
{
    if (!root)
        return;

    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}

class Solution
{
public:
    vector<vector<int>> verticalOrder(Node *root)
    {
        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);

        queue<Node *> q;
        q.push(root);
        queue<int> index;
        index.push(0);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            if (pos >= 0)
            {
                positive[pos].push_back(temp->data);
            }
            else
            {
                negative[abs(pos)].push_back(temp->data);
            }

            if (temp->left)
            {
                q.push(temp->left);
                index.push(pos - 1);
            }
            if (temp->right)
            {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        vector<vector<int>> ans;
        for (int i = negative.size() - 1; i >= 0; i--)
        {
            if (!negative[i].empty())
                ans.push_back(negative[i]);
        }
        for (int i = 0; i < positive.size(); i++)
        {
            if (!positive[i].empty())
                ans.push_back(positive[i]);
        }
        return ans;
    }
};

// Helper function to build a simple binary tree for testing
Node *buildSampleTree()
{
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
    Node *root = buildSampleTree();
    Solution sol;
    vector<vector<int>> result = sol.verticalOrder(root);

    cout << "Vertical Order Traversal:" << endl;
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