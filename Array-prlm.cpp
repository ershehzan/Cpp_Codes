#include <iostream>
using namespace std;

int main()
{
    int arr[1000];

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

    // Removing duplicates
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
                // Shift elements to the left
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--; // Reduce array size
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
