#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                int num = INT_MAX;
                for (int k = j; k < i + 1 + j; k++) {
                    num = min(num, arr[k]);
                }
                ans[i] = max(ans[i], num);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> result = solution.maxOfMins(arr);
    cout << "Max of min for every window size: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}