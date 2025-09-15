#include <iostream>
#include <vector>
#include <queue>      // For level-order traversal
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

// Recursive function to construct BST from preorder traversal using bounds
TreeNode* BST(vector<int>& arr, int& index, int lower, int upper) {
    // Base case: end of array or current element out of bounds
    if (index == arr.size() || arr[index] < lower || arr[index] > upper)
        return NULL;

    // Create root node with current value
    TreeNode* root = new TreeNode(arr[index++]);

    // Recursively construct left and right subtrees
    root->left = BST(arr, index, lower, root->val);
    root->right = BST(arr, index, root->val, upper);

    return root;
}

// Solution class with main BST builder function
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return BST(preorder, index, INT_MIN, INT_MAX);
    }
};

// Inorder traversal (Left → Root → Right)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder traversal (Root → Left → Right)
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Level-order traversal (Breadth First Search)
void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

int main(){
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of the constructed BST:\n";
    inorder(root);
    cout << "\n";

    cout << "Preorder traversal of the constructed BST:\n";
    preorder(root);
    cout << "\n";

    cout << "Level-order traversal of the constructed BST:\n";
    levelOrder(root);
    cout << "\n";

    return 0;
}

