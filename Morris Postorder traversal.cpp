#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Solution class as provided
class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* root) {
        
         // We will traverse the tree in the order - N R L.
        vector<int> ans;
        
        // We will traverse the tree until our root becomes nuLL that shows we have traverse the whole tree.
        while(root) {
            // If right of root doesn't exist then we will just go the left side and push the value of the node into the array.
            if(!root -> right){
                ans.push_back(root -> data);
                root = root -> left;
            } 
            // If right of root exist:
            else {
                // So if the right exist then we have to:
                // first, create a link of the leftmost node to the root node.
                // So that we can come back to root node.
                Node *curr = root -> right;
                // We are going to the leftmost node.
                while(curr -> left && curr -> left != root)
                    curr = curr -> left;
                // So now there are two conditions:
                // First, that we have not traverse that right [part.
                // Second, we have traverse the right part.
                
                // Now if we have not traverse the part then the left value of the curr node is NULL.
                // So we will add the value of the node to the ans array.
                // And make a link and go the right.
                if(curr -> left == NULL){
                    ans.push_back(root -> data);
                    curr -> left = root;
                    root = root -> right;
                } 
                // If we done the traversal then we will simply remove the link and go to left part.
                else {
                    curr -> left = NULL;
                    root = root -> left;
                }
            }
        }
        
        // After that we will reverse the ans array.
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
    }
};

// Helper function to build tree from level order input
Node* buildTree(const vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        Node* curr = q.front(); q.pop();
        if (vals[i] != -1) {
            curr->left = new Node(vals[i]);
            q.push(curr->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            curr->right = new Node(vals[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    // Example: build tree from level order: 1 2 3 4 5 -1 6
    vector<int> vals = {1, 2, 3, 4, 5, -1, 6};
    Node* root = buildTree(vals);

    Solution sol;
    vector<int> res = sol.postOrder(root);

    cout << "Morris Postorder Traversal: ";
    for (int v : res) cout << v << " ";
    cout << endl;

    return 0;
}