#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void find(Node* root, int pos, int &l) {
    if (!root)
        return;
    l = max(pos, l);
    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}

void dig(Node* root, int pos, vector<vector<int>>& ans) {
    if (!root)
        return;
    ans[pos].push_back(root->data);
    dig(root->left, pos + 1, ans);
    dig(root->right, pos, ans);
}

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        int l = 0;
        find(root, 0, l);
        vector<vector<int>> ans(l + 1);
        dig(root, 0, ans);
        vector<int> temp;
        for (size_t i = 0; i < ans.size(); i++) {
            for (size_t j = 0; j < ans[i].size(); j++) {
                temp.push_back(ans[i][j]);
            }
        }
        return temp;
    }
};

// Utility function to build a binary tree from level order input
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
    vector<int> result = solution.diagonal(root);
    cout << "Diagonal Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}