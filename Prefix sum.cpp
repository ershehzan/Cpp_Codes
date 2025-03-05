#include <iostream>
using namespace std;
int main()
{

    int arr[1000] = {6, 4, 12, -3, 7, 14, 28};
    int n = 7;
    int prefix[1000];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    cout << "Prefix sum array: ";
    for (int i = 0; i < n; i++)
    {
        cout << prefix[i] << " ";
    }

    return 0;
}