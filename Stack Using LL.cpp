#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    // push operation
    void push(int value)
    {
        Node *temp = new Node(value);
        if (temp == NULL)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            temp->next = top;
            top = temp;
            size++;
            cout << "Pushed " << value << " to Stack" << endl;
        }
    };
    // pop operation
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else
        {
            Node *temp = top;
            cout << "Popped " << temp->data << " from Stack" << endl;
            top = top->next;
            delete temp;
            size--;
        }
    };
    //  peek operation
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            cout << "Peeked " << top->data << " from Stack" << endl;
            return top->data;
     
        }
    };
    bool isEmpty()
    {
        return top == NULL;
    };

    int isSize()
    {
        return size;
    };
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout<<s.peek();

  
}