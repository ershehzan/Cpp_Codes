#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{

    Node *head;
    head = NULL;

    int arr[] = {20, 30, 40, 50};

    for(int i=0;i<4;i++){
    if (head == NULL)
    {
        head = new Node(arr[i]);
    }
    else
    {

        Node *temp;
        temp = new Node(arr[i]);
        temp->next = head;
        head = temp;
    }
}
cout<<"Linked List: ";
    // Print the linked list
Node *current =head;

while(current !=NULL){
    cout<<current->data<<" ";
    current=current->next;
};
    cout<<endl;
    return 0;
}