#include <iostream>
#include <vector>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int value)
    {

        data = value;
        next = NULL;
    }
};

node*reverse(node*curr,node*prev)
{
    if(curr==NULL)
    return prev;

    node*fut=curr->next;
    curr->next=prev;

    return reverse(fut,curr);
}

int main()
{

    node *head, *tail;
    tail = head = NULL;

    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        if (head == NULL)
        {
            head = new node(arr[i]);
            tail = head;
        }
        else
        {
            tail->next = new node(arr[i]);
            tail = tail->next;
        }
    }

    head=reverse(head,NULL);
    

    node *current;
    current = head;
    cout << "Reversed Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}
