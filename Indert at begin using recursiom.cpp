#include <iostream>
using namespace std;

// A class representing a node in the linked list
class node
{
public:
    int data; // Stores the data value of the node
    node *next; // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    node(int value)
    {
        data = value; // Assign the value to the data field
        next = NULL;  // Initialize the next pointer to NULL
    }

    // Recursive function to insert elements at the beginning of the linked list
    // Parameters:
    // - arr: Array containing values to insert
    // - index: Current index in the array
    // - size: Total size of the array
    // - prev: Pointer to the previous node (initially NULL)
    node *insertAtbegin(int arr[], int index, int size, node *prev)
    {
        if (index == size) // Base case: If all elements are processed, return the head of the list
            return prev;

        // Create a new node with the current array value
        node *temp = new node(arr[index]);

        // Link the new node to the previously created nodes
        temp->next = prev;

        // Recursive call to process the next element in the array
        return insertAtbegin(arr, index + 1, size, temp);
    }
};

int main()
{
    node *head; // Pointer to the head of the linked list
    head = NULL; // Initialize the head to NULL (empty list)

    // Array containing the values to be inserted into the linked list
    int arr[] = {20, 30, 40, 50};

    // Recursively insert elements from the array into the linked list
    head = head->insertAtbegin(arr, 0, 4, head);

    // Temporary pointer to traverse the linked list
    node *temp;
    temp = head;

    // Print the linked list
    cout << "Linked List: ";
    while (temp) // Loop until the end of the list
    {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
}
