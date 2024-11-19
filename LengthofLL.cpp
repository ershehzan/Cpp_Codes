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

    int length = 0;

    Node *current = first;

    while (current != nullptr)

    {
        length++;
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n The Lenght of Linked List is : " << length << endl;
    return 0;
}