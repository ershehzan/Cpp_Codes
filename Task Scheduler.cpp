// Problem Link: https://leetcode.com/problems/task-scheduler/
//621. Task Scheduler

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // CALCULATE FREQUENCY
        vector<int> freq(26, 0);
        int count = 0;
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
            count = max(count, freq[tasks[i] - 'A']);
        }

        int ans = (count - 1) * (n + 1);
        for (int i = 0; i < 26; i++) {
            if (freq[i] == count)
                ans++;
        }

        return ans > tasks.size() ? ans : tasks.size();
    }
};

int main() {
    Solution obj;

    // Example input
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    cout << "Minimum intervals required: " << obj.leastInterval(tasks, n) << endl;

    return 0;
}
