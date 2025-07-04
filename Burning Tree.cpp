#include <iostream>
#include <queue>
using namespace std;

// Node class definition
class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val) {
                data = val;
                left = right = NULL;
        }
};

// Functions from your previous code
void find(Node* root, int target, Node*& burnNode) {
        if (!root)
                return;
        if (root->data == target) {
                burnNode = root;
                return;
        }
        find(root->left, target, burnNode);
        find(root->right, target, burnNode);
}

int height(Node* root) {
        if (!root)
                return 0;
        return 1 + max(height(root->left), height(root->right));
}

int Burn(Node* root, int &timer, int target) {
        if (!root)
                return 0;
        if (root->data == target) {
                int lh = height(root->left);
                int rh = height(root->right);
                timer = max(lh, rh);
                return 1;
        }
        int left = Burn(root->left, timer, target);
        if (left > 0) {
                int rh = height(root->right);
                timer = max(timer, left + rh);
                return left + 1;
        }
        int right = Burn(root->right, timer, target);
        if (right > 0) {
                int lh = height(root->left);
                timer = max(timer, right + lh);
                return right + 1;
        }
        return 0;
}

class Solution {
    public:
        int minTime(Node* root, int target) {
                int timer = 0;
                Burn(root, timer, target);
                Node* burnNode = NULL;
                find(root, target, burnNode);
                int high = height(burnNode) - 1;
                return max(timer, high);
        }
};

// Helper function to build tree from level order input
Node* buildTree() {
        int val;
        cin >> val;
        if (val == -1) return NULL;
        Node* root = new Node(val);
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
                Node* curr = q.front();
                q.pop();
                int leftVal, rightVal;
                cin >> leftVal;
                if (leftVal != -1) {
                        curr->left = new Node(leftVal);
                        q.push(curr->left);
                }
                cin >> rightVal;
                if (rightVal != -1) {
                        curr->right = new Node(rightVal);
                        q.push(curr->right);
                }
        }
        return root;
}

int main() {
        cout << "Enter tree in level order (use -1 for NULL nodes):" << endl;
        Node* root = buildTree();
        int target;
        cout << "Enter target node value: ";
        cin >> target;
        Solution sol;
        int result = sol.minTime(root, target);
        cout << "Minimum time to burn the tree: " << result << endl;
        return 0;
}


