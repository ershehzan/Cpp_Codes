#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> st;
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        return q;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    queue<int> q;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    q = solution.reverseQueue(q);

    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}