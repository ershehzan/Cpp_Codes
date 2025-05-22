#include <iostream>
using namespace std;

// Definition of a Node in the linked list
class Node {
public:
    int data;      // Stores the value of the node
    Node* next;    // Pointer to the next node

    // Constructor to initialize the node with a value
    Node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {
    Node* head = NULL; // Pointer to the first node of the list
    Node* tail = NULL; // Pointer to the last node of the list
    
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n; // Read the number of nodes to create
    cout << "Enter the values of the nodes: ";
    
    // Creating the circular linked list
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val; // Read the value for each node
        
        if (head == NULL) {
            // If the list is empty, create the first node
            head = new Node(val);
            tail = head;
        } else {
            // Create a new node and attach it to the end of the list
            Node* temp = new Node(val);
            tail->next = temp;
            tail = temp;
        }
    }
    
    // Make the list circular by pointing the last node to the head
    tail->next = head; 

    // Initialize two pointers for loop detection
    Node* slow = head; // Moves one step at a time
    Node* fast = head; // Moves two steps at a time
    
    // Floyd's Cycle Detection Algorithm (Tortoise and Hare)
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow pointer by one
        fast = fast->next->next;     // Move fast pointer by two
        
        if (slow == fast) {
            // If slow and fast meet, there is a loop
            cout << "Loop exists!" << endl;
            break;
        }
    }
    
    // If fast reached the end, there is no loop
    if (fast == NULL || fast->next == NULL) {
        cout << "No Loop" << endl;
    }
    
    // Display the circular linked list
    cout << "Circular Linked List: ";
    Node* trav = head;
    do {
        cout << trav->data << " ";
        trav = trav->next;
    } while (trav != head); // Stop when we come back to the head
    
    return 0;
}
