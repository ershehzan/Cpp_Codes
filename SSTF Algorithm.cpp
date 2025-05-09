//SSTF (Shortest Seek Time First) Disk Scheduling Algorithm
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
    sort(begin(arr), begin(arr) + n);
    int Seek_time = 0;

    Seek_time += head - arr[0] + arr[n - 1] - arr[0];

    cout << "Total seek time (SSTF): " << Seek_time << endl;
    

    return 0;
}