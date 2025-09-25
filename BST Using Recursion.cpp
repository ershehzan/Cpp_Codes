#include <iostream> // Include the input/output stream library for cin and cout
using namespace std;

// Definition of a node in the Binary Search Tree (BST)
class Node{
public:
    int data;        // Value stored in the node
    Node *left;      // Pointer to the left child
    Node *right;     // Pointer to the right child

    // Constructor to initialize the node with a value
    Node(int value){
        data = value;          // Set the node's data
        left = right = NULL;   // Initialize left and right pointers to NULL
    }
};

// Function to insert a new value into the BST using recursion
Node *insert(Node *root, int value)
{
    // If the current subtree is empty, create a new node and return it
    if (!root)
    {
        Node *temp = new Node(value);
        return temp;
    }

    // If the value to insert is less than the current node's data, insert into the left subtree
    if (value < root->data)
        root->left = insert(root->left, value);
    else // Otherwise, insert into the right subtree
        root->right = insert(root->right, value);

    return root; // Return the root node (unchanged except for new insertions)
}

// Function to perform inorder traversal of the BST (prints values in sorted order)
void inorder(Node *root)
{
    // If the current node is NULL, return (base case for recursion)
    if (!root)
        return;

    inorder(root->left);        // Traverse the left subtree
    cout << root->data << " ";  // Print the current node's data
    inorder(root->right);       // Traverse the right subtree
}

int main(){
    
    int n; // Number of nodes to be inserted

    // Ask the user for the number of nodes in the BST
    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    Node *root = NULL; // Initialize the root of the BST as NULL

    // Prompt the user to enter node values
    cout << "Enter value for nodes: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val; // Read the value for the node
        root = insert(root, val); // Insert the value into the BST
    }

    // Display the inorder traversal (sorted order of elements)
    cout << "Inorder Traversal of the BST: ";
    // Inorder traversal of BST will give sorted order of elements
    inorder(root);

    cout << endl; // Print a newline at the end
}




