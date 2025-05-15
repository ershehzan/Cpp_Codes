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

// Solution class containing the method to find the middle node of a linked list
class Solution {
public:
    // Function to find and return the middle node of a linked list
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        // Step 1: Count the total number of nodes in the linked list
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: Calculate the middle position (integer division)
        count /= 2; // The middle node is at position count (0-based index)
        temp = head; // Reset temp to the head of the list

        // Step 3: Traverse to the middle node
        while (count--) {
            temp = temp->next; // Move temp forward by one node for each decrement
        }

        // Step 4: Return the middle node
        return temp;
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

    // Step 2: Find the middle node of the linked list
    ListNode* middle = solution.middleNode(head);

    // Step 3: Output the middle node value
    if (middle != NULL) {
        cout << "The middle node value is: " << middle->val << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}
