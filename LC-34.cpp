
//first and last occurrance in binary search problem of leet code 34.
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int key, int n)
{

int start=0,end=n-1,first=-1,last=-1,mid;
        while (start <= end)
    {
        int mid = start + (end-start) / 2;
        if (arr[mid] == key)
        {
            first=mid;
            end=mid-1;
        }
        else if (arr[mid] < key)
        {

            start = mid + 1;
        }
        else
        {

            end = mid - 1;
        }
    }
    start=0,end=n-1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
           last=mid;
           start=mid-1;
        }
        else if (arr[mid] < key)
        {

            start = mid + 1;
        }
        else
        {

            end = mid - 1;
        }
    } 
    return -1;
}
int main()
{
    int arr[1000];
    int n;
    cout << "Enter the index of array : ";
    cin >> n;
    cout << "Enter the elements of array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the number to search : " << endl;
    cin >> key;

    cout << BinarySearch(arr, key, n) << endl;
    return 0;
}