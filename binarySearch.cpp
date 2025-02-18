// Binary search
#include <iostream>
using namespace std;

int main()
{

    int n, l = 0, r, m;

    cout << "Enter the Number to search: ";

    cin >> n;

    int arr[] = {1, 2, 4, 6, 7, 9, 10, 21, 34, 45, 65, 78, 99, 100, 107};

    int size = sizeof(arr) / sizeof(arr[0]);

    r = size - 1; // Set r to the last index of the array

    // Begin binary search

    while (l <= r)
    {

        m = l + (r - l) / 2; //  calculation of the mid index

        if (arr[m] == n)
        {

            cout << "Element is present at index " << m << endl;

            return 0; // Exit if element is found
        }

        else if (arr[m] < n)
        {

            l = m + 1; // Move to the right half
        }

        else
        {

            r = m - 1; // Move to the left half
        }
    }

    cout << "Element is not present in the array" << endl; // If element is not found

    return 0;
}
