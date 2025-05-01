#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(vector<int> &arr, vector<vector<int>> &ans, int index,int n)
{

    if (index == n)
    {
        ans.push_back(arr);
        return;
    }
    vector<bool> use(21, 0);
    for (size_t i = index; i < arr.size(); i++)
    {
        if (use[arr[i] + 10] == 0)
        {
            swap(arr[i], arr[index]);
            permute(arr, ans, index + 1,n);
            swap(arr[i], arr[index]);
            use[arr[i] + 10] = 1;
        }
    }
}

int main()
{

    vector<int> arr = {1, 2, 2, 1};
int n = arr.size();
    vector<vector<int>> ans;

    permute(arr, ans, 0,n);

    for(size_t i=0;i<ans.size();i++){
        for(size_t j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}