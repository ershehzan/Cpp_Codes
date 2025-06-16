#include<iostream>
using namespace std;

class dequeue{
    int front, rear;
    int *arr;
    int size;
    public:
    dequeue(int n){
        size=n;
        arr=new int[size];
        front = rear = -1;
    }
    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return(rear+1)%size==front;
    }

    void push_front(int x){
        if(isFull()){
            cout << "Dequeue is full\n";
            return;
        }
        else if(isEmpty()){
            front=rear=0;
            arr[0]=x;
        }
        else{
            front=(front-1+size)%size;
            arr[front]=x;
        }
    }
    void push_back(int x){
         if(isFull()){
            cout << "Dequeue is full\n";
            return;
        }
        else if(isEmpty()){
            front=rear=0;
            arr[0]=x;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=x;
        }
    }
    void pop_front(){
        if(isEmpty()){
             cout << "Dequeue is Empty\n";
            return;
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
    void pop_back(){
         if(isEmpty()){
             cout << "Dequeue is Empty\n";
            return;
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
           rear=(rear-1+size)%size;
        }
    }
    int start(){
        if(isEmpty()){
            cout<<"Dequeue is Empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }
    int end(){
        if(isEmpty()){
            cout<<"Dequeue is Empty";
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    void display(){
    if (isEmpty()) {
        cout << "Dequeue is Empty\n";
        return;
    }
    cout << "Dequeue contents: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}
    ~dequeue(){
        delete[] arr;
    }

};
int main(){
    dequeue d(5);
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);
    d.push_front(1);
    d.display(); // Output: Dequeue contents: 5 1 10 20
 
    cout << "Front: " << d.start() << endl; // Output: 5
    cout << "Rear: " << d.end() << endl;   // Output: 20
    d.pop_front();
    cout << "Front after pop: " << d.start() << endl; // Output: 10
    d.pop_back();
    cout << "Rear after pop: " << d.end() << endl;   // Output: 10
    return 0;
}