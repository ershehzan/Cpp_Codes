#include <iostream>
using namespace std;

// Class to represent a Max Heap
class MaxHeap
{
public:
    int *arr;        // Dynamic array to store heap elements
    int size;        // Current number of elements in the heap
    int total_size;  // Maximum capacity of the heap

    // Constructor: Initializes the heap with given capacity
    MaxHeap(int n)
    {
        arr = new int[n];   // Allocate memory for heap array
        size = 0;           // Initially the heap is empty
        total_size = n;     // Store the maximum number of elements
    }

    // Function to insert a new element into the Max Heap
    void insert(int val)
    {
        if (size == total_size)
        {
            cout << "Heap is full" << endl;
            return;
        }

        // Step 1: Insert the element at the end of the array
        arr[size] = val;
        int index = size;
        size++;

        // Step 2: Bubble up the element to maintain Max Heap property
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            // Swap the current element with its parent if it's greater
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;  // Move to the parent index
        }

        cout << "Inserted " << val << " into the heap." << endl;
    }

    // Function to print all elements of the heap
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

    // Function to restore Max Heap property starting from a given index
    void Heapify(int index)
    {
        int largest = index;              // Assume current node is largest
        int left = 2 * index + 1;         // Left child index
        int right = 2 * index + 2;        // Right child index

        // Check if left child is greater than the current largest
        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }

        // Check if right child is greater than the current largest
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        // If the largest value is not the current node, swap and recurse
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);  // Recursive call for the affected subtree
        }
        else
        {
            // Only print when no further swapping is needed
            cout << "Heapify complete for index " << index << endl;
        }
    }

    // Function to delete the maximum (root) element from the heap
    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap is empty, cannot delete" << endl;
            return;
        }

        cout << "Deleted " << arr[0] << " from the heap." << endl;

        // Move the last element to the root
        swap(arr[0], arr[size - 1]);
        size--;  // Reduce heap size by 1 (effectively removing last element)

        if (size == 0)
        {
            cout << "Heap is now empty after deletion." << endl;
            return;
        }

        // Restore heap property from root
        Heapify(0);
    }

    // Function to get the maximum element (root) without deleting
    int getMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;  // Return -1 as error value
        }
        return arr[0];  // Return the root element (max)
    }

    // Destructor to release allocated memory
    ~MaxHeap()
    {
        delete[] arr;
    }
};

// Driver code to test the MaxHeap class
int main()
{
    int n;
    cout << "Enter the size of the heap: ";
    cin >> n;

    // Create a MaxHeap object with capacity 'n'
    MaxHeap h(n);

    // Input values to be inserted into the heap
    cout << "Enter " << n << " elements to insert into the heap: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        h.insert(val);  // Insert value into heap
    }

    h.Delete();         // Delete the root (maximum element)
    h.print();          // Print remaining elements of the heap

    return 0;
}