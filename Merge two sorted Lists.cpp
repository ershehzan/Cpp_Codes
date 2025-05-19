#include <iostream>
using namespace std;

// Node class represents a single node in the linked list
class Node
{
public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node

    // Constructor to initialize the node with a value
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Solution class contains the method to merge two sorted linked lists
class Solution
{
public:
    // Function to merge two sorted linked lists and return the head of the merged list
    Node *sortedMerge(Node *head1, Node *head2)
    {
        // Create a dummy node to form the new list
        Node *head = new Node(0);
        Node *tail = head; // Tail pointer to add new nodes

        // Traverse both lists and append the smaller node to the merged list
        while (head1 && head2)
        {
            if (head1->data <= head2->data)
            {
                tail->next = head1;     // Append node from list 1
                head1 = head1->next;    // Move to next node in list 1
                tail = tail->next;      // Move tail forward
                tail->next = NULL;      // Ensure the new tail's next is NULL
            }
            else
            {
                tail->next = head2;     // Append node from list 2
                head2 = head2->next;    // Move to next node in list 2
                tail = tail->next;      // Move tail forward
                tail->next = NULL;      // Ensure the new tail's next is NULL
            }
        }

        // If any nodes remain in list 1, append them
        if (head1)
        {
            tail->next = head1;
        }
        // Otherwise, append remaining nodes from list 2
        else
        {
            tail->next = head2;
        }

        // Remove the dummy node and return the real head
        Node *temp = head;
        head = head->next;
        delete temp;

        return head;
    }
};

// Utility function to print the linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from user input
Node *createList(int n)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main()
{
    Solution solution;
    int n1, n2;
    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    cout << "Enter elements of first sorted list: ";
    Node *head1 = createList(n1);

    cout << "Enter number of nodes in second sorted list: ";
    cin >> n2;
    cout << "Enter elements of second sorted list: ";
    Node *head2 = createList(n2);

    // Merge the two sorted lists
    Node *mergedHead = solution.sortedMerge(head1, head2);

    cout << "Merged sorted list: ";
    printList(mergedHead);

    return 0;
}
