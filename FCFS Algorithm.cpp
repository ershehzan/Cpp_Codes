// First come first serve (FCFS) disk scheduling algorithm: The FCFS disk scheduling algorithm is a simple and straightforward approach to managing disk requests. It processes requests in the order they arrive, without any prioritization or optimization.

#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int arr[100];
    int n, head;
    cout << "Enter the number of requests: ";
    cin >> n;
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the head position: ";
    cin >> head;

    int SeekTime = 0;

    for (int i = 0; i < n; i++)
    {
        SeekTime += abs(arr[i] - head);
        head = arr[i];
    }

    cout << "Total seek time (FCFS): " << SeekTime << endl;

    return 0;
}