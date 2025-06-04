#include <iostream>
#include <stack>
using namespace std;

class Solution {
    stack<int> s1; // main stack

public:
    // Constructor
    Solution() {}

    void push(int x) {
        if (s1.empty()) {
            s1.push(x * 101 + x);  // First element: min = x
        } else {
            int currentMin = s1.top() % 101;
            s1.push(x * 101 + min(x, currentMin));  // Encode x and new min
        }
    }

    // Remove the top element
    void pop() {
        if (s1.empty())
            return;
        s1.pop();
    }

    // Return top element
    int peek() {
        if (s1.empty())
            return -1;
        return s1.top() / 101;
    }

    // Return minimum element in O(1)
    int getMin() {
        if (s1.empty())
            return -1;
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
            stack.push(x);
        } else if (op == 2) {
            stack.pop();
        } else if (op == 3) {
            cout << "Top element: " << stack.peek() << endl;
        } else if (op == 4) {
            cout << "Minimum element: " << stack.getMin() << endl;
        }
    }
    return 0;
}