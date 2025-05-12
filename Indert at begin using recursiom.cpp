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

    node *insertAtbegin(int arr[], int index, int size, node *prev)
    {
        if (index == size)
            return prev;

        node *temp = new node(arr[index]);
        temp->next = prev;
        return insertAtbegin(arr, index + 1, size, temp);
    }
};

int main()
{

    node *head;
    head = NULL;
    int arr[] = {20, 30, 40, 50};

    head = head->insertAtbegin(arr, 0, 4, head);

    node *temp;
    temp = head;
    cout << "Linked List: ";
    while (temp)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
}