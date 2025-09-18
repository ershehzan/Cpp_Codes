#include <iostream>
#include <vector>
using namespace std;
// Function to maintain the min heap property for a subtree rooted at index 'i'.
// 'n' is the total number of elements in the heap (array).
void heapify(vector<int>& arr, int i, int n)
{
    int smallest = i;          // Assume current index as smallest
    int left = 2 * i + 1;      // Index of left child
    int right = 2 * i + 2;     // Index of right child

    // Check if left child exists and is smaller than current smallest
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Check if right child exists and is smaller than current smallest
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If the smallest is not the current index, swap and continue heapifying
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);      // Swap with smaller child
        heapify(arr, smallest, n);        // Recursively heapify the affected subtree
    }
}

// Function to build a min heap from an unsorted array
void buildMinheap(vector<int>& arr, int n)
{
    // Start from the last non-leaf node and move upward to the root
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);  // Apply heapify to each node
}

// Function to print the elements of the heap
void print(const vector<int>& arr)
{
    cout << "Min Heap: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n; // Input number of elements

    vector<int> arr(n); // Declare a vector of size n
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Input array elements

    // Build a min heap from the input array
    buildMinheap(arr, n);

    // Print the resulting min heap
    print(arr);

    return 0;
}

