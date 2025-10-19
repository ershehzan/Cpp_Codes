#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        
        int start = 0, end = n - 1;
        int minSum = 0, maxSum = 0;
        
        // Minimum candies
        while (start <= end) {
            minSum += prices[start];
            start++;
            end -= k;
        }
        
        start = n - 1;
        end = 0;
        
        // Maximum candies
        while (start >= end) {
            maxSum += prices[start];
            start--;
            end += k;
        }
        
        return {minSum, maxSum};
    }
};

int main() {
    Solution obj;
    int n, k;
    cout << "Enter number of candies: ";
    cin >> n;
    cout << "Enter number of free candies (k): ";
    cin >> k;

    vector<int> prices(n);
    cout << "Enter candy prices: ";
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    
    vector<int> ans = obj.minMaxCandy(prices, k);
    
    cout << "Minimum cost: " << ans[0] << endl;
    cout << "Maximum cost: " << ans[1] << endl;
    
    return 0;
}
