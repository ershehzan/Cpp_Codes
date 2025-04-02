#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to sort a given string in alphabetical order
string sort(string s) {
    // Vector to count the occurrence of each alphabet letter
    vector<int> alpha(26, 0);

    // Iterate through each character in the string
    for (int i = 0; i < s.size(); i++) {
        // Increment the count for the corresponding letter
        alpha[s[i] - 'a']++;
    }

    // String to store the sorted result
    string ans;

    // Iterate through the alphabet vector
    for (int i = 0; i < 26; i++) {
        // Get the character corresponding to the current index
        char c = 'a' + i;

        // Append the character to the result string based on its count
        while (alpha[i]) {
            ans += c;
            alpha[i]--;
        }
    }

    // Return the sorted string
    return ans;
}

int main() {
    string input;

    // Prompt the user to enter a string
    cout << "Enter a string: ";
    cin >> input;

    // Call the sort function to sort the input string
    string sortedString = sort(input);

    // Display the sorted string
    cout << "Sorted string: " << sortedString << endl;

    return 0; 
}
