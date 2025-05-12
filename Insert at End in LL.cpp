#include <iostream>
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

int main()
{

    node *head, *tail;
   tail= head = NULL;
    

    int arr[] = {20, 30, 40, 50};

    for (int i = 0; i < 4; i++)
    {

        if (head == NULL)
        {
            head = new node(arr[i]);
            tail=head;
        }
        else
        {
            tail->next = new node(arr[i]);
            tail = tail->next;
        }
    }

    node *current;
    current = head;
    cout << "Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}