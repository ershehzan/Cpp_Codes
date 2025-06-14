#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {}

    bool empty() {
        return st1.empty() && st2.empty();
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (empty())
            return 0;

        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int element = st2.top();
        st2.pop();
        return element;
    }

    int peek() {
        if (empty())
            return 0;

        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // Should print 1
    cout << "Pop: " << q.pop() << endl;            // Should print 1
    cout << "Front element: " << q.peek() << endl; // Should print 2
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl; // Should print No

    q.pop();
    q.pop();
    cout << "Is empty after popping all: " << (q.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}