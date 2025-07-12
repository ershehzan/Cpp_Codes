#include <iostream>
#include <vector>
using namespace std;

// Function to maintain the max heap property for a subtree rooted at index 'i'.
// 'n' is the total number of elements in the heap (array).
void heapify(vector<int>& arr, int i, int n)
{
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // Left child index
    int right = 2 * i + 2;     // Right child index

    // If the left child is within bounds and greater than the current largest, update largest
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is within bounds and greater than the current largest, update largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap and recursively heapify the affected subtree
    if (largest != i)
    {
        swap(arr[i], arr[largest]);      // Swap root with largest
        heapify(arr, largest, n);        // Recursively heapify the affected subtree
    }
}

// Function to build a max heap from an unsorted array
void buildMaxheap(vector<int>& arr, int n)
{
    // Start from the last non-leaf node and move upwards to root
    // Last non-leaf node = (n / 2) - 1
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n); // Call heapify for each node
}

// Function to print the elements of the heap
void print(const vector<int>& arr)
{
    cout << "Max Heap: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n; // Take the size of the array as input

    vector<int> arr(n); // Declare a vector of size n
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Input the array elements

    // Convert the input array into a max heap
    buildMaxheap(arr, n);

    // Print the final max heap
    print(arr);

    return 0;
}
