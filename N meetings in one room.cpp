#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> timer;
        for (int i = 0; i < start.size(); i++) {
            timer.push_back({start[i], end[i]});
        }

        sort(timer.begin(), timer.end(), comp);

        int total = 0;
        int ending = -1;

        for (int i = 0; i < timer.size(); i++) {
            if (timer[i].first > ending) {
                total++;
                ending = timer[i].second;
            }
        }
        return total;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of meetings: ";
    cin >> n;

    vector<int> start(n), end(n);

    cout << "Enter start times: ";
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Enter end times: ";
    for (int i = 0; i < n; i++)
        cin >> end[i];

    cout << "Maximum meetings that can be held: "
         << obj.maxMeetings(start, end) << endl;

    return 0;
}
