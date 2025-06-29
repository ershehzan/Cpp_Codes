#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        stack<Node*> s;
        vector<int> ans;
        if (!root) return ans;
        s.push(root);
        while (!s.empty()) {
            Node* temp = s.top();
            s.pop();
            ans.push_back(temp->data);
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }
        return ans;
    }
};

// Helper function to create a simple binary tree for demonstration
Node* createSampleTree() {
    /*   1
        / \
       2   3
      / \
     4   5  */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main() {
    Node* root = createSampleTree();
    Solution sol;
    vector<int> result = sol.preOrder(root);
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    // Free allocated memory (not strictly necessary for small demo)
    // ... (free nodes if needed)
    return 0;
}