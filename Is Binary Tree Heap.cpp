#include <iostream>
#include <queue>
using namespace std;

// Node structure
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

// Your Solution class
class Solution {
  public:
    int count(Node* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    bool CBT(Node* root, int index, int nodes) {
        if (!root) return true;
        if (index >= nodes) return false;
        return CBT(root->left, 2 * index + 1, nodes) &&
               CBT(root->right, 2 * index + 2, nodes);
    }

    bool maxheap(Node* root) {
        if (root->left) {
            if (root->data < root->left->data)
                return false;
            if (!maxheap(root->left))
                return false;
        }
        if (root->right) {
            if (root->data < root->right->data)
                return false;
            return maxheap(root->right);
        }
        return true;
    }

    bool isHeap(Node* tree) {
        int num = count(tree);
        if (!CBT(tree, 0, num)) return false;
        return maxheap(tree);
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
