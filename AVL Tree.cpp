#include <iostream>
#include <algorithm> // For max()
using namespace std;

// Definition of a Node in AVL Tree
class Node {
public:
    int data;    // Value of the node
    Node *left;  // Pointer to left child
    Node *right; // Pointer to right child
    int height;  // Height of the node

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1; // New node is a leaf, so height is 1
    }
};

// Function to get the height of a node
int getheight(Node *root){
    if (!root)
        return 0; // Null nodes have height 0
    return root->height;
}

// Function to get the balance factor of a node
int getbalance(Node *root){
    if (!root)
        return 0;
    return getheight(root->left) - getheight(root->right);
}

// Right Rotation (for Left-Left case)
Node *rightrotation(Node *root){
    Node *child = root->left;
    Node *childright = child->right;

    // Perform right rotation
    child->right = root;
    root->left = childright;

    // Update heights after rotation
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    // Return new root after rotation
    return child;
}

// Left Rotation (for Right-Right case)
Node *leftrotation(Node *root) {
    Node *child = root->right;
    Node *childleft = child->left;

    // Perform left rotation
    child->left = root;
    root->right = childleft;

    // Update heights after rotation
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    // Return new root after rotation
    return child;
}

// Recursive function to insert a key in the AVL Tree
Node *insert(Node *root, int key) {
    // Step 1: Perform normal BST insertion
    if (!root)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys not allowed in AVL

    // Step 2: Update height of this ancestor node
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Step 3: Get balance factor to check for unbalance
    int balance = getbalance(root);

    // Step 4: Perform appropriate rotations

    // Case 1: Left-Left
    if (balance > 1 && key < root->left->data)
        return rightrotation(root);

    // Case 2: Right-Right
    if (balance < -1 && key > root->right->data)
        return leftrotation(root);

    // Case 3: Left-Right
    if (balance > 1 && key > root->left->data) {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    // Case 4: Right-Left
    if (balance < -1 && key < root->right->data) {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root; // Return the unchanged root if balanced
}

// Recursive function to delete a node in the AVL tree
Node *deleteNode(Node *root, int key){
    if (!root)
        return NULL;

    // Perform standard BST deletion
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        else if (root->left && !root->right) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else {
            // Node with two children: get the inorder successor (smallest in right subtree)
            Node *curr = root->right;
            while (curr->left)
                curr = curr->left;

            root->data = curr->data; // Copy successor data
            root->right = deleteNode(root->right, curr->data); // Delete successor
        }
    }

    // Update height after deletion
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Get balance factor
    int balance = getbalance(root);

    // Perform necessary rotations

    // Left-Left case
    if (balance > 1 && getbalance(root->left) >= 0)
        return rightrotation(root);

    // Left-Right case
    if (balance > 1 && getbalance(root->left) < 0) {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    // Right-Right case
    if (balance < -1 && getbalance(root->right) <= 0)
        return leftrotation(root);

    // Right-Left case
    if (balance < -1 && getbalance(root->right) > 0) {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root; // Return the balanced node
}

// Inorder traversal: prints tree in sorted order
void inorder(Node *root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main() {
    Node *root = NULL;

    // Insert values into AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); // Triggers multiple rotations (LR case)

    // Output the inorder traversal of AVL Tree
    cout << "Inorder traversal of the AVL tree is: ";
    inorder(root);
    cout << endl;

    return 0;
}












