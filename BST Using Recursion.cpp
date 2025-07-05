#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
Node *insert(Node *root, int value)
{

    if (!root)
    {
        Node *temp = new Node(value);
        return temp;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
};

void inorder(Node *root)
{

    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    int n;
    cout << "Enter the number of nodes in the BST: ";
    cin >> n;
    Node *root = NULL;
    cout << "Enter value for nodes: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    cout << "Inorder Traversal of the BST: ";
    // Inorder traversal of BST will give sorted order of elements
    inorder(root);
    cout << endl;
}