#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity)
    {
        priority_queue<pair<double,pair<int,int>>> pq;
        int n = val.size();
        
        for(int i = 0; i < n; i++)
        {
            pq.push({(double)val[i]/wt[i], {val[i], wt[i]}});
        }

        double profit = 0.0;
        
        while(capacity > 0 && !pq.empty())
        {
            double ratio = pq.top().first;
            int value = pq.top().second.first;
            int weight = pq.top().second.second;
            pq.pop();
            
            if(capacity >= weight)
            {
                profit += value;
                capacity -= weight;
            }
            else
            {
                profit += ratio * capacity;
                capacity = 0;
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    double maxValue = sol.fractionalKnapsack(val, wt, capacity);

    // Print result with 6 decimal places
    cout << fixed << setprecision(6) << maxValue << endl;

    return 0;
}
 