#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    vector<int> arr = {5, 3, 8, 6, 2, 9, 10, 7, 4, 10};
    int n = 10;

    // sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arr.erase(arr.begin() + i);
            i--;
            n--;
        }
    }
    cout<<"After removing duplicates: ";
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}