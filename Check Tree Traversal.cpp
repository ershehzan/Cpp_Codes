#include <iostream>
#include <vector>
using namespace std;

// Forward declaration of Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex, int N) {
        if (inStart > inEnd || preIndex >= N)
            return NULL;

        Node* root = new Node(preorder[preIndex]);
        int index = -1;

        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->data) {
                index = i;
                break;
            }
        }

        if (index == -1) return NULL;

        preIndex++;
        root->left = buildTree(inorder, preorder, inStart, index - 1, preIndex, N);
        root->right = buildTree(inorder, preorder, index + 1, inEnd, preIndex, N);

        return root;
    }

    void getPostorder(Node* root, vector<int>& post) {
        if (!root) return;
        getPostorder(root->left, post);
        getPostorder(root->right, post);
        post.push_back(root->data);
    }

    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        int preIndex = 0;
        Node* root = buildTree(inorder, preorder, 0, N - 1, preIndex, N);

        vector<int> actualPost;
        getPostorder(root, actualPost);

        for (int i = 0; i < N; i++) {
            if (postorder[i] != actualPost[i])
                return false;
        }

        return true;
    }
};

int main() {
    int N;
    cout << "Enter number of nodes: ";
    cin >> N;
    int preorder[N], inorder[N], postorder[N];
    cout << "Enter preorder traversal: ";
    for (int i = 0; i < N; ++i) cin >> preorder[i];
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < N; ++i) cin >> inorder[i];
    cout << "Enter postorder traversal: ";
    for (int i = 0; i < N; ++i) cin >> postorder[i];

    Solution sol;
    if (sol.checktree(preorder, inorder, postorder, N))
        cout << "Yes, the traversals are of the same tree." << endl;
    else
        cout << "No, the traversals are NOT of the same tree." << endl;

    return 0;
}