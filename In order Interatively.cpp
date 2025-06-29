#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        stack<Node*> s;
        stack<bool> visited;
        vector<int> ans;

        if (!root) return ans;

        s.push(root);
        visited.push(0);

        while (!s.empty()) {
            Node* temp = s.top();
            s.pop();
            bool flag = visited.top();
            visited.pop();

            if (flag == 0) {
                if (temp->right) {
                    s.push(temp->right);
                    visited.push(0);
                }
                s.push(temp);
                visited.push(1);

                if (temp->left) {
                    s.push(temp->left);
                    visited.push(0);
                }
            } else {
                ans.push_back(temp->data);
            }
        }
        return ans;
    }
};

// Helper function to create a simple binary tree for testing
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
    vector<int> inorder = sol.inOrder(root);

    cout << "Inorder Traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    // Free allocated memory (not strictly necessary for small test)
    // ... (delete nodes if needed)

    return 0;
}