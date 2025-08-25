#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition of the Node class representing nodes of the binary tree
class Node{
public:
    int data;      // Value of the node
    Node *left;    // Pointer to left child
    Node *right;   // Pointer to right child

    // Constructor to initialize the node with given value
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Utility function to search for a value in a vector within a specific range
// Returns the index of the key if found, otherwise -1
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
    // Recursive function to construct the binary tree
    // in: inorder traversal vector
    // pre: preorder traversal vector
    // INstart: starting index for inorder traversal
    // INend: ending index for inorder traversal
    // index: current index in preorder vector
    Node *tree(vector<int> in, vector<int> pre, int INstart, int INend, int index)
    {
        // Base case: if the current subtree is empty
        if (INstart > INend)
        {
            return NULL;
        }

        // Create a new node with the current root value from preorder
        Node *root = new Node(pre[index]);
        // Find the position of this root value in inorder traversal
        int pos = search(in, root->data, INstart, INend);

        // Recursively build the left subtree
        // The left subtree will use the next index in preorder and the left segment in inorder
        root->left = tree(in, pre, INstart, pos - 1, index + 1);

        // Recursively build the right subtree
        // The right subtree will use the next index after all left subtree nodes in preorder
        root->right = tree(in, pre, pos + 1, INend, index + (pos - INstart) + 1);

        return root;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        int n = inorder.size();
        // Start tree construction from the full range and beginning of preorder
        return tree(inorder, preorder, 0, n - 1, 0);
    }
};

// Helper function to print the inorder traversal of the binary tree
void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);           // Print left subtree
    cout << root->data << " ";          // Print current node
    printInorder(root->right);          // Print right subtree
}

// Helper function to print the binary tree in level order (BFS)
void printLevelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();              // Number of nodes at current level
        while (sz--)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";  // Print current node
            if (curr->left)
                q.push(curr->left);     // Add left child to queue if exists
            if (curr->right)
                q.push(curr->right);    // Add right child to queue if exists
        }
        cout << endl;
    }
}

int main()
{
    // Example inorder and preorder traversals for demonstration
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};

    Solution sol;
    // Build the tree from the given traversals
    Node *root = sol.buildTree(inorder, preorder);

    // Print inorder traversal of the constructed tree
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    // Print level order traversal of the constructed tree
    cout << "Level order traversal of constructed tree:" << endl;
    printLevelOrder(root);

    return 0;
}

