#include <iostream>
using namespace std;

int subsum(int arr[], int index,int sum,int n)
{

    if(sum==0)
    return 1;
    if(index==n|| sum<0)
    return 0;

    return subsum(arr, index+1 , sum,n) + subsum(arr, index, sum - arr[index],n);
}

int main()
{
    int arr[] = {2,3,4};
    int sum = 6;

    cout << subsum(arr, 0, sum,3); // Call the function to find the target sum

    return 0;
}