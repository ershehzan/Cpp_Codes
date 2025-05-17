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

node *DLL(int arr[], int index, int size, node *back)
{

    if (index == size)
        return NULL;

    node *temp = new node(arr[index]);
    temp->prev = back;

    temp->next = DLL(arr, index + 1, size, temp);

    return temp;
};

int main()
{

    node *head = NULL;

    int n;
    cout << "Enter the number of Nodes: ";
    cin >> n;

    int arr[100];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    head = DLL(arr, 0, n, head);

    node *curr = head;
    cout << "Doubly Linked List using Recursion: ";
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}