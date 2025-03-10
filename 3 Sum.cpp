#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    vector<int> arr = {1, 8, 6, 4, 10, 45};

    int x;
    cout << "Enter the target sum: ";
    cin >> x;

    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        int ans = x - arr[i];
        int start = i + 1, end = n - 1;
        while (start < end)
        {
            if (arr[start] + arr[end] == ans)
            {
                cout << "Pair found"<<endl;
                return 1;
            }
            else if (arr[start] + arr[end] < ans)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    cout << "Pair not found"<<endl;
    return 0;
}
