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
    //Lc-206
//start
    vector<int>ans;
        node*temp=head;

        while(temp!=NULL)
        {
            ans.push_back(temp->data);
            temp=temp->next;
        }
        int i=ans.size()-1;
        temp=head;

        while(temp){

            temp->data=ans[i];
            i--;
            temp=temp->next;
        }
        //end




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




