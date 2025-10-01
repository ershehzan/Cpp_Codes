#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // Initialize a vector with some values
    vector<int> arr = {5, 3, 8, 6, 2, 9, 10, 7, 4, 10};
    int n = 10;  // Size of the vector

    // Bubble sort algorithm to sort the vector in ascending order
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap the elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Loop to remove duplicate elements from the sorted vector
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            // Erase the duplicate element
            arr.erase(arr.begin() + i);
            i--;  // Adjust the index after removal
            n--;  // Decrease the size of the vector
        }
    }

    // Print the vector after removing duplicates
    cout << "After removing duplicates: ";
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;  
}

