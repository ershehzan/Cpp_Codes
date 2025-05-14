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
    int arr[] = {20, 30, 40, 50};

    // Create the linked list from the array
    for (int i = 0; i < 4; i++)
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

    // LC-206: Reverse the linked list by storing values in a vector
    // Start of the reverse logic
    vector<int> ans; // Vector to store the data of the linked list nodes
    node *temp = head;

    // Traverse the list and store data in the vector
    while (temp != NULL)
    {
        ans.push_back(temp->data); // Add the data of the current node to the vector
        temp = temp->next;         // Move to the next node
    }

    int i = ans.size() - 1; // Start from the last element of the vector
    temp = head;

    // Traverse the list again and update the nodes with reversed data
    while (temp)
    {
        temp->data = ans[i]; // Assign data from the vector in reverse order
        i--;
        temp = temp->next; // Move to the next node
    }
    // End of the reverse logic

    // Print the reversed linked list
    node *current = head;
    cout << "Reversed Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " "; // Print the data of the current node
        current = current->next;      // Move to the next node
    }
    return 0; // End of the program
}
