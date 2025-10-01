#include <iostream> // Include the iostream header for input/output operations
#include <string>   // Include the string header to use the string class
using namespace std; // Use the standard namespace to avoid prefixing std::

// Recursive function to check if a string is a palindrome
// Parameters:
// - str: The string to be checked
// - start: The starting index of the string being checked
// - end: The ending index of the string being checked
bool pal(string str, int start, int end)
{
    // Base case: If the start index is greater than or equal to the end index,
    // the string (or the substring being checked) is a palindrome
    if (start >= end)
    {
        return 1; // Return true
    }

    // If the characters at the current start and end indices are not equal,
    // the string is not a palindrome
    if (str[start] != str[end])
        return 0; // Return false

    // Recursive case: Move the start index forward and the end index backward,
    // and check the remaining substring
    else
        return pal(str, start + 1, end - 1);
}

int main(){
    // Declare and initialize a string to check for palindrome
    string str = "madam";

    // Print whether the string is a palindrome by calling the `pal` function
    // The parameters passed are:
    // - str: The string to check
    // - 0: The starting index of the string
    // - 4: The ending index of the string (str.length() - 1)
    cout << "The string is palindrome: " << pal(str, 0, 4) << endl;

    return 0; // Exit the program
}

