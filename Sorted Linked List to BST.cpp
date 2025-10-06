#include <iostream>
#include <vector>
using namespace std;

// Definition of a Linked List Node
class LNode{
public:
    int data;
    LNode *next;

    // Constructor to initialize the node with a value
    LNode(int x){
        data = x;
        next = NULL;
    }
};

// Definition of a Binary Tree Node
class Node{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize the node with a value
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
public:
    // Helper function to convert a sorted array to a balanced BST
    Node *BST(vector<int> &arr, int start, int end)
    {
        // Base case: when start index exceeds end index
        if (start > end)
            return NULL;

        // Choose middle element as root to maintain balance
        int mid = start + (end - start + 1) / 2;

        // Create the root node with mid value
        Node *root = new Node(arr[mid]);

        // Recursively build the left subtree using left half
        root->left = BST(arr, start, mid - 1);

        // Recursively build the right subtree using right half
        root->right = BST(arr, mid + 1, end);

        return root;
    }

    // Main function to convert a sorted linked list to a balanced BST
    Node *sortedListToBST(LNode *head)
    {
        vector<int> arr;

        // Step 1: Convert the linked list to a vector (array)
        while (head)
        {
            arr.push_back(head->data);
            head = head->next;
        }

        // Step 2: Use the array to construct a balanced BST
        return BST(arr, 0, arr.size() - 1);
    }
};

// Function to perform inorder traversal of the BST
// Inorder traversal of BST should give the sorted order
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);         // Visit left subtree
    cout << root->data << " ";   // Print root data
    inorder(root->right);        // Visit right subtree
}

// Helper function to create a sorted linked list from a vector
LNode *createLinkedList(vector<int> values)
{
    if (values.empty())
        return NULL;

    // Create the head node
    LNode *head = new LNode(values[0]);
    LNode *curr = head;

    // Link remaining nodes
    for (int i = 1; i < values.size(); ++i)
    {
        curr->next = new LNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main(){
    // Input: sorted list to be converted to BST
    vector<int> sortedList = {1, 2, 3, 4, 5, 6, 7};

    // Create linked list from the sorted array
    LNode *head = createLinkedList(sortedList);

    // Create Solution object
    Solution sol;

    // Convert the sorted linked list to a balanced BST
    Node *bstRoot = sol.sortedListToBST(head);

    // Display inorder traversal of BST (should match input list)
    cout << "Inorder Traversal of BST: ";
    inorder(bstRoot);
    cout << endl;

    return 0;
}






