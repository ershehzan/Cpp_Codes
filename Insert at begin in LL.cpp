#include <iostream>
using namespace std;

// A class representing a node in the linked list
class Node
{
public:
    int data;   // Stores the data value of the node
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    Node(int value)
    {
        data = value;  // Assign the value to the data field
        next = NULL;   // Initialize the next pointer to NULL
    }
};

int main()
{
    Node *head;   // Pointer to the head of the linked list
    head = NULL;  // Initialize the head to NULL (empty list)

    // Array containing the values to be inserted into the linked list
    int arr[] = {20, 30, 40, 50};

    // Loop through the array to insert elements at the beginning of the linked list
    for (int i = 0; i < 4; i++)
    {
        if (head == NULL) // If the list is empty, create the first node
        {
            head = new Node(arr[i]); // Create a new node and assign it to head
        }
        else
        {
            // Create a new node and insert it at the beginning of the list
            Node *temp;
            temp = new Node(arr[i]); // Create a new node with the current array value
            temp->next = head;       // Link the new node to the current head
            head = temp;             // Update the head to point to the new node
        }
    }

    cout << "Linked List: ";

    // Pointer to traverse the linked list
    Node *current = head;

    // Print the elements of the linked list
    while (current != NULL) // Loop until the end of the list
    {
        cout << current->data << " "; // Print the data of the current node
        current = current->next;      // Move to the next node
    }
    cout << endl;

    return 0; // Indicate successful program completion
}
