#include <iostream>
using namespace std;

int main() 
{
    string s = "levi"; // Initialize the string

    int start = 0, end = s.size() - 1; // Set start and end pointers

    // Reverse the string using two-pointer approach
    while (start < end)
    {
        if (s[start] != s[end]) // Check if characters at start and end are not equal
        {
            cout << "Not a palindrome" << endl; // Print not a palindrome message
            return 0;  // Exit the program
        }
        start++; // Move start pointer forward
        end--;   // Move end pointer backward
    }

    cout << "Palindrome" << endl; // Print palindrome message

    return 0; 
}
