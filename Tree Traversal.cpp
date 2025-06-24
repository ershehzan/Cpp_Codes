#include <iostream>
using namespace std;

// Definition of the Node class for a binary tree
class Node
{
public:
    int data;           // Stores the value of the node
    Node *left, *right; // Pointers to the left and right child nodes

    // Constructor to initialize the node with a value
    Node(int val)
    {
        data = val;
        left = right = NULL; // Children are set to NULL initially
    }
};

// Function to build a binary tree recursively from user input
Node *BinaryTree()
{
    int n;

    cin >> n; // Read data for the current node from user
    if (n == -1) // -1 indicates no node (used to represent NULL)
        return NULL;

    Node *temp = new Node(n); // Create a new node with value n

    // Recursively build the left subtree
    cout << "Enter the left child of " << n << ": ";
    temp->left = BinaryTree();

    // Recursively build the right subtree
    cout << "Enter the right child of " << n << ": ";
    temp->right = BinaryTree();

    return temp; // Return the constructed subtree rooted at temp
}

// Function to print the preorder traversal (Root, Left, Right) of the tree
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";   // Visit the root node
    preorder(root->left);        // Traverse left subtree
    preorder(root->right);       // Traverse right subtree
}

// Function to print the inorder traversal (Left, Root, Right) of the tree
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);         // Traverse left subtree
    cout << root->data << " ";   // Visit the root node
    inorder(root->right);        // Traverse right subtree
}

// Function to print the postorder traversal (Left, Right, Root) of the tree
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);       // Traverse left subtree
    postorder(root->right);      // Traverse right subtree
    cout << root->data << " ";   // Visit the root node
}

int main()
{
    cout << "Enter the Root: ";  // Prompt user for the root node value
    Node *Root;
    Root = BinaryTree();         // Build the binary tree from user input
    cout << "Binary Tree created successfully." << endl;

    // Print the root node's data if the tree is not empty
    if (Root != NULL)
    {
        cout << "Root node value: " << Root->data << endl;
    }

    // Print the preorder traversal
    cout << "Preorder Traversal: ";
    preorder(Root);
    cout << endl;

    // Print the inorder traversal
    cout << "Inorder Traversal: ";
    inorder(Root);
    cout << endl;

    // Print the postorder traversal
    cout << "Postorder Traversal: ";
    postorder(Root);
    cout << endl;

    return 0; // Program ends successfully
}
