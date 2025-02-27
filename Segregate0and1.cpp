#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start = 0, end = n - 1;
    while (start < end)
    {
        if (arr[start]  == 0)
        {
            start++;
        }
        else if (arr[end] == 0)
        {
            swap(arr[start], arr[end]);
            start++;
        }
        else
        {

            end--;
        }
    }

    // Print the final array after moving zeros to the right
    cout << "Array after moving zeros to the right: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
