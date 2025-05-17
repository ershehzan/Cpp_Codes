#include <iostream>
using namespace std;

// Definition of the node class for the doubly linked list
class node {
public:
    int data;       // Data held by the node
    node *next;     // Pointer to the next node
    node *prev;     // Pointer to the previous node

    // Constructor to initialize the node with a given value
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

int main() {
    node *head = NULL; // Points to the first node of the doubly linked list
    node *tail = NULL; // Points to the last node of the doubly linked list

    int n;
    cout << "Enter the number of Nodes: ";
    cin >> n;

    cout << "Enter the values: ";
    // Creating the initial doubly linked list of size n
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        // If the list is empty, initialize head and tail with the first node
        if (head == NULL) {
            head = new node(val);
            tail = head;
        }
        // Otherwise, append the new node at the end of the list
        else {
            node *temp = new node(val); // Create a new node
            tail->next = temp;          // Link the current tail to the new node
            temp->prev = tail;          // Link the new node back to the current tail
            tail = temp;                // Update the tail to the new node
        }
    }

    int pos;
    cout << "Enter the position to insert a new node: ";
    cin >> pos;

    int val;
    cout << "Enter the value to insert: ";
    cin >> val;

    node *temp = new node(val); // Create the new node to be inserted
    node *curr = head;          // Pointer to traverse the list

    // Case 1: Inserting at the beginning
    if (pos == 0) {
        // If the list is empty, make the new node the head
        if (head == NULL) {
            head = new node(val);
        }
        // If the list is not empty, adjust pointers to insert at the start
        else {
            temp->next = head;     // Point new node's next to current head
            head->prev = temp;     // Point current head's prev to new node
            head = temp;           // Update head to the new node
        }
    }
    // Case 2: Inserting at middle or end
    else {
        // Traverse the list until the node before the target position
        while (--pos) {
            curr = curr->next;
        }

        // If inserting at the end (i.e., after the current last node)
        if (curr->next == NULL) {
            curr->next = temp; // Link current node to new node
            temp->prev = curr; // Link new node back to current node
        }
        // If inserting in the middle
        else {
            temp->next = curr->next;      // Point new node's next to current node's next
            temp->prev = curr;            // Point new node's prev to current node
            curr->next = temp;            // Link current node to new node
            temp->next->prev = temp;      // Link the next node's prev to new node
        }
    }

    // Traversing and printing the doubly linked list
    node *trav = head;
    cout << "Doubly Linked List: ";
    while (trav != NULL) {
        cout << trav->data << " "; // Print data
        trav = trav->next;         // Move to next node
    }
}
