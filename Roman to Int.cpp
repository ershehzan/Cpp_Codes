#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int nums(char c) {
        if (c == 'I')
            return 1;
        else if (c == 'V')
            return 5;
        else if (c == 'X')
            return 10;
        else if (c == 'L')
            return 50;
        else if (c == 'C')
            return 100;
        else if (c == 'D')
            return 500;
        else
            return 1000;
    }

    int romanToInt(string s) {
        int sum = 0, index = 0;

        while (index < s.size() - 1) {
            if (nums(s[index]) < nums(s[index + 1]))
                sum -= nums(s[index]);
            else
                sum += nums(s[index]);

            index++;
        }
        sum += nums(s[index]);
        return sum;
    }
};

int main() {
    Solution solution;
    string romanNumeral;

    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;

    int result = solution.romanToInt(romanNumeral);
    cout << "The integer value is: " << result << endl;

    return 0;
}