#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the difference: ";
    cin >> k;
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        if (i != j && arr[j] - arr[i] == k)
        {
            cout << "Pair found at index " << "[" << i << " and " << j << "]" << endl;
            return 0;
        }
        else if (arr[j] - arr[i] < k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << "Pair not found" << endl;
    return 0;
}