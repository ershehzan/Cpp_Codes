#include <iostream>
using namespace std;

// Definition of a node in the singly linked list
class Node {
public:
    int data;        // Data stored in the node
    Node* next;      // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Solution class containing method to remove duplicates
class Solution {
public:
    // Function to remove duplicates from a sorted linked list
    Node* removeDuplicates(Node* head) {
        // If the list is empty, return as is
        if (!head) return head;

        Node* prev = head;        // Pointer to the previous node (initially head)
        Node* curr = head->next;  // Pointer to the current node (starts from second node)
        
        // Traverse the linked list
        while (curr) {
            // If current node is a duplicate of the previous node
            if (curr->data == prev->data) {
                prev->next = curr->next; // Skip the duplicate
                delete curr;             // Free memory of duplicate node
                curr = prev->next;       // Move current to the next node after deletion
            } else {
                prev = prev->next;       // Move prev pointer forward
                curr = curr->next;       // Move curr pointer forward
            }
        }
        // Return the head of the modified list
        return head;
    }
};

// Utility function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " "; // Print current node data
        head = head->next;         // Move to next node
    }
    cout << endl;
}

// Utility function to create a linked list of n nodes from user input
Node* createList(int n) {
    Node* head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;                   // Read node value from user
        Node* newNode = new Node(value); // Create a new node
        if (!head) {
            head = newNode;             // First node becomes the head
            tail = head;                // Tail also points to head initially
        } else {
            tail->next = newNode;       // Add new node at the end
            tail = tail->next;          // Update the tail pointer
        }
    }
    return head;
}

int main() {
    Solution solution;
    int n;
    cout << "Enter number of nodes in sorted linked list: ";
    cin >> n;
    cout << "Enter elements of sorted linked list: ";
    Node* head = createList(n);                 // Create the linked list from input

    head = solution.removeDuplicates(head);      // Remove duplicates

    cout << "List after removing duplicates: ";
    printList(head);                            // Print the modified list

    return 0;
}
