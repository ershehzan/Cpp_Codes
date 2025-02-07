#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Initializing the array with 10 elements
    int arr[10] = {2, 4, 5, 6, 7, 8, 9, 1, 56, 11};

    // Variable to store the largest element, initialized to the smallest possible integer
    int ans = INT_MIN;

    // Loop to find the largest element in the array
    for (int i = 0; i < 10; i++)
    {
        // If the current element is greater than 'ans', update 'ans'
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }

    // Variable to store the second largest element, initialized to the smallest possible integer
    int sec = INT_MIN;

    // Loop to find the second largest element
    for (int i = 0; i < 10; i++)
    {
        // If the current element is not equal to the largest element, update 'sec' with the maximum value
        if (arr[i] != ans)
        {
            sec = max(sec, arr[i]);
        }
    }

    // Output the largest and second-largest elements
    cout << "Largest Element is : " << ans << endl;
    cout << "Second Largest Element is : " << sec << endl;

    return 0;
}
