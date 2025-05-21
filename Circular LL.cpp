#include <iostream>
using namespace std;

// Definition of the node class for the circular linked list
class node {
public:
    int data;      // Data stored in the node
    node *next;    // Pointer to the next node

    // Constructor to initialize the node with a value
    node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {
    node* head = NULL; // Pointer to the first node (head) of the list
    node* tail = NULL; // Pointer to the last node (tail) of the list

    int n;
    cout << "Enter the Number of Nodes: ";
    cin >> n; // Read the number of nodes to be created
    cout << "Enter the Value: ";

    // Loop to create the linked list with 'n' nodes
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val; // Read value for the current node

        if (head == NULL) {
            // If the list is empty, create the first node
            head = new node(val);
            tail = head;
        } else {
            // For subsequent nodes, create a new node and link it to the list
            node* temp = new node(val);
            tail->next = temp;
            tail = temp;
        }
    }

    // Make the linked list circular by connecting the last node to the head
    if (tail != NULL) {
        tail->next = head;
    }

    // Display the circular linked list
    node* curr = head;
    cout << "Circular Linked List: ";
    if (curr != NULL) {
        // Traverse the list starting from head until we reach head again
        do {
            cout << curr->data << " "; // Print current node's data
            curr = curr->next;         // Move to the next node
        } while (curr != head);        // Stop when we complete the circle
    }

    return 0; // Indicate successful program termination
}
