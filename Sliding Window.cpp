#include <iostream>
#include <queue>
using namespace std;

// Function to display the current contents of the sliding window
void display(queue<int> q)
{
    cout << "Sliding Window:";
    // Print all elements currently in the queue (the current window)
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    int arr[100]; // Array to hold the input elements
    int n, k;     // n = number of elements, k = size of the sliding window

    // Accept the number of elements from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Accept the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Accept the sliding window size
    cout << "Enter the size of the sliding window: ";
    cin >> k;

    queue<int> q; // Queue to represent the current sliding window

    // Fill the queue with the first (k-1) elements (preparing the window)
    for (int i = 0; i < k - 1; i++)
    {
        q.push(arr[i]);
    }

    // Loop through the array, maintaining a window of size k
    for (int i = k - 1; i < n; i++)
    {
        // Add the next element to the window
        q.push(arr[i]);
        // Display the current window
        display(q);
        // Remove the oldest element to keep the window size fixed
        q.pop();
    }

    return 0;
}
