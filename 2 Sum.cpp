#include <iostream>
using namespace std; 

int main()
{  // Initialize an array with sorted elements (Two-pointer approach works on sorted arrays)
    int arr[1000] = {3, 4, 6, 8, 11, 12, 34, 41};
    int n = 8; // Number of elements in the array
    int target; // Variable to store the target sum
    cout << "Enter the target: ";
    cin >> target;
    // Initialize two pointers
    int start = 0;   // Points to the first element
    int end = n - 1; // Points to the last element

    // Two-pointer approach to find a pair that sums up to the target value
    while (start < end) 
    {
        int sum = arr[start] + arr[end]; // Calculate the sum of elements at start and end indexes

        if (sum == target)
        { // If the sum matches the target
            cout << "Pair found: [" << arr[start] << "," << arr[end] << "]" << endl;
            
            cout << "Pair found at Index: [" << start << "," << end << "]" << endl;
            
            return 0; // Exit the program as we found a valid pair
        }
        else if (sum > target)
        { // If sum is greater, move the end pointer left to reduce sum
            end--;
        }
        else
        { // If sum is smaller, move the start pointer right to increase sum
            start++;
        }
    }
   
    // If no pair is found after the loop completes
    cout << "No pairs found." << endl;
    return 0;
}














