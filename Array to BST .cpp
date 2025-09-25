#include <iostream>
#include <vector>
using namespace std;
// Binary Tree Node class
class Node{
public:
    int data;       // Value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with given value
    Node(int val)
        data=val;
       left=right=NULL;
};
// Solution class to build BST from sorted array
class Solution {
public:
    // Helper function to recursively build the BST
    Node* ArrayToBST(vector<int>& arr, int start, int end) {
        // Base case: if start index exceeds end, return null (no node)
        if (start > end)
            return nullptr;

        // Find the middle element to ensure balanced BST
        int mid = start + (end - start) / 2;

        // Create a new node with the middle element as root
        Node* root = new Node(arr[mid]);

        // Recursively build left subtree with left half of array
        root->left = ArrayToBST(arr, start, mid - 1);

        // Recursively build right subtree with right half of array
        root->right = ArrayToBST(arr, mid + 1, end);

        // Return the root node of this subtree
        return root;
    }

    // Public function to initiate BST construction from entire array
    Node* sortedArrayToBST(vector<int>& nums) {
        return ArrayToBST(nums, 0, nums.size() - 1);
    }
};

// Helper function to perform inorder traversal of BST
// Inorder traversal of BST yields sorted order of elements
void inorderTraversal(Node* root){
    if (!root) return;                 // Base case: null node

    inorderTraversal(root->left);      // Traverse left subtree
    cout << root->data << " ";         // Visit root node
    inorderTraversal(root->right);     // Traverse right subtree
}

int main(){
    // Input sorted array
    vector<int> arr = {-10, -3, 0, 5, 9};
    // Create Solution object
    Solution sol;
    // Construct BST from sorted array
    Node* root = sol.sortedArrayToBST(arr);
    // Print inorder traversal of the constructed BST
    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}












