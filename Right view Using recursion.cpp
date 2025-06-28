#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void rv(Node* root, int level, vector<int>& ans) {
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    rv(root->right, level + 1, ans);
    rv(root->left, level + 1, ans);
}

class Solution {
  public:
    vector<int> rightView(Node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        rv(root, 0, ans);
        return ans;
    }
};

// Utility function to build a simple binary tree from user input (level order)
Node* buildTree() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n == 0) return NULL;
    vector<Node*> nodes(n, NULL);
    cout << "Enter node values (use -1 for NULL): ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val != -1)
            nodes[i] = new Node(val);
    }
    for (int i = 0, j = 1; j < n; ++i) {
        if (nodes[i]) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

int main() {
    Node* root = buildTree();
    Solution solution;
    vector<int> result = solution.rightView(root);
    cout << "Right view of the tree: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;