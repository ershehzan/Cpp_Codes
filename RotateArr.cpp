#include <iostream>
using namespace std;
int main()
{
    int i;
    int arr[1000] = {1, 2, 3, 4, 5, 6, 7, 8};
    // Store the last element in a temporary variable
    int temp = arr[7];

    // Shift elements to the right
    for (i = 7; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    // Place the last element at the beginning
    arr[0] = temp;

    cout << "Rotated array: ";
    for (i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}