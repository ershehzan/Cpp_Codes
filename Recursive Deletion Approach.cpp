
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

node *deletenode(node*current,int x){
    if(x==1){
        node*temp=current->next;
        delete current;
        return temp;

    }
    current->next=deletenode(current->next,x-1);
    return current;
}


int main()
{

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

    head=deletenode(head,x);
    cout << "Linked List After Deletion: ";
    node *curr = head;
    
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
