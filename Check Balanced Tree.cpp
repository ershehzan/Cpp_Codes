#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Binary tree node structure
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
                data = val;
                left = NULL;
                right = NULL;
        }
};

// Height function to check balance
int h(Node* root, bool &valid) {
        if (!root)
                return 0;
        int l = h(root->left, valid);
        int r = h(root->right, valid);
        if (abs(l - r) > 1)
                valid = 0;
        return 1 + max(l, r);
}

class Solution {
    public:
        bool isBalanced(Node* root) {
                bool valid = 1;
                h(root, valid);
                return valid;
        }
};

int main() {
        // Example: create a balanced tree
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);

        Solution sol;
        if (sol.isBalanced(root))
                cout << "Tree is balanced" << endl;
        else
                cout << "Tree is not balanced" << endl;

        // Example: create an unbalanced tree
        Node* root2 = new Node(1);
        root2->left = new Node(2);
        root2->left->left = new Node(3);

        if (sol.isBalanced(root2))
                cout << "Tree is balanced" << endl;
        else
                cout << "Tree is not balanced" << endl;

        // Clean up memory (not strictly necessary for this example)
        // ... (delete nodes if needed)

        return 0;
}