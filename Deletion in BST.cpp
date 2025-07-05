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

bool search(Node *root, int target)
{
    if (!root)
        return 0;

    if (root->data == target)
        return 1;

    if (root->data > target)
        return search(root->left, target);
    else
        return search(root->right, target);
}

Node *deleteNode(Node *root, int x)
{

    if (!root)
        return NULL;

    if (root->data > x)
    {
        root->left = deleteNode(root->left, x);
        return root;
    }
    else if (root->data < x)
    {
        root->right = deleteNode(root->right, x);
        return root;
    }
    else
    {
        // leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // one child
        else if (!root->right) // left child exist
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // two child
        else if (!root->left) // right child exist
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child Exist
        else
        {
            // find greatest Element from left
            Node *child = root->left;
            Node *parent = root;

            // get to right most Node
            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            if (root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
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

    cout << "Enter the value to Delete in BST: ";
    int target;
    cin >> target;

    deleteNode(root, target);
    cout << "Inorder Traversal of the BST after deletion: ";
    inorder(root);
    cout << endl;
}