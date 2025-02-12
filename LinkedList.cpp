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
    first->data = 100;
    first->next = second; // first node points to second

    second->data = 200;
    second->next = third; // second node points to third

    third->data = 300;
    third->next = fourth; // third node points to fourth

    fourth->data = 400;
    fourth->next = five; // fourth node points to fifth

    five->data = 500;
    five->next = nullptr; // last node points to null (end of list)

    // Traversing and printing the linked list
    Node *current = first; // Start from the first node

    while (current != nullptr) // Loop until the end of the list
    {
        cout << current->data << " "; // Print current node's data
        current = current->next; // Move to the next node
    }

    // Free allocated memory
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete five;

    return 0;
}
