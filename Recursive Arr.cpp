// Include the iostream library for input and output operations
#include <iostream>
using namespace std;

// Recursive function to print the elements of an array in sequence
// Parameters:
// - `arr[]`: The array whose elements need to be printed
// - `index`: The current index of the array being processed
void print(int arr[], int index)
{
    // Base case: If the index is -1, all elements have been printed, so return
    if (index == -1)
    {
        return;
    }

    // Recursive call: Process the previous element in the array
    print(arr, index - 1);

    // Print the current element of the array
    cout << arr[index] << " ";
}

int main()
{
    // Initialize an array with 5 elements
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Call the recursive print function, starting from the last index of the array (4)
    print(arr, 4);

    // Return 0 to indicate successful program termination
    return 0;
}
