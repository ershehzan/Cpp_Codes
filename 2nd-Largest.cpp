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
    for (int i = 0; i < n-1; i++)
    {
        cin >> arr[i];
        for (int i = 0; i < n-1; i++)
        {

            if (arr[i] > ans)
            {
                ans = arr[i];
            }
        }
    }

    // Second Largest
    int sec = INT_MIN;
    for (int i = 0; i < n-1; i++)
    {
        if (ans != arr[i])
        {
            sec = max(sec, arr[i]);
        }
    }
    cout << "Largest Element is : " << ans << endl;
    cout << "Second Largest Element is : " << sec << endl;
    return 0;
}
