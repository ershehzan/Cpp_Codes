#include <iostream>
using namespace std;

// Queue class using an array for storage
class Queue
{
    int front, rear;   // 'front' points to the first element; 'rear' to the last element in the queue
    int *arr;          // Dynamic array to store queue elements
    int size;          // Maximum size of the queue

public:
    // Constructor to initialize the queue with a given size
    Queue(int n)
    {
        arr = new int[n];    // Allocate memory for the array
        size = n;            // Store the size
        front = rear = -1;   // Initialize both front and rear to -1, indicating the queue is empty
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

    // Add an element to the rear of the queue (enqueue operation)
    void enqueue(int x)
    {
        if (isEmpty())
        {
            // If queue is empty, set both front and rear to 0 and insert the first element
            cout << "Inserting " << x << " in Queue" << endl;
            front = rear = 0;
            arr[0] = x;
        }
        else if (isFull())
        {
            // If the queue is full, print a message and return
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            // Otherwise, increment rear and insert the new element
            cout << "Inserting " << x << " in Queue" << endl;
            rear++;
            arr[rear] = x;
        }
    }

    // Remove an element from the front of the queue (dequeue operation)
    void dequeue()
    {
        if (isEmpty())
        {
            // If the queue is empty, print a message and return
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                // If there is only one element, remove it and reset the queue to empty
                cout << "Removing " << arr[front] << " from Queue" << endl;
                cout << "Queue is now Empty" << endl;
                front = rear = -1;
            }
            else
            {
                // Otherwise, remove the front element and increment the front pointer
                cout << "Removing " << arr[front] << " from Queue" << endl;
                front++;
            }
        }
    }

    // Get the element at the front of the queue without removing it
    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            cout << "Front element is: " << arr[front] << endl;
            return arr[front];
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;
    Queue q(n);  // Create a queue of size n

    cout << "Enter element to enqueue: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.enqueue(x);  // Add each element to the queue
    }

    // Show the front element of the queue
    cout << q.start() << endl;

    // Note: You can add q.dequeue() calls here to test removing elements
}
