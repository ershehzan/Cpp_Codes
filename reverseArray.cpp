#include <iostream>
using namespace std;

int main()
{

    int arr[1000];
    int n,i;
    cout"Enter the index: ";
        cin>>n;
    cout<<"Enter the Elements: ";
    for(i=0;i<n;i++){
cin>>arr[i];
    }

    int start = 0, end = n-1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    };
    for (int i = 0; i < n; i++)
        cout << arr[i];

    return 0;
}
