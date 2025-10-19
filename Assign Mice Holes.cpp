#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        int n = holes.size();
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            ans = max(ans, abs(mices[i] - holes[i]));
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of mice and holes: ";
    cin >> n;

    vector<int> mices(n), holes(n);
    cout << "Enter positions of mice:\n";
    for(int i = 0; i < n; i++)
        cin >> mices[i];
    
    cout << "Enter positions of holes:\n";
    for(int i = 0; i < n; i++)
        cin >> holes[i];

    Solution obj;
    int result = obj.assignHole(mices, holes);
    cout << "Minimum time for last mouse to get into a hole: " << result << endl;

    return 0;
}
