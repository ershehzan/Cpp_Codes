#include <iostream>
#include <queue>
using namespace std;

void display(queue<int> q)
{
    cout << "Sliding Window:";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    int arr[100];
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the size of the sliding window: ";
    cin >> k;

    queue<int> q;

    for (int i = 0; i < k - 1; i++)
    {
        q.push(arr[i]);
    }
    for (int i = k - 1; i < n; i++)
    {
        q.push(arr[i]);
        display(q);
        q.pop();
    }
    return 0;
}