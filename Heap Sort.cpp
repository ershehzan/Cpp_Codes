#include <iostream>
#include <vector>
using namespace std;
// Iterative version of heapify to maintain the max-heap property
void heapify(vector<int> &arr, int i, int n){
    
    while (i < n){
        int largest = i;           // Assume current index is largest
        int left = 2 * i + 1;      // Index of left child
        int right = 2 * i + 2;     // Index of right child

        // Check if left child exists and is greater than current largest
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // Check if right child exists and is greater than current largest
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not the current node, swap and continue
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            i = largest; // Move to the largest child and repeat
        }
        else
        {
            break; // Heap property is satisfied
        }
    }
}

// Function to build a max heap from an unsorted array
void buildMaxheap(vector<int> &arr, int n)
{
    // Start from the last non-leaf node and apply heapify
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);
}

// Function to perform heap sort using max heap
void heapsort(vector<int> &arr, int n)
{
    // Build max heap first
    buildMaxheap(arr, n);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root (maximum) to the end
        swap(arr[i], arr[0]);
        // Call heapify on the reduced heap
        heapify(arr, 0, i); // 'i' becomes the new size
    }
}

// Function to print the elements of an array
void print(const vector<int> &arr)
{
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapsort(arr, n); // Perform Heap Sort

    cout << "Sorted array (Ascending Order): ";
    print(arr); // Print sorted array
    return 0;
}












