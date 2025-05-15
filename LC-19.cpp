#include <iostream>
using namespace std;

// Definition of a single node in a linked list
class ListNode {
public:
    int val; // Value of the node
    ListNode* next; // Pointer to the next node in the list

    // Constructor to initialize a node with a value
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

// Solution class containing the method to remove the nth node from the end of the list
class Solution {
public:
    // Function to remove the nth node from the end of the list
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        // Step 1: Count the total number of nodes in the list
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: Calculate the position of the node to remove from the start
        count -= n;

        // Step 3: If the node to be removed is the head
        if (count == 0) {
            temp = head;
            head = head->next; // Move the head pointer to the next node
            delete temp; // Free the memory of the removed node
            return head;
        }

        // Step 4: Traverse to the node before the one to be removed
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        // Step 5: Remove the nth node from the end
        prev->next = curr->next; // Bypass the node to be removed
        delete curr; // Free the memory of the removed node

        return head; // Return the updated head of the list
    }
};

int main() {
    Solution solution;

    // Variables for creating the linked list
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    // Input the values of the linked list nodes
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (head == NULL) {
            head = new ListNode(value); // Create the first node
            tail = head;
        } else {
            tail->next = new ListNode(value); // Append new nodes to the list
            tail = tail->next;
        }
    }

    // Input the position of the node to be removed from the end
    int pos;
    cout << "Enter the position of the node to be removed from the end: ";
    cin >> pos;

    // Remove the nth node from the end
    head = solution.removeNthFromEnd(head, pos);

    // Print the updated linked list
    cout << "Updated linked list: ";
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
