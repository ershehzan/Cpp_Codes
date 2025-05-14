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
    tail = head = NULL;

    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();

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
    // Lc-206
    // start
    node *curr = head, *prev = NULL, *future = NULL;

    while (curr)
    {

        future = curr->next;

        curr->next = prev;
        prev = curr;
        curr = future;
    };

    head = prev;

    // end

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
