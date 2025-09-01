#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int value){
        data = value;
        next = NULL;
    }
};
int main()
{

    node *head;
    node *tail = NULL; // Declare tail outside the loop
    head = NULL;
    int arr[] = {10, 20, 30, 40, 50};

   for (int i = 0; i < 5; i++)
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

    if (head != NULL)
    {
        if (head->next == NULL)
        {
            node *temp = head;
            delete temp;
            head = NULL;
        }

        else
        {
            node *prev = NULL;
            node *temp = head;

            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = NULL;
        }
    };

    cout << "Linked List After Last Node Deletion: ";

    node *current = head;

    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }

}

