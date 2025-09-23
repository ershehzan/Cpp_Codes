#include <iostream>
using namespace std;

int main(){
    int arr[1000]; // Array to store elements
    // Input array size
    int n;
    cout << "Enter the size of the Array: ";
    cin >> n;
    
    // Input array elements
    cout << "Enter the elements of the Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Removing duplicate elements
    for (int i = 0; i < n - 1; i++) // Outer loop to iterate through each element
    {
        for (int j = i + 1; j < n;) // Inner loop to compare with the rest of the array
        {
            if (arr[i] == arr[j]) // If a duplicate is found
            {
                // Shift elements to the left to remove the duplicate
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--; // Reduce the size of the array
                // No need to increment `j` as the next element shifts into `j`'s place
            }
            else
            {
                j++; // Move to the next element only if no deletion occurs
            }
        }
    }
    
    // Output the array after removing duplicates
    cout << "Array after deletion of duplicate elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}









