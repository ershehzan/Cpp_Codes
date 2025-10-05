#include <iostream> 
#include <climits> // Include library for INT_MAX and INT_MIN constants
using namespace std; // Use the standard namespace

int main(){
    int arr[5] = {13, 24, 35, 40, 51}; // Declare and initialize an array with 5 elements
    
    int i; // Loop variable
    int ans = INT_MAX; // Initialize ans with the maximum possible integer value
    
    // Finding the minimum value in the array
    for (i = 0; i < 5; i++)
    {
        if (arr[i] < ans) // If the current element is smaller than ans
            ans = arr[i]; // Update ans with the smaller value
    }
    cout << "Min value is : ";
    cout << ans << endl; // Print the minimum value
    
    // Finding the maximum value in the array
    ans = INT_MIN; // Reinitialize ans with the minimum possible integer value
    
    for (i = 0; i < 5; i++)
    {
        if (arr[i] > ans) // If the current element is greater than ans
            ans = arr[i]; // Update ans with the greater value
    }
    cout << "Max value is : ";
    cout << ans << endl; // Print the maximum value

    return 0; 
}

