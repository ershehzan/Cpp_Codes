#include <iostream> // Include the iostream header for input/output operations
#include <string>   // Include the string header to use the string class
using namespace std; // Use the standard namespace to avoid prefixing std::

// Recursive function to reverse a string in place
// Parameters:
// - str: The string to be reversed (passed by reference to modify the original string)
// - start: The starting index of the current character to swap
// - end: The ending index of the current character to swap
void rev(string &str, int start, int end)
{
    // Base case: If the start index is greater than or equal to the end index,
    // the string is fully reversed, so return
    if (start >= end)
    {
        return; // Exit the function
    }

    // Swap the characters at the start and end indices
    char c = str[start]; // Temporarily store the character at the start index
    str[start] = str[end]; // Assign the character at the end index to the start index
    str[end] = c; // Assign the stored character to the end index

    // Recursive case: Move the start index forward and the end index backward
    // to continue reversing the remaining substring
    rev(str, start + 1, end - 1);
}

int main()
{
    // Declare and initialize a string to be reversed
    string str = "Nosh";

    // Call the `rev` function to reverse the string
    // Parameters passed:
    // - str: The string to reverse
    // - 0: The starting index of the string
    // - 3: The ending index of the string (str.length() - 1)
    rev(str, 0, 3);

    // Print the reversed string
    cout << "The reversed string is: " << str << endl;

    return 0; // Exit the program
}
