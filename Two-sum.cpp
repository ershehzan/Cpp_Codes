#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Array to store elements
    int n, target; // Variables to store the number of elements and target sum

    // Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Input the target sum value
    cout << "Enter the Target: ";
    cin >> target;

    // Iterate through the array to find pairs that sum up to the target
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // Avoid duplicate pairs by starting from i+1
        {
            if (arr[i] + arr[j] == target) // Check if the sum matches the target
                cout << "Pair found at indices: [" << i << "," << j << "]" << endl;
        }
    }

    return 0;
}
