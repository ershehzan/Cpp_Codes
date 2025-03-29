#include <iostream>
using namespace std;

int main() // Corrected function name from 'msin' to 'main'
{
    string s = "ivel"; // Initialize the string

    int start = 0, end = s.size() - 1; // Set start and end pointers
    
    // Reverse the string using two-pointer approach
    while (start < end)
    {
        swap(s[start], s[end]); // Swap characters at start and end positions
        start++; // Move start pointer forward
        end--; // Move end pointer backward
    }
    
    cout << s << endl; // Print the reversed string
    int size=0;
while(s[size] != '\0') // Calculate the size of the string
{
    size++; // Increment size for each character until null terminator
}
cout << "Size of the string: " << size << endl; // Print the size of the string

    return 0; 
}
