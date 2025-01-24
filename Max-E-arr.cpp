#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[10] = {2, 4, 5, 6, 7, 8, 9, 1, 56, 11};
    int ans = INT_MAX;
    for (int i = 0; i < 10; i++)
    {
        // MIN VALUE
        if (arr[i] < ans)
            ans = arr[i];
    }

    cout << ans;

    return 0;
}
