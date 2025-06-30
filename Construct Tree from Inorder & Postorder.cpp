#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Tree node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int search(vector<int> &arr, int target, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

class Solution
{
public:
    Node *tree(vector<int> &inorder, vector<int> &postorder, int start, int end, int index)
    {
        if (start > end)
        {
            return NULL;
        }
        Node *root = new Node(postorder[index]);
        int pos = search(inorder, root->data, start, end);

        // right
        root->right = tree(inorder, postorder, pos + 1, end, index - 1);

        // left
        root->left = tree(inorder, postorder, start, pos - 1, index - (end - pos) - 1);

        return root;
    }

    // Function to return a tree created from postorder and inorder traversals.
    Node *buildTree(vector<int> inorder, vector<int> postorder)
    {
        int idx = postorder.size() - 1;
        return tree(inorder, postorder, 0, inorder.size() - 1, idx);
    }
};

// Helper function to print level order traversal
void printLevelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> inorder(n), postorder(n);
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; ++i)
        cin >> inorder[i];
    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; ++i)
        cin >> postorder[i];

    Solution sol;
    Node *root = sol.buildTree(inorder, postorder);

    cout << "Level order traversal of constructed tree:" << endl;
    printLevelOrder(root);

    return 0;
}