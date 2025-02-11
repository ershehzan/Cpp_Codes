#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Array to store elements
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int i = 0;
    int val;
    cout << "Enter the value to remove: ";
    cin >> val;

    while (i < n)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[n - 1]; // Swap with last element
            n--;                 // Reduce size
        }
        else
        {
            i++; // Move to next element
        }
    }

    cout << "New size: " << n << endl;
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) // Corrected loop condition
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
