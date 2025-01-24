#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Largest
    int ans = INT_MIN;
  int arr[10] = {2, 4, 5, 6, 7, 8, 9, 1, 56, 11};
    for (int i = 0; i < 10; i++)
    {

        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }
    // Second Largest
    int sec = INT_MIN;
    for (int i = 0; i < 10; i++)
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
