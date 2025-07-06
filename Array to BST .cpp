#include <iostream>
#include <vector>
using namespace std;

// Binary Tree Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val), left(nullptr), right(nullptr) {}
};

// Solution class to build BST
class Solution {
public:
    Node* ArrayToBST(vector<int>& arr, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        Node* root = new Node(arr[mid]);

        root->left = ArrayToBST(arr, start, mid - 1);
        root->right = ArrayToBST(arr, mid + 1, end);

        return root;
    }

    Node* sortedArrayToBST(vector<int>& nums) {
        return ArrayToBST(nums, 0, nums.size() - 1);
    }
};

// Helper function to print inorder traversal
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> arr = {-10, -3, 0, 5, 9};

    Solution sol;
    Node* root = sol.sortedArrayToBST(arr);

    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
