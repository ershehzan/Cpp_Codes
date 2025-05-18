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
        next = prev = NULL;
    }
};

int main()
{

    node *head = NULL;
    node *tail = NULL;

    int n;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    cout << "Enter the values of the nodes: ";
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
    cout << "Enter the position of the node you want to delete: ";
    cin >> pos;

    if (pos == 1)
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // if there are more than one nodes
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
        }
    }

    else
    {
        node *curr = head;
        while (--pos)
        {
            curr = curr->next;
        }
        // last node
        if (curr->next == NULL)
        {
            curr->prev->next = NULL;
            delete curr;
        }
        // Middle node

        else
        {
            node *back = curr->prev;
            node *front = curr->next;

            back->next = front;
            front->prev = back;
            delete curr;


            /*  Optimal solution
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;   */ 
            
        }
    }

    node *trav = head;

    cout << "Linked List after Deletion : ";
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}