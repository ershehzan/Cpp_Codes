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
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // MIN VALUE
        if (arr[i] < ans)
            ans = arr[i];
    }

    cout <<"The Minimum Element in Array is : "<< ans;

    return 0;
}
