#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    
    void racw(string &s) {
        char n = s[0]; // Store the first character
        int index = 1;

        while (index < s.size()) {
            s[index - 1] = s[index]; // Shift characters left
            index++;
        }
        s[s.size() - 1] = n; // Move the first character to the last position
    }
    
    void rcw(string &s) {
        char n = s[s.size() - 1];
        int index = s.size() - 2;

        while (index >= 0) {
            s[index + 1] = s[index];
            index--;
        }
        s[0] = n;
    }
    
    bool isRotated(string& s1, string& s2) {
        if (s1.size() != s2.size())
            return false;

        string cw, acw;
        // clockwise
        cw = s1;

        rcw(cw);
        rcw(cw);

        if (cw == s2)
            return true;

        // Anticlockwise
        acw = s1;

        racw(acw);
        racw(acw);

        if (acw == s2)
            return true;

        return false;
    }
};

int main() {
    Solution solution;

    string s1 = "amazon";
    string s2 = "azonam";

    if (solution.isRotated(s1, s2)) {
        cout << s2 << " is a rotated version of " << s1 << " by 2 places." << endl;
    } else {
        cout << s2 << " is not a rotated version of " << s1 << " by 2 places." << endl;
    }

    return 0;
}
