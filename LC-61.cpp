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

// Solution class containing the method to rotate the linked list
class Solution {
public:
    // Function to rotate the linked list to the right by k places
    ListNode* rotateRight(ListNode* head, int k) {
        // If the list is empty, has only one node, or no rotations are required
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Step 1: Count the total number of nodes in the list
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Step 2: Optimize rotations using modulo operation
        k = k % count; // Rotating by the length of the list results in the same list
        if (k == 0) return head; // If no effective rotations are needed, return head

        // Step 3: Find the new head of the list after rotation
        count -= k; // Determine the position of the new head
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (count--) { // Traverse to the node just before the new head
            prev = curr;
            curr = curr->next;
        }

        // Step 4: Perform the rotation
        prev->next = NULL; // Break the list at the new head
        ListNode* tail = curr; // Start from the new head
        while (tail->next) { // Find the original tail of the list
            tail = tail->next;
        }
        tail->next = head; // Connect the original tail to the original head
        head = curr; // Update the head pointer to the new head

        return head; // Return the rotated list
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

    // Step 1: Input the values of the linked list nodes
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

    // Step 2: Input the number of rotations
    int k;
    cout << "Enter the number of rotations: ";
    cin >> k;

    // Step 3: Rotate the linked list
    head = solution.rotateRight(head, k);

    // Step 4: Print the updated linked list
    cout << "Rotated linked list: ";
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " "; // Print each node value
        curr = curr->next; // Move to the next node
    }
    cout << endl;

    return 0;
}
