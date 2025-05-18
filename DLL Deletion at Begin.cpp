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

    //Deletion at the beginning
    if (head != NULL)
    {
        // if there is only one node
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


    node *trav = head;
    cout << "The linked list is: ";
    while (trav != NULL)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}