#include <iostream>
using namespace std;

// Definition of the Node class representing each node in the binary tree
class Node
{
public:
    int data;           // Value/data stored in the node
    Node *left, *right; // Pointers to the left and right child nodes

    // Constructor to initialize node with a value and set child pointers to NULL
    Node(int val)
    {
        data = val;
        left = right = NULL; // Initialize children as null
    }
};

// Recursive function to create a binary tree based on user input
Node *BinaryTree()
{
    int n;

    cin >> n; // Read value for current node from user input
    if (n == -1) // -1 is a sentinel value indicating no node (NULL)
        return NULL;

    Node *temp = new Node(n); // Create a new node with the input value

    // Recursively construct the left subtree
    cout << "Enter the left child of " << n << ": ";
    temp->left = BinaryTree();

    // Recursively construct the right subtree
    cout << "Enter the right child of " << n << ": ";
    temp->right = BinaryTree();

    return temp; // Return the created node (subtree root)
}

// Function for preorder traversal: Root -> Left -> Right
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";   // Visit root node
    preorder(root->left);        // Traverse left subtree
    preorder(root->right);       // Traverse right subtree
}

// Function for inorder traversal: Left -> Root -> Right
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);         // Traverse left subtree
    cout << root->data << " ";   // Visit root node
    inorder(root->right);        // Traverse right subtree
}

// Function for postorder traversal: Left -> Right -> Root
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);       // Traverse left subtree
    postorder(root->right);      // Traverse right subtree
    cout << root->data << " ";   // Visit root node
}

int main()
{
    cout << "Enter the Root: ";  // Prompt user for the root node
    Node *Root;
    Root = BinaryTree();         // Build the binary tree recursively
    cout << "Binary Tree created successfully." << endl;

    // Example usage: print the root node's data if tree is not empty
    if (Root != NULL)
    {
        cout << "Root node value: " << Root->data << endl;
    }

    // Print the preorder traversal of the tree
    cout << "Preorder Traversal: ";
    preorder(Root);
    cout << endl;

    // Print the inorder traversal of the tree
    cout << "Inorder Traversal: ";
    inorder(Root);
    cout << endl;

    // Print the postorder traversal of the tree
    cout << "Postorder Traversal: ";
    postorder(Root);
    cout << endl;

    return 0; // Program executed successfully
}
