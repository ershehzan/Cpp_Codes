#include <iostream>
#include <queue>
using namespace std;

// Definition of a Node in the binary tree
class Node
{
public:
    int data;          // Value stored in the node
    Node *left, *right; // Pointers to left and right child nodes

    // Constructor to initialize node with a value and set children to NULL
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int main()
{
    int n;
    cout << "Enter the Root: ";
    cin >> n; // Input value for the root node

    int first, second; // Variables to store the left and right child values

    queue<Node *> q;   // Queue to help build the tree level by level (BFS)

    Node *root = new Node(n); // Create the root node
    q.push(root);             // Push root node into queue

    // Loop until all nodes have been processed
    while (!q.empty())
    {
        Node *temp = q.front(); // Get the front node from the queue
        q.pop();                // Remove the node from the queue

        // Input for the left child
        cout << "Enter the left child of " << temp->data << ": ";
        cin >> first;
        if (first != -1) // If input is not -1, create the left child
        {
            temp->left = new Node(first);
            q.push(temp->left); // Add left child to the queue
        }

        // Input for the right child
        cout << "Enter the Right child of " << temp->data << ": ";
        cin >> second;
        if (second != -1) // If input is not -1, create the right child
        {
            temp->right = new Node(second);
            q.push(temp->right); // Add right child to the queue
        }
    }
}
