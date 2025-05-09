// SSTF (Shortest Seek Time First) Disk Scheduling Algorithm
// The SSTF algorithm prioritizes servicing the disk request that is closest
// to the current position of the disk head. This reduces the total seek time
// compared to other algorithms like FCFS.

#include <algorithm> // For sorting the requests
#include <iostream>  // For input and output operations
#include <cmath>     // For mathematical calculations like abs()
using namespace std; // To avoid writing std:: repeatedly

int main()
{
    int arr[100]; // Array to store disk requests
    int n, head;  // n: number of requests, head: initial position of the disk head

    // Prompt the user to input the number of disk requests
    cout << "Enter the number of requests: ";
    cin >> n;

    // Input the disk requests
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Store each request in the array
    }

    // Input the initial position of the disk head
    cout << "Enter the head position: ";
    cin >> head;

    // Sort the requests to facilitate finding the shortest seek time
    // This is crucial for the SSTF algorithm
    sort(begin(arr), begin(arr) + n);

    int Seek_time = 0; // Variable to store the total seek time

    // Calculate the total seek time for SSTF
    // Here, we assume the disk head first moves to the smallest request,
    // then to the largest request, covering the entire range of requests.
    Seek_time += head - arr[0] + arr[n - 1] - arr[0];

    // Output the total seek time calculated using the SSTF algorithm
    cout << "Total seek time (SSTF): " << Seek_time << endl;

    return 0; // Indicate successful program termination
}
