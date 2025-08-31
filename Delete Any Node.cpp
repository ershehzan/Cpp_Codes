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

int main(){
    node *head = NULL;
    node *tail = NULL;

    int arr[100];
    int n;
    cout << "Enter the number of Nodes for linked list: ";
    cin >> n;
    cout << "Enter the elements of Nodes in linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

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

    int x;
    cout << "Enter the value of the node to be deleted: ";
    cin >> x;

    if (x == 1){
        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {

        x--;
        node *current = head;
        node *prev = NULL;

        while (x--){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
    }
    node *curr = head;
    cout << "Enter the value of the node to be deleted: ";
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

}




