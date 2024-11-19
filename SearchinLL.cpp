#include <iostream>
using namespace std;

struct Node
{ // holds the integer value
    int data;
    Node *next; // points to the next node
};
int main()
{

    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *five = new Node();

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = five;

    five->data = 50;
    five->next = nullptr;

    int target;
    cout << "Enter the number to search :";
    cin >> target;

    Node *current = first;
    bool found = false;
    while (current != nullptr)
    {
        if (current->data == target)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found)
    {
        cout << "Number " << target << " is found in the linked list :" << endl;
    }
    else
    {
        cout << "Number " << target << " is not found in the linked list :" << endl;
    }
    return 0;
}