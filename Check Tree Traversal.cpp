#include <iostream>
#include <vector>
using namespace std;

// Definition of a node in the binary tree
struct Node {
    int data;       // Value stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child
    Node(int val) : data(val), left(NULL), right(NULL) {} // Constructor to initialize node
};

class Solution {
public:
    // Function to build a binary tree from inorder and preorder traversals
    // inorder[]: Inorder traversal array
    // preorder[]: Preorder traversal array
    // inStart, inEnd: Current segment of inorder array
    // preIndex: Current index in preorder array
    // N: Number of nodes
    Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex, int N) {
        // Base case: If no elements to construct the tree
        if (inStart > inEnd || preIndex >= N)
            return NULL;

        // Create a new node with current preorder element
        Node* root = new Node(preorder[preIndex]);
        int index = -1;

        // Find the index of the current root in inorder traversal
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->data) {
                index = i;
                break;
            }
        }

        // If the element is not found, return NULL (invalid tree)
        if (index == -1) return NULL;

        // Move to the next element in preorder array
        preIndex++;

        // Recursively build the left and right subtrees
        root->left = buildTree(inorder, preorder, inStart, index - 1, preIndex, N);
        root->right = buildTree(inorder, preorder, index + 1, inEnd, preIndex, N);

        return root;
    }

    // Function to get the postorder traversal of the tree and store in 'post'
    void getPostorder(Node* root, vector<int>& post) {
        if (!root) return;
        getPostorder(root->left, post);    // Traverse left subtree
        getPostorder(root->right, post);   // Traverse right subtree
        post.push_back(root->data);        // Visit root
    }

    // Function to check if given preorder, inorder, and postorder arrays represent the same tree
    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        int preIndex = 0;
        // Build the tree from preorder and inorder traversals
        Node* root = buildTree(inorder, preorder, 0, N - 1, preIndex, N);

        // Get the postorder traversal of the constructed tree
        vector<int> actualPost;
        getPostorder(root, actualPost);

        // Compare the given postorder traversal with the generated one
        for (int i = 0; i < N; i++) {
            if (postorder[i] != actualPost[i])
                return false; // Mismatch found
        }

        return true; // All traversals match
    }
};
int main() {
    int N;
    cout << "Enter number of nodes: ";
    cin >> N;
    int preorder[N], inorder[N], postorder[N];

    // Input preorder traversal
    cout << "Enter preorder traversal: ";
    for (int i = 0; i < N; ++i) cin >> preorder[i];

    // Input inorder traversal
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < N; ++i) cin >> inorder[i];

    // Input postorder traversal
    cout << "Enter postorder traversal: ";
    for (int i = 0; i < N; ++i) cin >> postorder[i];

    Solution sol;
    // Check if all three traversals are from the same tree
    if (sol.checktree(preorder, inorder, postorder, N))
        cout << "Yes, the traversals are of the same tree." << endl;
    else
        cout << "No, the traversals are NOT of the same tree." << endl;

    return 0;
}



