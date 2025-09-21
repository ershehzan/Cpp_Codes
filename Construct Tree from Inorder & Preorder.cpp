#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Tree node structure
struct Node{
    int data;       // Stores the value of the node
    Node *left;     // Pointer to the left child node
    Node *right;    // Pointer to the right child node
    Node(int x)
    {
        data = x;
        left = right = NULL; // Initialize left and right to NULL
    }
};
// Searches for the index of 'target' in 'arr' between indices s and e (inclusive)
// Returns the index if found, otherwise returns -1
int search(vector<int> &arr, int target, int s, int e){
    for (int i = s; i <= e; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

class Solution{
public:
    // Recursively builds a binary tree from inorder and postorder traversal arrays
    // inorder: vector representing inorder traversal
    // postorder: vector representing postorder traversal
    // start, end: current segment of inorder array to consider
    // index: current root index in postorder array (from the end towards start)
    Node *tree(vector<int> &inorder, vector<int> &postorder, int start, int end, int index){
        // Base case: if the start index exceeds end, subtree is empty
        if (start > end)
        {
            return NULL;
        }
        // The current root node is at postorder[index]
        Node *root = new Node(postorder[index]);
        // Find the index of root's value in the inorder array
        int pos = search(inorder, root->data, start, end);

        // Recursively construct the right subtree first (since postorder is being processed from end)
        // Right subtree will use elements from pos+1 to end in inorder,
        // and the next element in postorder (index - 1)
        root->right = tree(inorder, postorder, pos + 1, end, index - 1);

        // Recursively construct the left subtree
        // Left subtree uses elements from start to pos-1 in inorder,
        // and skips the elements used for the right subtree in postorder
        root->left = tree(inorder, postorder, start, pos - 1, index - (end - pos) - 1);

        return root;
    }

    // Builds the binary tree given inorder and postorder traversal vectors
    // Returns the root node of the constructed tree
    Node *buildTree(vector<int> inorder, vector<int> postorder){
        int idx = postorder.size() - 1; // Start from the last element in postorder
        return tree(inorder, postorder, 0, inorder.size() - 1, idx);
    }
};

// Helper function to print the level order traversal (BFS) of the tree
void printLevelOrder(Node *root){
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size(); // Number of nodes at the current level
        while (sz--)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " "; // Print the current node's data
            if (curr->left)
                q.push(curr->left);    // Add left child to the queue if exists
            if (curr->right)
                q.push(curr->right);   // Add right child to the queue if exists
        }
        cout << endl; // Newline after each level
    }
}

int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> inorder(n), postorder(n);

    // Input inorder traversal from user
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; ++i)
        cin >> inorder[i];

    // Input postorder traversal from user
    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; ++i)
        cin >> postorder[i];

    Solution sol;
    // Build the tree using the given traversals
    Node *root = sol.buildTree(inorder, postorder);

    // Output the tree in level order to verify correctness
    cout << "Level order traversal of constructed tree:" << endl;
    printLevelOrder(root);

    return 0;
}









