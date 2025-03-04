#include <iostream>
#include <vector>
using namespace std;

bool divide(vector<int> arr)
{
    int n = arr.size();
    int prefix = 0, total_sum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    // Check if the total sum is even
    if (total_sum % 2 != 0)
    {
        cout << "The array cannot be divided into two equal sum subarrays" << endl;
        return false;
    }

    // Calculate the prefix sum and check if it equals half of the total sum
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        if (prefix == total_sum / 2)
        {
            cout << "The array can be divided into two equal sum subarrays" << endl;
            return true;
        }
    }

    cout << "The array cannot be divided into two equal sum subarrays" << endl;
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    divide(v);
    return 0;
}