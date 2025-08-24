#include <iostream>
#include <queue>
using namespace std;

// Node structure for binary tree
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Solution class containing all logic to check Max-Heap
class Solution {
  public:
    // Counts total number of nodes in the binary tree
    int count(Node* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    // Checks if the tree is a Complete Binary Tree
    bool CBT(Node* root, int index, int nodes) {
        if (!root) return true;

        // If index assigned to current node is beyond total nodes => not CBT
        if (index >= nodes) return false;

        // Recursively check left and right subtrees
        return CBT(root->left, 2 * index + 1, nodes) &&
               CBT(root->right, 2 * index + 2, nodes);
    }

    // Checks if the binary tree satisfies the max-heap property
    bool maxheap(Node* root)
     {
        // Check left child
        if (root->left) {
            // If parent is smaller than left child => not heap
            if (root->data < root->left->data)
                return false;
            // Recur for left subtree
            if (!maxheap(root->left))
                return false;
        }

        // Check right child
        if (root->right) 
        {
            // If parent is smaller than right child => not heap
            if (root->data < root->right->data)
                return false;
            // Recur for right subtree
            return maxheap(root->right);
        }

        return true; // Leaf node or both children checked
    }

    // Wrapper function to check if tree is a valid max heap
    bool isHeap(Node* tree) 
    {
        int num = count(tree);             // Step 1: Count total nodes
        if (!CBT(tree, 0, num)) return false; // Step 2: Check complete binary tree property
        return maxheap(tree);                // Step 3: Check max-heap property
    }
};

int main() {
    /*
       Construct this tree:
              10
             /  \
            9    8
           / \  /
          7  6 5
    */

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    Solution obj;
    if (obj.isHeap(root))
        cout << "The tree is a Max-Heap." << endl;
    else
        cout << "The tree is NOT a Max-Heap." << endl;

    return 0;
}



