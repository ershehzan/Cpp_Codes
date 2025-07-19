#include <iostream>
#include <vector>
using namespace std;

// Structure of node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Your solution class
class Solution {
  public:
    void inorder(Node* root, vector<int>& ans) {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    void postorder(Node* root, int& index, vector<int>& ans) {
        if (!root)
            return;
        postorder(root->left, index, ans);
        postorder(root->right, index, ans);
        root->data = ans[index];
        index++;
    }

    void convertToMaxHeapUtil(Node* root) {
        vector<int> ans;
        inorder(root, ans); // Sorted values from BST
        int index = 0;
        postorder(root, index, ans); // Fill postorder to make Max Heap
    }
};

// Function to print postorder of the tree (for verifying Max Heap)
void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    /*
        Construct this BST:
                4
               / \
              2   6
             / \ / \
            1  3 5  7
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Solution obj;
    obj.convertToMaxHeapUtil(root);

    cout << "Postorder of the converted Max Heap: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
