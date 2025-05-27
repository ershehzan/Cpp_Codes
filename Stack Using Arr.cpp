#include<iostream> // Include standard input/output stream library
using namespace std;

// Definition of Stack class using array implementation
class Stack{
    int *arr;      // Pointer to array for stack elements
    int top=-1;    // Index of the top element (initialized to -1, meaning stack is empty)
    int size;      // Maximum size of the stack

public:
    bool flag;     // Flag to check if stack is empty (1: empty, 0: not empty)

    // Constructor to initialize stack with a given size
    Stack(int s){
        size=s;         // Set the maximum size of stack
        top=-1;         // Initialize top to -1 (stack is empty)
        arr=new int[s]; // Allocate memory for the stack array
        flag=1;         // Set flag to 1 indicating stack is empty initially
    }

    // Push operation to add an element to the stack
    void push(int value){
        if(top==size-1){ // Check if stack is full (overflow condition)
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;                // Increment top to point to next position
            arr[top]=value;       // Add value to the top of stack
            cout<<"Pushed "<<value<<" to Stack"<<endl;
            flag=0;               // Set flag to 0 indicating stack is not empty
        }
    }

    // Pop operation to remove the top element from the stack
    void pop(){
        if(top==-1){ // Check if stack is empty (underflow condition)
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
            cout<<"Popped "<<arr[top]<<" from Stack"<<endl; // Print the popped value
            top--;          // Decrement top to remove the element
            if(top==-1)
                flag=1;     // If stack is empty after pop, set flag to 1
        }
    }

    // Peek operation to get the top element without removing it
    int peek(){
        if(top==-1){ // If stack is empty
            cout<<"Stack is empty"<<endl;
            return -1; // Return error value
        }
        else{
            return arr[top]; // Return the top element
        }
    }

    // isEmpty operation to check if stack is empty
    bool isEmpty(){
        return top==-1; // Return true if top is -1 (stack is empty)
    }

    // isSize operation to return current size (number of elements)
    int isSize(){
        return top+1; // Number of elements is top index + 1
    }
};

int main(){

    Stack s(5); // Create a stack of size 5

    // Example push operations (commented out)
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);

    s.push(-1); // Push -1 to the stack

    int value=s.peek(); // Get the top value

    if(s.flag==0){ // If stack is not empty
        cout<<"Top element is: "<<value<<endl;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }

    // More example usage (commented out)
    // cout<<s.peek()<<endl;
    // cout<<s.isEmpty()<<endl;
    // cout<<s.isSize()<<endl;

}
