//GFG
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int findSubString(string& s) 
        {
                vector<int> count(256, 0);
                
                int f = 0, sec = 0, len = s.size();
                int dif = 0;

                // Count number of unique characters in the string
                while (f < s.size())
                {
                        if (count[s[f]] == 0)
                                dif++;
                        count[s[f]]++;
                        f++;
                }

                // Reset count array and pointers for sliding window
                fill(count.begin(), count.end(), 0);
                f = 0;
                sec = 0;
                int currDif = 0;

                while (sec < s.size())
                {
                        while (currDif < dif && sec < s.size())
                        {
                                if (count[s[sec]] == 0)
                                        currDif++;

                                count[s[sec]]++;
                                sec++;
                        }

                        while (currDif == dif)
                        {
                                len = min(len, sec - f);
                                count[s[f]]--;

                                if (count[s[f]] == 0)
                                        currDif--;

                                f++;
                        }
                }

                return len;
        }
};

//{ Driver Code Starts.
//   Driver code
int main() {
        int t;
        cin >> t;
        while (t--) {

                string str;
                cin >> str;
                Solution ob;
                cout << ob.findSubString(str) << endl;

                cout << "~"
                         << "\n";
        }
        return 0;
}
