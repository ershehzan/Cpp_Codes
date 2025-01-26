#include <iostream>
using namespace std;
int main()
{

    int arr[1000] = {4, 5, 6, 7, 8, 10, 1, 2};
    int start = 0, end = 7, ans = arr[0];

    while (start <= end)
    {

        int mid = start + (end - start) / 2;// to avoid overflow
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            ans = arr[mid];
            end = mid - 1;
        }
    }
    cout <<"Minimum element in rotated array is "<< ans<<endl;
    return 0;
}
