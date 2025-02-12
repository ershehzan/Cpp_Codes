#include <iostream>
using namespace std;

// Define a structure for a Node in the linked list
struct Node
{ 
    int data;    // Holds the integer value
    Node *next;  // Pointer to the next node
};

int main()
{
    // Creating five nodes dynamically
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *five = new Node();

    // Assigning values to the nodes and linking them together
    first->data = 10;
    first->next = second; // First node points to second node

    second->data = 20;
    second->next = third; // Second node points to third node

    third->data = 30;
    third->next = fourth; // Third node points to fourth node

    fourth->data = 40;
    fourth->next = five; // Fourth node points to fifth node

    five->data = 50;
    five->next = nullptr; // Last node points to nullptr (end of the list)

    int length = 0; // Variable to store the length of the linked list

    // Pointer to traverse the linked list
    Node *current = first;

    // Loop through the linked list and print each node's data
    while (current != nullptr)
    {
        length++; // Increment length for each node
        cout << current->data << "  "; // Print the data of the current node
        current = current->next; // Move to the next node
    }

    // Print the length of the linked list
    cout << "\nThe Length of the Linked List is: " << length << endl;

    // Free allocated memory to prevent memory leaks
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete five;

    return 0;
}
