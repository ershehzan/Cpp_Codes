#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[1000];
    int n;
    cout << "Enter the index:";
    cin >> n;
    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // MAX   VALUE
        if (arr[i] > ans)
            ans = arr[i];
    }

    cout <<"The MAX Element in Array is : "<< ans;

    return 0;
}
