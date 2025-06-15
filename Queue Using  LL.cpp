#include <iostream>
using namespace std;

// Node class for singly linked list node
class Node
{
public:
    int data;       // Stores the value of the node
    Node *next;     // Pointer to the next node in the list

    // Constructor to initialize node with value and set next to NULL
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Queue class using a singly linked list
class Queue
{
    Node *front;    // Pointer to the front node (first element) of the queue
    Node *rear;     // Pointer to the rear node (last element) of the queue

public:
    // Constructor initializes an empty queue
    Queue()
    {
        front = rear = NULL;
    }

    // Function to check if queue is empty
    bool isEmpty()
    {
        return front == NULL;
    }

    // Enqueue operation: adds a new value at the rear of the queue
    void push(int val)
    {
        if (isEmpty())
        {
            // If queue is empty, create a new node and set both front and rear to it
            front = rear = new Node(val);
            cout << "Queue is now initialized with value: " << val << endl;
        }
        else
        {
            // If queue is not empty, create a new node and link it to the current rear
            Node *temp = new Node(val);
            rear->next = temp;       // Link new node after current rear
            cout << "Value " << val << " added to the queue" << endl;
            rear = temp;             // Update rear pointer
        }
    }

    // Dequeue operation: removes the front element from the queue
    void pop()
    {
        if (isEmpty())
        {
            // Cannot remove from an empty queue
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            // Only one element in the queue
            delete front;
            front = rear = NULL;
            cout << "Queue is now empty after pop" << endl;
        }
        else
        {
            // More than one element: remove the front node
            Node *temp = front;
            cout << "Popped: " << temp->data << endl;
            front = front->next;     // Move front pointer to next node
            delete temp;             // Free memory of old front node
        }
    }

    // Peek operation: returns the value of the front element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, no front element" << endl;
            return -1; // or throw an exception if desired
        }
        else
        {
            return front->data;
        }
    }
};

int main()
{
    Queue q;                // Create a queue object
    q.push(10);             // Add 10 to the queue
    q.push(20);             // Add 20 to the queue
    q.push(30);             // Add 30 to the queue

    cout << "Front element is: " << q.peek() << endl;      // Display current front

    q.pop();                // Remove the front element (10)
    cout << "Front element after pop is: " << q.peek() << endl; // Display front

    q.pop();                // Remove the front element (20)
    cout << "Front element after another pop is: " << q.peek() << endl; // Display front
}
