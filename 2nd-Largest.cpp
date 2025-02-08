#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Largest
    int arr[1000];
    int n;
    int ans = INT_MIN;
    cout << "Enter the index: ";
    cin >> n;

    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)  // Fixed loop condition
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)  // Moved max calculation outside input loop
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }

    // Second Largest
    int sec = INT_MIN;
    for (int i = 0; i < n; i++)  // Fixed loop condition
    {
        if (arr[i] != ans && arr[i] > sec)  // Fixed second largest logic
        {
            sec = arr[i];
        }
    }

    cout << "Largest Element is : " << ans << endl;
    cout << "Second Largest Element is : " << sec << endl;
    return 0;
}
