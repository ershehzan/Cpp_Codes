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

    int arr[] = {20, 30, 40, 50};
    int size = 4;
    head = insertAtend(arr, 0, size);

    node *current = head;

    cout << "Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}