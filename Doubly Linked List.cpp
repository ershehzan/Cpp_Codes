#include <iostream>
using namespace std;

// Definition of the node class for a doubly linked list
class node{
public:
    int data;       // Data part of the node
    node *next;     // Pointer to the next node
    node *prev;     // Pointer to the previous node

    // Constructor to initialize the node with a value
    node(int val){
        
        data = val;
        next = NULL;
        prev = NULL;
    }
};

int main(){
    
    node *head = NULL; // Points to the first node of the list
    node *tail = NULL; // Points to the last node of the list

    int n;
    cout << "Enter the number of Nodes: ";
    cin >> n;

    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val; // Read value to be inserted

        // If the list is empty, create the first node and assign both head and tail
        if (head == NULL)
        {
            head = new node(val);
            tail = head;
        }
        else
        {
            // Create a new node
            node *temp = new node(val);

            // Link current tail to the new node
            tail->next = temp;

            // Link new node back to current tail
            temp->prev = tail;

            // Move tail pointer to the newly created node
            tail = temp;
        }
    }

    // Traverse and display the linked list
    node *curr = head;
    cout << "Doubly Linked List: ";
    
    while (curr != NULL)
    {
        cout << curr->data << " "; // Print current node's data
        curr = curr->next;         // Move to the next node
    }

    return 0;
}






