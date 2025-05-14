#include <iostream> // For input-output operations
#include <vector>   // For using the vector container
using namespace std;

// Definition of the node class for the linked list
class node
{
public:
    int data;    // Data stored in the node
    node *next;  // Pointer to the next node

    // Constructor to initialize the node with a value
    node(int value)
    {
        data = value;
        next = NULL; // Initialize the next pointer to NULL
    }
};

int main()
{
    node *head, *tail; // Pointers for the head and tail of the linked list
    tail = head = NULL; // Initialize both to NULL

    // Input array to create the linked list
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size(); // Get the size of the array

    // Create the linked list from the array
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            // If the list is empty, create the first node
            head = new node(arr[i]);
            tail = head; // Tail points to the same node as head
        }
        else
        {
            // Add a new node at the end of the list
            tail->next = new node(arr[i]);
            tail = tail->next; // Move the tail pointer to the new node
        }
    }

    // LC-206: Reverse the linked list
    // Start of the reverse logic
    node *curr = head, *prev = NULL, *future = NULL; // Initialize pointers

    while (curr) // Traverse the list until the end
    {
        future = curr->next; // Save the next node
        curr->next = prev;   // Reverse the link
        prev = curr;         // Move prev to the current node
        curr = future;       // Move to the next node
    };

    head = prev; // Update the head to the new first node
    // End of the reverse logic

    // Print the reversed linked list
    node *current;
    current = head;
    cout << "Reversed Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " "; // Print the data of the current node
        current = current->next;      // Move to the next node
    }
    return 0; // End of the program
}
