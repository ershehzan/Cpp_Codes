// Book Allocation
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int arr[1000] = {12, 36, 67, 90};

    int start = 0, end = 3, mid, ans;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int page = 0, count = 1;

        for (int i = 0; i < n; i++)
        {
            if (start < arr[i])
            {
                start = arr[i];
                end += arr[i];
            }
            page += arr[i];
            if (page > mid)

                count++;
            page = arr[i];
        }
        if (count <= n)
        {

            ans = mid;
            end = mid - 1;
        }
        else
        {

            start = mid + 1;
        }
    }
    cout << " " << ans;
    return 0;
}