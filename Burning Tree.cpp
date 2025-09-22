#include <iostream>
#include <queue>
using namespace std;

// Node class definition for the binary tree
class Node {
    public:
        int data;       // Value of the node
        Node *left;     // Pointer to left child
        Node *right;    // Pointer to right child

        // Constructor to initialize node with value
        Node(int val) {
            data = val;
            left = right = NULL;
        }
};

// Helper function to find the node with the target value
// Updates burnNode pointer to point to the node with 'target' value
void find(Node* root, int target, Node*& burnNode) {
    if (!root)
        return;
    if (root->data == target) {
        burnNode = root;
        return;
    }
    find(root->left, target, burnNode);
    find(root->right, target, burnNode);
}

// Computes the height of a given subtree rooted at 'root'
int height(Node* root) {
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Recursive function to compute the minimum time to burn the tree from target node
// Returns distance from root to target if found, else returns 0
// Updates 'timer' with the maximum time needed to burn all nodes
int Burn(Node* root, int &timer, int target) {
    if (!root)
        return 0;
    if (root->data == target) {
        int lh = height(root->left);    // Height of left subtree
        int rh = height(root->right);   // Height of right subtree
        timer = max(lh, rh);            // Timer is the maximum of left/right subtrees
        return 1;                       // Target found, return distance as 1
    }
    int left = Burn(root->left, timer, target);    // Search in left subtree
    if (left > 0) {                               // If target found in left subtree
        int rh = height(root->right);             // Height of right subtree
        timer = max(timer, left + rh);            // Update timer
        return left + 1;                          // Distance from current node to target
    }
    int right = Burn(root->right, timer, target); // Search in right subtree
    if (right > 0) {                              // If target found in right subtree
        int lh = height(root->left);              // Height of left subtree
        timer = max(timer, right + lh);           // Update timer
        return right + 1;                         // Distance from current node to target
    }
    return 0;                                     // Target not found in either subtree
}

// Solution class encapsulating the main function to compute burning time
class Solution {
    public:
        // Returns the minimum time required to burn the entire tree from the target node
        int minTime(Node* root, int target) {
            int timer = 0;
            Burn(root, timer, target);        // Compute burning time using helper
            Node* burnNode = NULL;
            find(root, target, burnNode);     // Find node with target value
            int high = height(burnNode) - 1;  // Height of subtree under target node (minus 1 for edges)
            return max(timer, high);          // Maximum of two values is the answer
        }
};

// Helper function to build a binary tree from level order input
// Takes input from user, -1 indicates NULL node
Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}
// Main function to drive the program
int main() {
    cout << "Enter tree in level order (use -1 for NULL nodes):" << endl;
    Node* root = buildTree();             // Build tree from input
    int target;
    cout << "Enter target node value: ";
    cin >> target;                        // Take target value as input
    Solution sol;
    int result = sol.minTime(root, target);  // Compute minimum burn time
    cout << "Minimum time to burn the tree: " << result << endl;
    return 0;
}

