#include <iostream>
#include <climits>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val)
{
        data = val;
        left = right = NULL;
    }
};

// Helper function to build BST from postorder traversal
Node* Bst(int arr[], int &index, int lower, int upper) {
    // Base case: index out of bounds or element not in valid range
    if (index < 0 || arr[index] < lower || arr[index] > upper)
        return NULL;

    // Create root node with current postorder element
    Node* root = new Node(arr[index--]);

    // Recursively build right subtree before left subtree
    root->right = Bst(arr, index, root->data, upper);
    root->left = Bst(arr, index, lower, root->data);

    return root;
}

// Function to initiate BST construction
Node* constructTree(int post[], int size) {
    int index = size - 1; // Start from last element of postorder array
    return Bst(post, index, INT_MIN, INT_MAX);
}

// Inorder traversal: Left → Root → Right
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal: Root → Left → Right
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int post[] = {1, 7, 5, 50, 40, 10};
    int size = sizeof(post) / sizeof(post[0]);

    Node* root = constructTree(post, size);

    cout << "Inorder traversal of the constructed BST:\n";
    inorder(root);
    cout << "\n";

    cout << "Preorder traversal of the constructed BST:\n";
    preorder(root);
    cout << "\n";

    return 0;
}

