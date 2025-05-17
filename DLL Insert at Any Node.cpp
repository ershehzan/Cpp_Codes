#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n;
    cout << "Enter the number of Nodes: ";
    cin >> n;
    cout << "Enter the values: ";

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (head == NULL)
        {
            head = new node(val);
            tail = head;
        }
        else
        {
            node *temp = new node(val);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    int pos;
    cout << "Enter the position to insert a new node: ";
    cin >> pos;

    int val;
    cout << "Enter the value to insert: ";
    cin >> val;

    node *temp = new node(val);
    node *curr = head;

    // insert at the beginning
    if (pos == 0)
    {
        // Linked List is empty
        if (head == NULL)
        {
            head = new node(val);
        }
        else
        // Linked List is not empty
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else
    {

        while (--pos)
        {
            curr = curr->next;
        }
        // insert at the end
        if (curr->next == NULL)
        {

            curr->next = temp;
            temp->prev = curr;
        }

        // insert at the middle
        else
        {

            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
        }
    }
    node *trav = head;
    cout << "Doubly Linked List: ";
    while (trav != NULL)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}