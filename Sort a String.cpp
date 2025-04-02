#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sort(string s) {
    //complete the function here
    vector<int> alpha(26, 0);

    for (int i = 0; i < s.size(); i++) {
        alpha[s[i] - 'a']++;
    }

    string ans;

    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;

        while (alpha[i]) {
            ans += c;
            alpha[i]--;
        }
    }
    return ans;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string sortedString = sort(input);
    cout << "Sorted string: " << sortedString << endl;

    return 0;
}