#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> p; // max heap
    p.push(10);
    p.push(20);
    p.push(5);
    cout << "Max Heap elements: ";
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);

    cout << "Min Heap elements: ";
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}