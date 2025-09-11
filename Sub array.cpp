#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array can be divided into two equal sum subarrays
bool divide(vector<int> arr)
{
    int n = arr.size(); // Get the size of the array
    int prefix = 0, total_sum = 0; // Initialize prefix sum and total sum variables

    // Step 1: Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i]; // Add each element to the total sum
    }

    // Step 2: Check if the total sum is odd
    // If total sum is odd, it's impossible to split into two equal sum subarrays
    if (total_sum % 2 != 0)
    {
        cout << "The array cannot be divided into two equal sum subarrays because the total sum is odd." << endl;
        return false; // Return false since division is not possible
    }

    // Step 3: Iterate through the array to calculate the prefix sum
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i]; // Add the current element to prefix sum

        // Step 4: Check if the prefix sum equals half of the total sum
        if (prefix == total_sum / 2)
        {
            // If prefix sum is exactly half of the total sum, the array can be split
            cout << "The array can be divided into two equal sum subarrays." << endl;
            return true; // Return true since division is possible
        }
    }
    // Step 5: If loop completes and no equal split is found, return false
    cout << "The array cannot be divided into two equal sum subarrays." << endl;
    return false;
}

int main(){
    
    int n; // Variable to store array size

    // Prompt user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n); // Declare a vector to store array elements

    // Prompt user to enter the array elements
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; // Take input for each element
    }

    // Call the divide function to check if the array can be split into two equal sum subarrays
    divide(v);

    return 0; // Exit the program
}



