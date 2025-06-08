// Include the necessary header file for input/output operations
#include <iostream>
using namespace std;

// Define a class for the Circular Queue
class Queue
{
    int front, rear;  // Indices to track the front and rear positions in the queue
    int *arr;         // Pointer to dynamically allocate the array for the queue
    int size;         // Maximum size of the queue

public:
    // Constructor to initialize the queue with a given size
    Queue(int n)
    {
        arr = new int[n]; // Dynamically allocate memory for the queue
        size = n;         // Set the size of the queue
        front = rear = -1; // Initialize front and rear to -1 (empty queue)
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Function to check if the queue is full (circular condition)
    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    // Function to add an element to the queue (enqueue operation)
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return; // Cannot insert if queue is full
        }
        else if (isEmpty())
        {
            // If queue is empty, set both front and rear to 0
            front = rear = 0;
            arr[rear] = x; // Insert the element at rear
        }
        else
        {
            // Move rear to the next position in a circular manner
            rear = (rear + 1) % size;
            arr[rear] = x; // Insert the element at rear
        }
        cout << "Inserting " << x << " in Queue" << endl;
    }

    // Function to remove an element from the queue (dequeue operation)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return; // Cannot remove if queue is empty
        }
        cout << "Removing " << arr[front] << " from Queue" << endl;

        // If only one element is left, reset queue to empty state
        if (front == rear)
        {
            front = rear = -1;
            cout << "Queue is now Empty" << endl;
        }
        else
        {
            // Move front to the next position in a circular manner
            front = (front + 1) % size;
        }
    }

    // Function to get the front element of the queue
    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1; // Indicate error value
        }
        cout << "Front element is: " << arr[front] << endl;
        return arr[front];
    }
};

int main()
{
    Queue q(5);        // Create a queue of size 5
    q.enqueue(10);     // Insert 10
    q.enqueue(20);     // Insert 20
    q.enqueue(30);     // Insert 30
    q.enqueue(40);     // Insert 40
    q.enqueue(50);     // Insert 50 (queue should be full here)
    q.dequeue();       // Remove front element (10)
    q.dequeue();       // Remove next front element (20)
    
    // Print the current front element
    cout << q.start() << endl;

    return 0;
}
