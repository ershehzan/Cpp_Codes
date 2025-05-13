#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{

    Node *head, *tail;
    tail = head = NULL;

    int arr[] = {10,20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
    {

        if (head == NULL)
        {
            
            head = new Node(arr[i]);
            tail = head;
        }
        else
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    cout << "Linked List After First Node Deletion: ";
    // Print the linked list
    Node *current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    };
    cout << endl;
    return 0;
}