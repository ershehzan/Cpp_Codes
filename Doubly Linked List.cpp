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
    node*tail=NULL;
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
            tail=head;
        }
        else
        {
            node*temp=new node(val);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
         
        }
    }

    node *curr = head;
    cout << "Doubly Linked List: ";
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}