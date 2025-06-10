#include <iostream>
using namespace std;

// Node class represents each element in the linked list (used for queue nodes)
class Node
{
public:
    int data;      // Value stored in the node
    Node *next;    // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Queue class implements queue operations using a singly linked list
class Queue
{
    Node *front;   // Pointer to the front node of the queue
    Node *rear;    // Pointer to the rear node of the queue

public:
    // Constructor to initialize an empty queue
    Queue()
    {
        front = rear = NULL;
    }

    // Checks if the queue is empty
    bool isEmpty()
    {
        return front == NULL;
    }

    // Enqueue operation: Adds an element to the end of the queue
    void push(int val)
    {
        if (isEmpty())
        {
            // If the queue is empty, initialize both front and rear to the new node
            front = rear = new Node(val);
            cout << "Queue is now initialized with value: " << val << endl;
        }
        else
        {
            // Otherwise, add the new node at the end and update the rear pointer
            Node *temp = new Node(val);
            rear->next = temp;
            cout << "Value " << val << " added to the queue" << endl;
            rear = temp;
        }
    }

    // Dequeue operation: Removes an element from the front of the queue
    void pop()
    {
        if (isEmpty())
        {
            // If the queue is empty, print a message and return
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            // If only one element is left, delete it and reset both pointers
            delete front;
            front = rear = NULL;
            cout << "Queue is now empty after pop" << endl;
        }
        else
        {
            // Otherwise, remove the front element and move the front pointer
            Node *temp = front;
            cout << "Popped: " << temp->data << endl;
            front = front->next;
            delete temp;
        }
    }

    // Peek operation: Returns the value at the front of the queue without removing it
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
    Queue q;                // Create a queue instance
    q.push(10);             // Add 10 to the queue
    q.push(20);             // Add 20 to the queue
    q.push(30);             // Add 30 to the queue

    cout << "Front element is: " << q.peek() << endl; // Show front element

    q.pop();                // Remove front element (10)
    cout << "Front element after pop is: " << q.peek() << endl; // Show new front

    q.pop();                // Remove front element (20)
    cout << "Front element after another pop is: " << q.peek() << endl; // Show new front
}
