#include <iostream> // Include standard input/output stream library
using namespace std;

// Node class representing a node in the Binary Search Tree (BST)
class Node
{
public:
    int data;        // Value stored in the node
    Node *left;      // Pointer to the left child node
    Node *right;     // Pointer to the right child node

    // Constructor to initialize node with a value
    Node(int value)
    {
        data = value;          // Set node's data to the given value
        left = right = NULL;   // Initialize left and right pointers to NULL
    }
};

// Function to insert a value into the BST recursively
Node *insert(Node *root, int value)
{
    // If the current node is NULL, create and return a new node with the given value
    if (!root)
    {
        Node *temp = new Node(value);
        return temp;
    }
    // If the value to insert is less than root's data, insert into left subtree
    if (value < root->data)
        root->left = insert(root->left, value);
    else // Otherwise, insert into right subtree
        root->right = insert(root->right, value);

    return root; // Return the unchanged (or updated) root pointer
}

// Function to perform inorder traversal of the BST (prints nodes in sorted order)
void inorder(Node *root)
{
    if (!root)
        return; // Base case: if the node is NULL, return

    inorder(root->left);         // Visit left subtree
    cout << root->data << " ";   // Print the current node's data
    inorder(root->right);        // Visit right subtree
}

// Function to search for a target value in the BST
bool search(Node *root, int target)
{
    if (!root)
        return 0; // Base case: reached a NULL node, target not found

    if (root->data == target)
        return 1; // Target value found

    // If the target is less than current node's data, search left subtree
    if (root->data > target)
        return search(root->left, target);
    else // Otherwise, search right subtree
        return search(root->right, target);
}

int main()
{
    int n; // Number of nodes to insert into the BST

    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    Node *root = NULL; // Initialize BST root as NULL

    cout << "Enter value for nodes: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;           // Input value for the node
        root = insert(root, val); // Insert value into the BST
    }

    // Uncomment the following lines to see inorder traversal (sorted order)
    // cout << "Inorder Traversal of the BST: ";
    // inorder(root);
    // cout << endl;

    cout << "Enter the value to search in BST: ";
    int target;
    cin >> target;

    // Output 1 if found, 0 otherwise
    cout << search(root, target);
}
