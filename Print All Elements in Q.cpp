#include <iostream>
using namespace std;

class Queue
{
    int front, rear;
    int *arr;
    int size;

public:
    Queue(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }
    int getSize() const {
        // Return the current number of elements in the queue
        if (front == -1 && rear == -1) return 0;
        return rear - front + 1;
    }
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    bool isFull()
    {
        return (rear == size - 1);
    }

    void push(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
        }
        else if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }
        }
    }

    int peek(){
        if(isEmpty()){
            // cout << "Queue is Empty" << endl;
            return -1;
        }
        else{
            // cout << "Front element is: " << arr[front] << endl;
            return arr[front];
        }
    }
};

int main(){
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;
    Queue q(n);

    cout << "Enter element to enqueue: ";
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        q.push(x);
    }

    int p = q.getSize();
   
    cout << "Queue Elements are:";
    while (p--)
    {
        cout << q.peek() << " ";
        q.push(q.peek()); // Re-enqueue the front element to keep it in the queue
        q.pop();
    }
    cout << endl;

    return 0;
}