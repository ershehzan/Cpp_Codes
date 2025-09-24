#include<iostream>
using namespace std;
// Class representing a Dequeue (Double Ended Queue) using a circular array
class dequeue{
    int front, rear;   // Indices for front and rear of the dequeue
    int *arr;          // Pointer to the array holding elements
    int size;          // Maximum size of the dequeue
public:
    // Constructor to initialize the dequeue with given size
    dequeue(int n){
        size=n;
        arr=new int[size];  // Dynamically allocate array
        front = rear = -1;  // Initialize front and rear as empty
    }

    // Check if the dequeue is empty
    bool isEmpty(){
        return front==-1;
    }

    // Check if the dequeue is full
    bool isFull(){
        return (rear+1)%size==front;
    }

    // Insert an element at the front of the dequeue
    void push_front(int x){
        if(isFull()){
            cout << "Dequeue is full\n";
            return;
        }
        else if(isEmpty()){
            // If empty, insert at the first position
            front=rear=0;
            arr[0]=x;
        }
        else{
            // Move front pointer backwards (circularly) and insert
            front=(front-1+size)%size;
            arr[front]=x;
        }
    }

    // Insert an element at the back of the dequeue
    void push_back(int x){
        if(isFull()){
            cout << "Dequeue is full\n";
            return;
        }
        else if(isEmpty())
        {
            // If empty, insert at the first position
            front=rear=0;
            arr[0]=x;
        }
        else{
            // Move rear pointer forward (circularly) and insert
            rear=(rear+1)%size;
            arr[rear]=x;
        }
    }

    // Remove an element from the front of the dequeue
    void pop_front()
  {
        if(isEmpty()){
            cout << "Dequeue is Empty\n";
            return;
        }
        else if(front==rear)
        {
            // If only one element was present, reset dequeue
            front=rear=-1;
        }
        else{
            // Move front pointer forward (circularly)
            front=(front+1)%size;
        }
    }

    // Remove an element from the back of the dequeue
    void pop_back()
{
        if(isEmpty()){
            cout << "Dequeue is Empty\n";
            return;
        }
        else if(front==rear){
            // If only one element was present, reset dequeue
            front=rear=-1;
        }
        else{
            // Move rear pointer backward (circularly)
            rear=(rear-1+size)%size;
        }
    }

    // Get the front element of the dequeue
    int start(){
        if(isEmpty()){
            cout<<"Dequeue is Empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }

    // Get the rear element of the dequeue
    int end(){
        if(isEmpty()){
            cout<<"Dequeue is Empty";
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    // Display all elements in the dequeue from front to rear
    void display(){
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return;
        }
        cout << "Dequeue contents: ";
        int i = front;
        // Loop from front to rear (circularly)
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~dequeue(){
        delete[] arr;
    }
};

int main(){
    
    dequeue d(5);          // Create a dequeue of size 5
    d.push_back(10);       // Insert 10 at the back
    d.push_back(20);       // Insert 20 at the back
    d.push_front(5);       // Insert 5 at the front
    d.push_front(1);       // Insert 1 at the front
    d.display();           // Output: Dequeue contents: 5 1 10 20

    cout << "Front: " << d.start() << endl; // Output: 5
    cout << "Rear: " << d.end() << endl;   // Output: 20

    d.pop_front();         // Remove from front
    cout << "Front after pop: " << d.start() << endl; // Output: 10

    d.pop_back();          // Remove from back
    cout << "Rear after pop: " << d.end() << endl;   // Output: 10

    return 0;
}











