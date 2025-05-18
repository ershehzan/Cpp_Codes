// Doubly Linked List: Delete Node at End

#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class node
{
public:
    int data;      // Data stored in the node
    node *next;    // Pointer to the next node
    node *prev;    // Pointer to the previous node

    // Constructor to initialize node with a value
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

int main()
{
    node *head = NULL; // Pointer to the head of the list
    node *tail = NULL; // Pointer to the tail of the list
    int n;

    // Input: number of nodes to create
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    // Input: values for each node
    cout << "Enter the values of the nodes: ";

    // Creating the doubly linked list
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (head == NULL)
        {
            // For the first node, initialize head and tail
            head = new node(val);
            tail = head;
        }
        else
        {
            // For subsequent nodes, append at the end and update tail
            node *temp = new node(val);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    // Deletion at the end of the doubly linked list
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            // Only one node in the list
            delete head;
            head = NULL;
        }
        else
        {
            // More than one node: traverse to the last node
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            // Update the previous node's next pointer and delete last node
            temp->prev->next = NULL;
            delete temp;
        }
    }

    // Display the linked list after deletion
    node *trav = head;
    cout << "The linked list is: ";
    while (trav != NULL)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}
