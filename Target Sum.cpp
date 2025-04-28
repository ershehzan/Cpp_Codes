#include <iostream>
using namespace std;

bool find(int arr[], int index, int n, int target)
{

    if (target == 0){
        return 1;
    }
    if (index == n || target < 0){
        return 0;
    }
    return find(arr, index + 1, n, target) || find(arr, index + 1, n, target - arr[index]);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int target = 8;

    cout<<find(arr, 0, n, target); // Call the function to find the target sum

    return 0;
}