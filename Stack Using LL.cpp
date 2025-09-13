// Include the input-output stream library to use cout and cin
#include <iostream>
using namespace std;

// Node class represents each element in the stack
class Node{
public:
    int data;        // Value stored in the node
    Node *next;      // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(int value)
    {
        data = value;    // Assign value to data
        next = NULL;     // Set next pointer to NULL
    }
};

// Stack class implements stack functionality using linked list
class Stack
{
    Node *top;   // Pointer to the top element of the stack
    int size;    // Current size of the stack

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        top = NULL;   // Top is NULL when stack is empty
        size = 0;     // Size is 0 for an empty stack
    }

    // Push operation: Adds an element to the top of the stack
    void push(int value)
    {
        Node *temp = new Node(value); // Create a new node with the given value

        // Check if memory allocation failed
        if (temp == NULL)
        {
            cout << "Stack Overflow" << endl; // Stack overflow error
            return;
        }
        else
        {
            temp->next = top; // Set new node's next to current top
            top = temp;       // New node becomes the new top
            size++;           // Increment size
            cout << "Pushed " << value << " to Stack" << endl;
        }
    };

    // Pop operation: Removes the top element from the stack
    void pop()
    {
        // Check if stack is empty
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl; // Stack underflow error
            return;
        }
        else
        {
            Node *temp = top;           // Store the current top node
            cout << "Popped " << temp->data << " from Stack" << endl;
            top = top->next;            // Move top to the next node
            delete temp;                // Free memory of the old top node
            size--;                     // Decrement size
        }
    };

    // Peek operation: Returns the value at the top without removing it
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl; // Nothing to peek at
            return -1;                        // Return error value
        }
        else
        {
            cout << "Peeked " << top->data << " from Stack" << endl;
            return top->data;                 // Return value of the top node
        }
    };

    // isEmpty: Checks whether the stack is empty
    bool isEmpty()
    {
        return top == NULL; // Stack is empty if top is NULL
    };

    // isSize: Returns the number of elements in the stack
    int isSize()
    {
        return size;
    };
};

// Main function demonstrating stack operations
int main()
{
    Stack s;          // Create a stack object

    s.push(10);       // Push 10 onto stack
    s.push(20);       // Push 20 onto stack
    s.push(30);       // Push 30 onto stack

    cout << s.peek(); // Peek at the top element (should be 30)

    // Program ends, stack will be destroyed
}

