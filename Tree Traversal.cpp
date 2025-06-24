#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *BinaryTree()
{
    int n;

    cin >> n;
        if (n == -1)
        return NULL;

    Node *temp = new Node(n);
    cout << "Enter the left child of " << n << ": ";
    temp->left = BinaryTree();
    cout << "Enter the right child of " << n << ": ";
    temp->right = BinaryTree();
    return temp;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{

    cout << "Enter the Root: ";
    Node *Root;
    Root = BinaryTree();
    cout << "Binary Tree created successfully." << endl;

    // Example usage: print the root node's data if tree is not empty
    if (Root != NULL)
    {
        cout << "Root node value: " << Root->data << endl;
    }
    cout << "Preorder Traversal: ";
    preorder(Root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inorder(Root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(Root);
    cout << endl;
    return 0;
}