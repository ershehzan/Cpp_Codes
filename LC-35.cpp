//Search insert problem Leet code 35
#include<iostream>

using namespace std;
int main()
{

    int arr[1000]={1,2,4,5,7,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target;

 //solution start from here
int start = 0, end = arr.size() - 1, ans = arr.size(), mid;

while (start <= end)
{
    mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        ans = mid;
        break;
    }
    else if (arr[mid] < target)
    {
        start = mid + 1;
    }
    else
    {
        ans = mid;
        end = mid - 1;
    }
}
return ans;
//end here
}