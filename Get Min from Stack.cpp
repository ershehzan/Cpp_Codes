#include <iostream>
#include <stack>
using namespace std;
// Solution class to implement a stack with getMin in O(1) time
class Solution {
                stack<int> s1; // Main stack to store values and minimums in encoded form
                 public:
    // Constructor
    Solution() {}

    // Pushes an element onto the stack
    void push(int x) {
        if (s1.empty()) {
            // If stack is empty, encode the value and itself as the min (x*101 + x)
            // Here, 101 is used as a multiplier to separate value and min in encoding
            s1.push(x * 101 + x);  // First element: min = x
        } else {
            // Get the current minimum from the top element (encoded)
            int currentMin = s1.top() % 101;
            // Push the new value with the updated min (min between x and current min)
            s1.push(x * 101 + min(x, currentMin));  // Encode x and new min
        }
    }

    // Removes the top element of the stack
    void pop() {
        if (s1.empty())
            return; // Do nothing if stack is empty
        s1.pop();
    }

    // Returns the top element of the stack (without removing it)
    int peek() {
        if (s1.empty())
            return -1; // Return -1 if stack is empty
        // Decoding: x is stored as x*101 + min, so divide by 101 to get x
        return s1.top() / 101;
    }

    // Returns the minimum element in the stack in O(1) time
    int getMin() {
        if (s1.empty())
            return -1; // Return -1 if stack is empty
        // Decoding: min is stored in the lower part (modulo 101)
        return s1.top() % 101;
    }
};

int main() {
    Solution stack;
    int q;
    cout << "Enter number of operations: ";
    cin >> q;
    cout << "Operations:\n1 x (push x)\n2 (pop)\n3 (peek)\n4 (getMin)\n";
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            stack.push(x); // Push operation
        } else if (op == 2) {
            stack.pop(); // Pop operation
        } else if (op == 3) {
            // Peek/top operation
            cout << "Top element: " << stack.peek() << endl;
        } else if (op == 4) {
            // Get minimum operation
            cout << "Minimum element: " << stack.getMin() << endl;
        }
    }
    return 0;
}


