// First come first serve (FCFS) disk scheduling algorithm: 
// The FCFS disk scheduling algorithm is a simple and straightforward approach to managing disk requests.
// It processes requests in the order they arrive without prioritization or optimization.
#include <algorithm> // For generic algorithms like sorting (not used here but included)
#include <iostream>  // For input and output operations
#include <cmath>     // For mathematical operations like abs()
using namespace std; // To avoid writing std:: repeatedly

int main(){
    int arr[100]; // Array to hold disk requests
    int n, head;  // n: number of requests, head: initial position of the disk head

    // Prompt the user to input the number of disk requests
    cout << "Enter the number of requests: ";
    cin >> n;
    // Prompt the user to input the disk requests
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Store each request in the array
    }
    // Prompt the user to input the initial position of the disk head
    
    cout << "Enter the head position: ";
    cin >> head;
    
    int SeekTime = 0; // Variable to accumulate the total seek time
    // Process each request in the order it appears in the array
    for (int i = 0; i < n; i++)
    {
        // Calculate the seek time for the current request
        SeekTime += abs(arr[i] - head);

        // Update the head position to the current request
        head = arr[i];
    }
    // Output the total seek time calculated using the FCFS algorithm
    cout << "Total seek time (FCFS): " << SeekTime << endl;
    return 0; // Indicate that the program executed successfully
}












