#include <iostream>
using namespace std;
int main()
{
    int i;
    int arr[1000];
    // Store the last element in a temporary variable
    int temp = arr[n-1];

    // Shift elements to the right
    for (i = n-1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    // Place the last element at the beginning
    arr[0] = temp;

    cout << "Rotated array: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
