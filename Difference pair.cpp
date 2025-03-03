#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 5, 8, 50, 80}; // Initialize the array
    int k;                                  // Difference to find
    cout << "Enter the difference: ";
    cin >> k;
    int start = 0, end = 1, n = arr.size() - 1; // Two pointers initialized to the beginning and end of the array

    // Two-pointer approach to find the pair with the given difference
    while (end < n)
    {
        int diff = arr[end] - arr[start]; // Calculate the difference between the elements at the two pointers

        if (diff == k)
        {
            // If the difference is equal to k, print the indices of the pair and exit
            cout << "Pair found: [" << start << "," << end << "]" << endl;
            return 1; // Exit after finding the first pair
        }
        else if (diff < k)
        {
            // If the difference is greater than k, move the 'end' pointer to the left to reduce the difference
            end++;
        }
        else
        {
            // If the difference is less than k, move the 'start' pointer to the right to increase the difference
            start++;
        }
    }

    // If no pair is found, print a message indicating that
    cout << "No pair found" << endl;
    return 0;
}