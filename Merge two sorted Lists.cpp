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

class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        Node *head = new Node(0);
        Node *tail = head;

        while (head1 && head2)
        {
            if (head1->data <= head2->data)
            {
                tail->next = head1;
                head1 = head1->next;
                tail = tail->next;
                tail->next = NULL;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        if (head1)
        {
            tail->next = head1;
        }
        else
        {
            tail->next = head2;
        }
        Node *temp = head;
        head = head->next;
        delete temp;

        return head;
    }
};

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *createList(int n)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main()
{
    Solution solution;
    int n1, n2;
    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    cout << "Enter elements of first sorted list: ";
    Node *head1 = createList(n1);

    cout << "Enter number of nodes in second sorted list: ";
    cin >> n2;
    cout << "Enter elements of second sorted list: ";
    Node *head2 = createList(n2);

    Node *mergedHead = solution.sortedMerge(head1, head2);

    cout << "Merged sorted list: ";
    printList(mergedHead);

    return 0;
}