#include <iostream>
#include <algorithm> // For max()
using namespace std;

// Definition of a Node in AVL Tree
class Node
{
public:
    int data;    // Value of the node
    Node *left;  // Pointer to left child
    Node *right; // Pointer to right child
    int height;  // Height of the node

    // Constructor
    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1; // A newly created node is a leaf, so height is 1
    }
};

// Function to get the height of a node
int getheight(Node *root)
{
    if (!root)
        return 0; // Null node has height 0
    return root->height;
}

// Function to get the balance factor of a node
int getbalance(Node *root)
{
    if (!root)
        return 0;
    // Balance = height of left subtree - height of right subtree
    return getheight(root->left) - getheight(root->right);
}

// Right Rotation (for Left-Left case)
Node *rightrotation(Node *root)
{
    Node *child = root->left;
    Node *childright = child->right;

    // Perform rotation
    child->right = root;
    root->left = childright;

    // Update heights
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    // Return new root after rotation
    return child;
}

// Left Rotation (for Right-Right case)
Node *leftrotation(Node *root)
{
    Node *child = root->right;
    Node *childleft = child->left;

    // Perform rotation
    child->left = root;
    root->right = childleft;

    // Update heights
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    // Return new root after rotation
    return child;
}

// Function to insert a node in the AVL tree
Node *insert(Node *root, int key)
{
    // Step 1: Perform normal BST insertion
    if (!root)
        return new Node(key); // Create a new node if root is NULL

    if (key < root->data) // Insert in left subtree
        root->left = insert(root->left, key);
    else if (key > root->data) // Insert in right subtree
        root->right = insert(root->right, key);
    else
        return root; // Duplicates not allowed in AVL Tree

    // Step 2: Update the height of the ancestor node
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Step 3: Check the balance factor to see if the node became unbalanced
    int balance = getbalance(root);

    // Case 1: Left Left
    if (balance > 1 && key < root->left->data)
        return rightrotation(root);

    // Case 2: Right Right
    if (balance < -1 && key > root->right->data)
        return leftrotation(root);

    // Case 3: Left Right
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftrotation(root->left); // First rotate left
        return rightrotation(root);            // Then rotate right
    }

    // Case 4: Right Left
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightrotation(root->right); // First rotate right
        return leftrotation(root);                // Then rotate left
    }

    // Tree is balanced, no rotation needed
    return root;
}

// Inorder Traversal to print the tree in sorted order
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver Code
int main()
{
    Node *root = NULL;

    // Insert elements into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); // This triggers multiple rotations

    // Print the inorder traversal (should be sorted)
    cout << "Inorder traversal of the AVL tree is: ";
    inorder(root);
    cout << endl;

    return 0;
}
