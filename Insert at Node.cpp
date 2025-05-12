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

node *insertAtend(int arr[], int index, int size)
{

    if (index == size)
        return NULL;

    node *temp = new node(arr[index]);
    temp->next = insertAtend(arr, index + 1, size);
    return temp;
}

int main()
{
    node *head;
    head = NULL;

    int arr[] = {10, 20, 40, 50};
    int size = 4;
    head = insertAtend(arr, 0, size);

    int x = 2;
    node *temp = head;
    int value = 30;
    x--;
    while (x--)
    {

        temp = temp->next;
    };

    node *temp2 = new node(value);
    temp2->next = temp->next;
    temp->next = temp2;

    node *current = head;

    cout << "Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}