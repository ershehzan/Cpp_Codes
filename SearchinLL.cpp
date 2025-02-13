#include <iostream>
using namespace std;

// Define a structure for a Node in the linked list
struct Node
{
    int data;   // Holds the integer value
    Node *next; // Pointer to the next node
};

int main()
{
    // Creating five nodes dynamically
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *five = new Node();

    // Assigning data values and linking nodes together
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = five;

    five->data = 50;
    five->next = nullptr; // Marks the end of the linked list

    // Asking user for the number to search
    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    // Searching for the target number in the linked list
    Node *current = first; // Start from the first node
    bool found = false;     // Flag to track if the number is found

    while (current != nullptr)
    {
        if (current->data == target) // If the target is found
        {
            found = true;
            break; // Exit the loop early
        }
        current = current->next; // Move to the next node
    }

    // Display the result based on search outcome
    if (found)
    {
        cout << "Number " << target << " is found in the linked list." << endl;
    }
    else
    {
        cout << "Number " << target << " is not found in the linked list." << endl;
    }

    return 0; // End of program
}
