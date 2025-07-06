#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// TreeNode definition
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = right = NULL;
    }
};

// Function to construct BST from preorder using bounds
TreeNode* BST(vector<int>& arr, int& index, int lower, int upper) {
    if (index == arr.size() || arr[index] < lower || arr[index] > upper)
        return NULL;

    TreeNode* root = new TreeNode(arr[index++]);

    root->left = BST(arr, index, lower, root->val);
    root->right = BST(arr, index, root->val, upper);

    return root;
}

// Solution class
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return BST(preorder, index, INT_MIN, INT_MAX);
    }
};

// Inorder traversal for validation
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of the constructed BST:\n";
    inorder(root);
    cout << endl;

    return 0;
}
