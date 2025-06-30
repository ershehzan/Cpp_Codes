#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition of the Node class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int search(vector<int> &arr, int key, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

class Solution
{
public:
    Node *tree(vector<int> in, vector<int> pre, int INstart, int INend, int index)
    {
        if (INstart > INend)
        {
            return NULL;
        }

        Node *root = new Node(pre[index]);
        int pos = search(in, root->data, INstart, INend);

        // left
        root->left = tree(in, pre, INstart, pos - 1, index + 1);
        // right
        root->right = tree(in, pre, pos + 1, INend, index + (pos - INstart) + 1);

        return root;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        int n = inorder.size();
        return tree(inorder, preorder, 0, n - 1, 0);
    }
};

// Helper function to print inorder traversal of the tree
void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Helper function to print the tree in level order
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
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};

    Solution sol;
    Node *root = sol.buildTree(inorder, preorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    cout << "Level order traversal of constructed tree:" << endl;
    printLevelOrder(root);

    return 0;
}

