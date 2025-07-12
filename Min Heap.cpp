#include <iostream>
using namespace std;

// Class representing a Min Heap data structure
class MinHeap
{
public:
    int *arr;        // Dynamic array to store heap elements
    int size;        // Current number of elements in the heap
    int total_size;  // Maximum capacity of the heap

    // Constructor to initialize the heap with given capacity
    MinHeap(int n)
    {
        arr = new int[n];  // Allocate memory for the heap
        size = 0;          // Initially heap is empty
        total_size = n;    // Set maximum capacity
    }

    // Destructor to free allocated memory and prevent memory leaks
    ~MinHeap()
    {
        delete[] arr;
    }

    // Insert a new value into the heap and maintain the min-heap property
    void insert(int val)
    {
        if (size == total_size)
        {
            cout << "Heap is full" << endl;
            return;
        }

        // Insert the new element at the end of the array
        arr[size] = val;
        int index = size;  // Start from the newly inserted index
        size++;            // Increase heap size

        // Bubble up the inserted element to its correct position
        while (index > 0 && arr[(index - 1) / 2] > arr[index])
        {
            // Swap with parent if it's greater than the current element
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;  // Move to parent index
        }

        cout << "Inserted " << val << " into the heap." << endl;
    }

    // Print all elements of the heap in array order
    void print()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Heapify function to restore the min-heap property from a given index downward
    void heapify(int index)
    {
        int smallest = index;               // Assume current index is the smallest
        int left = 2 * index + 1;           // Left child index
        int right = 2 * index + 2;          // Right child index

        // Compare with left child
        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        // Compare with right child
        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        // If a smaller child is found, swap and continue heapifying
        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            heapify(smallest);  // Recursively heapify the affected subtree
        }
    }

    // Delete the root (minimum element) from the heap
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty, cannot delete" << endl;
            return;
        }

        cout << "Deleted " << arr[0] << " from the heap." << endl;

        // Move the last element to the root and reduce heap size
        swap(arr[0], arr[size - 1]);
        size--;

        // Restore the min-heap property starting from the root
        if (size > 0)
            heapify(0);
    }

    // Return the minimum (root) element of the heap
    int getMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;  // You could throw an exception here instead
        }
        return arr[0];
    }
};

int main()
{
    int n;
    cout << "Enter the size of the heap: ";
    cin >> n;

    // Create a MinHeap of capacity n
    MinHeap h(n);

    cout << "Enter " << n << " elements to insert into the heap: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        h.insert(val);  // Insert each value into the heap
    }

    h.print();          // Display the heap elements

    h.deleteRoot();     // Delete the root element (minimum)
    h.print();          // Display the heap after deletion

    return 0;
}