#include <iostream>
using namespace std;
int main()
{

 int n; // Declare variables: 'n' for array size, 'i' and 'j' for loops, 'key' for sorting
    int arr[1000];    // Declare an array of size 1000 to store user input

    // Prompt the user to enter the number of elements in the array
    cout << "Enter the Index: ";
    cin >> n; // Read the number of elements from user input

    // Prompt the user to enter the array elements
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each element and store it in the array
    }

    for (int i = 0; i < n-1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout <<"Sorted Array:" ;
    for (int i = 0; i < n; i++)
    {
       cout<<arr[i] << " ";
    }

    return 0;
}
