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
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    bool isFull()
    {
        return (rear == size - 1);
    }

    void enqueue(int x)
    {
        if (isEmpty())
        {
            cout << "Inserting " << x<<" in Queue" << endl;
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
            cout << "Inserting " << x<<" in Queue" << endl;
            rear++;
            arr[rear] = x;
        }
    }
    void dequeue()
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
                cout << "Removing " << arr[front] <<" from Queue" << endl;
                cout << "Queue is now Empty" << endl;
                front = rear = -1;
            }
            else
            {
                cout << "Removing " << arr[front] <<" from Queue" << endl;
                front++;
            }
        }
    }

    int start(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else{
            cout << "Front element is: " << arr[front] << endl;
            return arr[front];
        }
    }
};
int main(){
   
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
     
    q.dequeue();
    q.dequeue();

  cout << q.start() << endl;




}