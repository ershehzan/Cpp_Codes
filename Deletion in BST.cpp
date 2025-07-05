#include <iostream> // For standard input/output operations
using namespace std;

// Node class representing a single node in the Binary Search Tree (BST)
class Node
{
public:
    int data;        // Value stored in the node
    Node *left;      // Pointer to the left child
    Node *right;     // Pointer to the right child

    // Constructor to initialize the node with a value
    Node(int value)
    {
        data = value;
        left = right = NULL; // Initialize child pointers as NULL
    }
};

// Recursive function to insert a value into the BST
Node *insert(Node *root, int value)
{
    // If the tree/subtree is empty, create a new node and return it
    if (!root)
    {
        Node *temp = new Node(value);
        return temp;
    }
    // If value is less than the current node, insert in left subtree
    if (value < root->data)
        root->left = insert(root->left, value);
    else // Otherwise, insert in right subtree
        root->right = insert(root->right, value);

    return root; // Return the unchanged (or updated) root pointer
}

// Inorder traversal to print the BST in sorted order (LNR: Left, Node, Right)
void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);         // Traverse the left subtree
    cout << root->data << " ";   // Print the current node's data
    inorder(root->right);        // Traverse the right subtree
}

// Search function to check if a target value exists in the BST
bool search(Node *root, int target)
{
    if (!root)
        return 0; // Tree is empty or not found

    if (root->data == target)
        return 1; // Found the value

    // Search the left or right subtree based on value comparison
    if (root->data > target)
        return search(root->left, target);
    else
        return search(root->right, target);
}

// Function to delete a node with value x from the BST
Node *deleteNode(Node *root, int x)
{
    if (!root)
        return NULL; // Value not found, return NULL

    // If the value to be deleted is smaller, go left
    if (root->data > x)
    {
        root->left = deleteNode(root->left, x);
        return root;
    }
    // If the value to be deleted is greater, go right
    else if (root->data < x)
    {
        root->right = deleteNode(root->right, x);
        return root;
    }
    // Node found
    else
    {
        // Case 1: Node is a leaf (no children)
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // Case 2: Node has only left child
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node has only right child
        else if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // Case 4: Node has two children
        else
        {
            // Find the largest value in left subtree (inorder predecessor)
            Node *child = root->left;
            Node *parent = root;

            // Go to the rightmost node in left subtree
            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            // If the predecessor is not the direct left child
            if (root != parent)
            {
                parent->right = child->left; // Re-attach the child’s left subtree
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else // Predecessor is direct left child
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
    int n; // Number of nodes to be inserted

    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    Node *root = NULL; //*

