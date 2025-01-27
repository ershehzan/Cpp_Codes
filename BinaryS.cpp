#include <iostream>
using namespace std;

int BinarySearch(int arr[], int target, int num)
{
    int start = 0, end = num- 1, mid;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            cout << "Element found at index ";
            return mid;
        }
        else if (arr[mid] <target)
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
    int num;
    cout << "Enter the index of array : ";
    cin >> num;
    cout << "Enter the elements of array : ";
    for (int i = 0; i <num; i++)
        cin >> arr[i];

    int target;
    cout << "Enter the number to search : " << endl;
    cin >> target;

    cout << BinarySearch(arr, target,num) << endl;
    return 0;
}
