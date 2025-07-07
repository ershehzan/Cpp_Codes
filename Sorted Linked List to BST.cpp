#include <iostream>
#include <vector>
using namespace std;

// Linked List Node
class LNode
{
public:
    int data;
    LNode *next;

    LNode(int x)
    {
        data = x;
        next = NULL;
    }
};

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Convert sorted array to Balanced BST
    Node *BST(vector<int> &arr, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = start + (end - start + 1) / 2;
        Node *root = new Node(arr[mid]);

        root->left = BST(arr, start, mid - 1);
        root->right = BST(arr, mid + 1, end);

        return root;
    }

    // Convert sorted linked list to BST
    Node *sortedListToBST(LNode *head)
    {
        vector<int> arr;
        while (head)
        {
            arr.push_back(head->data);
            head = head->next;
        }
        return BST(arr, 0, arr.size() - 1);
    }
};

// Inorder traversal of BST
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Helper function to create a sorted linked list
LNode *createLinkedList(vector<int> values)
{
    if (values.empty())
        return NULL;
    LNode *head = new LNode(values[0]);
    LNode *curr = head;
    for (int i = 1; i < values.size(); ++i)
    {
        curr->next = new LNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main()
{
    vector<int> sortedList = {1, 2, 3, 4, 5, 6, 7};
    LNode *head = createLinkedList(sortedList);

    Solution sol;
    Node *bstRoot = sol.sortedListToBST(head);

    cout << "Inorder Traversal of BST: ";
    inorder(bstRoot);
    cout << endl;

    return 0;
}
