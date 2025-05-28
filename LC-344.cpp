#include <iostream>   // For input and output stream
#include <vector>     // For using the vector container
#include <stack>      // For using the stack container
using namespace std;

// Solution class that contains the method to reverse a string
class Solution {
public:
    // This function reverses the input vector of characters in place
    void reverseString(vector<char>& s) {
        stack<char> st;  // Declare a stack to assist in reversing the string

        // Push each character of the vector into the stack
        for (size_t i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }

        int i = 0; // Index to overwrite the vector from the beginning

        // Pop characters from the stack (which reverses the order)
        // and assign them back to the vector
        while (!st.empty()) {
            s[i] = st.top();
            st.pop();
            i++;
        }
    }
};

int main() {
    Solution solution;  // Create an object of the Solution class
    int n;              // Variable to store the number of characters

    // Prompt the user to enter the number of characters
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> s(n);  // Declare a vector of characters of size n

    // Prompt the user to enter the characters (one by one, no spaces)
    cout << "Enter the characters (no spaces): ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // Call the reverseString method to reverse the characters in the vector
    solution.reverseString(s);

    // Output the reversed string
    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0; // Indicate successful execution
}
