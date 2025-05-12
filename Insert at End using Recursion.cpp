#include <iostream>
using namespace std;

// A class representing a node in the linked list
class node
{
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

// Recursive function to insert elements at the end of the linked list
// Parameters:
// - arr: Array containing values to insert
// - index: Current index in the array
// - size: Total size of the array
node *insertAtend(int arr[], int index, int size)
{
    if (index == size) // Base case: If all elements are processed, return NULL
        return NULL;

    // Create a new node with the current array value
    node *temp = new node(arr[index]);

    // Recursively insert the next elements and link them to the current node
    temp->next = insertAtend(arr, index + 1, size);
    return temp; // Return the current node
}

int main()
{
    node *head;   // Pointer to the head of the linked list
    head = NULL;  // Initialize the head to NULL (empty list)

    // Array containing the values to be inserted into the linked list
    int arr[] = {20, 30, 40, 50};
    int size = 4; // Size of the array

    // Recursively insert elements from the array into the linked list
    head = insertAtend(arr, 0, size);

    // Pointer to traverse the linked list
    node *current = head;

    // Print the elements of the linked list
    cout << "Linked List: ";
    while (current != NULL) // Loop until the end of the list
    {
        cout << current->data << " "; // Print the data of the current node
        current = current->next;      // Move to the next node
    }

    return 0; // Indicate successful program completion
}
