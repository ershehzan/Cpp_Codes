#include <iostream>
using namespace std;
// Definition of the doubly linked list node
class node{
public:
    int data;       // Stores the value of the node
    node *next;     // Pointer to the next node in the list
    node *prev;     // Pointer to the previous node in the list

    // Constructor to initialize node with a value
    node(int val){
        data = val;
        next = prev = NULL;
    }
};

int main(){
    node *head = NULL; // Pointer to the head (first node) of the DLL
    node *tail = NULL; // Pointer to the tail (last node) of the DLL

    int n;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    cout << "Enter the values of the nodes: ";
    // Creating the doubly linked list with n nodes
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (head == NULL)
        {
            // First node creation
            head = new node(val);
            tail = head;
        }
        else
        {
            // Appending new node at the end
            node *temp = new node(val);
            tail->next = temp;   // Link the current tail to new node
            temp->prev = tail;   // Link the new node back to the tail
            tail = temp;         // Move the tail pointer to the new node
        }
    }

    int pos;
    cout << "Enter the position of the node you want to delete: ";
    cin >> pos;

    // Deleting the node at the given position
    if (pos == 1)
    {
        // Deleting the head node
        if (head->next == NULL)
        {
            // Only one node in the list
            delete head;
            head = NULL;
        }
        else
        {
            // More than one node; update head and delete old head
            node *temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL; // Set new head's prev to NULL
        }
    }
    else
    {
        // Deleting node at position other than head
        node *curr = head;
        // Traverse to the node to be deleted
        while (--pos)
        {
            curr = curr->next;
        }
        if (curr->next == NULL)
        {
            // Deleting the last node (tail)
            curr->prev->next = NULL; // Set previous node's next to NULL
            delete curr;
        }
        else
        {
            // Deleting a node from the middle
            node *back = curr->prev;    // Node before the one to delete
            node *front = curr->next;   // Node after the one to delete

            back->next = front;         // Link previous node to next node
            front->prev = back;         // Link next node back to previous node
            delete curr;                // Delete the target node

            /*  Optimal solution (alternative one-liners)
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            */
        }
    }

    // Print the list after deletion
    node *trav = head;
    cout << "Linked List after Deletion : ";
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}




