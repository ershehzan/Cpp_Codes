//GFG
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int findSubString(string& s) 
        {
                // Initialize the count array to store character frequencies
                vector<int> count(256, 0);
                
                // Initialize pointers and variables
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

                // Iterate over the string with the sliding window approach
                while (sec < s.size())
                {
                        // Expand the window until it contains all unique characters
                        while (currDif < dif && sec < s.size())
                        {
                                if (count[s[sec]] == 0)
                                        currDif++;

                                count[s[sec]]++;
                                sec++;
                        }

                        // Contract the window to find the minimum length substring
                        while (currDif == dif)
                        {
                                len = min(len, sec - f);
                                count[s[f]]--;

                                if (count[s[f]] == 0)
                                        currDif--;

                                f++;
                        }
                }

                return len; // Return the length of the smallest substring containing all unique characters
        }
};

//{ Driver Code Starts.
// Driver code
int main() {
        int t;
        cin >> t; // Read number of test cases
        while (t--) {

                string str;
                cin >> str; // Read the input string
                Solution ob;
                cout << ob.findSubString(str) << endl; // Print the result

                cout << "~"
                         << "\n";
        }
        return 0;
}
