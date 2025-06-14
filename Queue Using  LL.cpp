#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    // Enqueue operation
    void push(int val)
    {
        if (isEmpty())
        {

            front = rear = new Node(val);
            ;
            cout << "Queue is now initialized with value: " << val << endl;
        }
        else
        {
            Node *temp = new Node(val);
            rear->next = temp;
            cout << "Value " << val << " added to the queue" << endl;
            rear = temp;
        }
    }
    // Dequeue operation
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            delete front;
            front = rear = NULL;
            cout << "Queue is now empty after pop" << endl;
        }
        else
        {
            Node *temp = front;
            cout << "Popped: " << temp->data << endl;
            front = front->next;
            delete temp;
        }
    }
    // Peek operation
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, no front element" << endl;
            return -1; // or throw an exception
        }
        else
        {
            return front->data;
        }
    }
};

int main()
{

    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element is: " << q.peek() << endl;
    q.pop();
    cout << "Front element after pop is: " << q.peek() << endl;
    q.pop();
    cout << "Front element after another pop is: " << q.peek() << endl;
}