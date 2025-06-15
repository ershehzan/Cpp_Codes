#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to return the first negative number in the queue
int display(queue<int> q)
{
    // Traverse the queue until it's empty
    while (!q.empty())
    {
        // If the front element is negative, return it
        if (q.front() < 0)
        {
            return q.front();
        }
        // Otherwise, remove the front element and continue
        q.pop();
    }
    // If no negative number is found, return 0
    return 0; 
};

int main()
{
    int arr[100]; // Array to hold the elements
    int n, k;     // n = number of elements, k = size of the sliding window

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the size of the sliding window: ";
    cin >> k;

    queue<int> q; // Queue to store elements of the current window

    // Fill the queue with the first (k-1) elements
    for (int i = 0; i < k - 1; i++)
    {
        q.push(arr[i]);
    }

    vector<int> ans; // Vector to store the answer for each window

    // Process each sliding window of size k
    for (int i = k - 1; i < n; i++)
    {
        // Add the next element to the queue (current window)
        q.push(arr[i]);
        // Find the first negative number in the current window and store it
        ans.push_back(display(q));
        // Remove the oldest element to slide the window
        q.pop();
    }

    cout << "First negative number in each sliding window: ";
    // Output the result for each window
    for (size_t i = 0; i < ans.size(); i++)
    {
        if (ans[i] != 0)
        {
            cout << ans[i] << " ";
        }
        else
        {
            cout << "No negative number in this window ";
        }
    }
    return 0;
}
