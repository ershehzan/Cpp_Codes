#include <iostream>
using namespace std;

class Queue{
    int front, rear;
    int *arr;
    int size;

public:
    Queue(int n){
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    bool isEmpty(){
        return (front == -1);
    }

    bool isFull(){
        return ((rear + 1) % size == front);
    }

    void enqueue(int x){
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty()){
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
        cout << "Inserting " << x << " in Queue" << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Removing " << arr[front] << " from Queue" << endl;

        if (front == rear)
        {
            front = rear = -1;
            cout << "Queue is now Empty" << endl;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        cout << "Front element is: " << arr[front] << endl;
        return arr[front];
    }
};

int main()
{
   int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;
    Queue q(n);
    
     cout << "Enter element to enqueue: ";
    for(int i=0;i<n;i++){
        int x;
       
        cin >> x;
        q.enqueue(x);
    }

    return 0;
}






