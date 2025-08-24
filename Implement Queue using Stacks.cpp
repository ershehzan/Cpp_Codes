#include <iostream>
#include <stack>
using namespace std;
// Class to implement a queue using two stacks
class MyQueue {
    stack<int> st1; // Stack for enqueue operations
    stack<int> st2; // Stack for dequeue/peek operations

public:
    // Constructor
    MyQueue() {}

    // Check if the queue is empty
    bool empty()
    {
        // The queue is empty only if both stacks are empty
        return st1.empty() && st2.empty();
    }

    // Add an element to the end of the queue
    void push(int x)
    {
        // Always push the new element onto st1
        st1.push(x);
    }

    // Remove and return the element at the front of the queue
    int pop() {
        // If the queue is empty, return 0 (could throw an exception in practice)
        if (empty())
            return 0;

        // If st2 is empty, move all elements from st1 to st2 (reversing order)
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        // The top of st2 is the front of the queue
        int element = st2.top();
        st2.pop();
        return element;
    }

    // Return the element at the front of the queue without removing it
    int peek() {
        // If the queue is empty, return 0 (could throw an exception in practice)
        if (empty())
            return 0;

        // If st2 is empty, move all elements from st1 to st2 to access the front
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        // Return the top of st2, which is the front of the queue
        return st2.top();
    }
};

int main() {
    MyQueue q;

    // Add elements to the queue: 1, 2, 3
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // Should print 1
    cout << "Pop: " << q.pop() << endl;            // Should print 1
    cout << "Front element: " << q.peek() << endl; // Should print 2
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl; // Should print No

    // Remove all elements
    q.pop();
    q.pop();
    cout << "Is empty after popping all: " << (q.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}




