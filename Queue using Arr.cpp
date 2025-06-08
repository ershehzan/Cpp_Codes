// Include the standard input/output stream library
#include <iostream>
using namespace std;

// Define a Queue class that uses an array for storage
class Queue
{
    int front, rear; // Indices to track the front and rear of the queue
    int *arr;        // Pointer to dynamically allocated array for queue elements
    int size;        // Maximum size of the queue

public:
    // Constructor to initialize the queue with a specific size
    Queue(int n)
    {
        arr = new int[n]; // Dynamically allocate array for n elements
        size = n;         // Set the queue size
        front = rear = -1;// Initialize both front and rear to -1 (queue is empty)
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull()
    {
        return (rear == size - 1);
    }

    // Add an element to the queue
    void enqueue(int x)
    {
        if (isEmpty())
        {
            // If queue is empty, insert at position 0
            cout << "Inserting " << x << " in Queue" << endl;
            front = rear = 0;
            arr[0] = x;
        }
        else if (isFull())
        {
            // If queue is full, cannot insert new element
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            // Insert element at the next available rear position
            cout << "Inserting " << x << " in Queue" << endl;
            rear++;
            arr[rear] = x;
        }
    }

    // Remove an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            // If queue is empty, cannot remove element
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                // If only one element is left, removing it will empty the queue
                cout << "Removing " << arr[front] << " from Queue" << endl;
                cout << "Queue is now Empty" << endl;
                front = rear = -1; // Reset indices to indicate empty queue
            }
            else
            {
                // Remove the front element and move the front index forward
                cout << "Removing " << arr[front] << " from Queue" << endl;
                front++;
            }
        }
    }

    // Get the element at the front of the queue
    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1; // Return error value
        }
        else
        {
            cout << "Front element is: " << arr[front] << endl;
            return arr[front];
        }
    }
};

// Main function to demonstrate queue operations
int main()
{
    Queue q(5);        // Create a queue of size 5

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Dequeue (remove) two elements from the front
    q.dequeue();
    q.dequeue();

    // Display the current front element
    cout << q.start() << endl;

    return 0;
}
