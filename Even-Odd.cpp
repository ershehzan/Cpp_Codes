#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};

    // Number of elements in the array
    int n = 10;

    // Variables to count even and odd numbers
    int even = 0, odd = 0;

    // Loop through the array to count even and odd numbers
    for (int i = 0; i < n; i++)
    {
        // Check if the current element is even
        if (arr[i] % 2 == 0)
        {
            even++; // Increment the even counter
        }
        else
        {
            odd++; // Increment the odd counter
        }
    }

    // Print the count of even numbers
    cout << "Number of even numbers: " << even << endl;
    // Print the count of odd numbers
    cout << "Number of odd numbers: " << odd << endl;

    return 0;
}