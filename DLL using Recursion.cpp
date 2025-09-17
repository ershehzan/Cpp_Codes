#include <iostream>
using namespace std;

// Definition of node class for the Doubly Linked List
class node{
public:
    int data;       // Stores the value
    node *next;     // Pointer to the next node
    node *prev;     // Pointer to the previous node

    // Constructor to initialize the node
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

// Recursive function to create a doubly linked list from an array
node *DLL(int arr[], int index, int size, node *back)
{
    // Base case: if index reaches size, we've processed the whole array
    if (index == size)
        return NULL;

    // Create a new node with the current array element
    node *temp = new node(arr[index]);

    // Set the previous pointer to the previous node
    temp->prev = back;

    // Recursively create the rest of the list, setting temp->next to the result
    temp->next = DLL(arr, index + 1, size, temp);

    // Return the current node to be linked by its predecessor
    return temp;
}

int main(){
    node *head = NULL; // Pointer to head of the doubly linked list

    int n;
    cout << "Enter the number of Nodes: ";
    cin >> n;

    int arr[100]; // Static array to hold values
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input each value
    }

    // Build the DLL using recursion
    head = DLL(arr, 0, n, head); // head starts as NULL, recursion will link nodes

    // Print the Doubly Linked List
    node *curr = head;
    cout << "Doubly Linked List using Recursion: ";
    while (curr)
    {
        cout << curr->data << " "; // Print current node's data
        curr = curr->next;         // Move to next node
    }

    return 0;
}


