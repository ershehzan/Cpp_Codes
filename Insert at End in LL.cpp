#include <iostream>
using namespace std;

// A class representing a node in the linked list
class node{
public:
    int data;   // Stores the data value of the node
    node *next; // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    node(int value)
    {
        data = value;  // Assign the value to the data field
        next = NULL;   // Initialize the next pointer to NULL
    }
};

int main(){
    node *head, *tail; // Pointers to the head and tail of the linked list
    tail = head = NULL; // Initialize both pointers to NULL (empty list)

    // Array containing the values to be inserted into the linked list
    int arr[] = {20, 30, 40, 50};

    // Loop through the array to insert elements into the linked list
    for (int i = 0; i < 4; i++)
    {
        // If the list is empty, create the first node
        if (head == NULL)
        {
            head = new node(arr[i]); // Create a new node and assign it to head
            tail = head;             // Tail also points to the same node
        }
        else
        {
            // Otherwise, create a new node and link it to the end of the list
            tail->next = new node(arr[i]); // Assign the new node to the next pointer of tail
            tail = tail->next;             // Move the tail pointer to the new node
        }
    }

    // Pointer to traverse the linked list
    node *current;
    current = head;

    // Print the elements of the linked list
    cout << "Linked List: ";
    while (current != NULL) // Loop until the end of the list
    {
        cout << current->data << " "; // Print the data of the current node
        current = current->next;      // Move to the next node
    }

    return 0; // Indicate successful program completion
}


