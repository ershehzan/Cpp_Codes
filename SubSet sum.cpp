#include <iostream>
#include <vector>
using namespace std;

void subsetsum(int arr[], int index, int n, int sum ,vector<int>&ans)
{
    if (index == n)
    {
       ans.push_back(sum); // Store the sum of the current subset
        return;
    }
    subsetsum(arr, index+1, n, sum,ans);
    subsetsum(arr, index + 1, n, sum + arr[index],ans); // include the current element
}

int main()
{
    int arr[] = {3, 4, 5};
    int n = 3;
    vector<int> ans; // Vector to store the sums of all subsets
    cout << "The sum of all subsets is: " << endl;
    subsetsum(arr,0,n,0,ans);
    for(size_t i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
