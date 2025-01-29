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

    first->data = 100;
    first->next = second;

    second->data = 200;
    second->next = third;

    third->data = 300;
    third->next = fourth;

    fourth->data = 400;
    fourth->next = five;

    five->data = 500;
    five->next = nullptr;

    Node *current = first;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
