#include <iostream>
#include <climits>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Helper function to build BST from postorder
Node *Bst(int arr[], int &index, int lower, int upper)
{
    if (index < 0 || arr[index] < lower || arr[index] > upper)
        return NULL;

    Node *root = new Node(arr[index--]);

    root->right = Bst(arr, index, root->data, upper);
    root->left = Bst(arr, index, lower, root->data);

    return root;
}

// Function to construct BST from postorder traversal
Node *constructTree(int post[], int size)
{
    int index = size - 1;
    return Bst(post, index, INT_MIN, INT_MAX);
}

// Inorder traversal to verify the BST
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
    int post[] = {1, 7, 5, 50, 40, 10};
    int size = sizeof(post) / sizeof(post[0]);

    Node *root = constructTree(post, size);

    cout << "Inorder traversal of the constructed BST:\n";
    inorder(root);
    cout << endl;

    return 0;
}
