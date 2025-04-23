#include <iostream> // Include the iostream header for input/output operations
#include <string>   // Include the string header to use the string class
using namespace std; // Use the standard namespace to avoid prefixing std::

// Recursive function to convert a lowercase string to uppercase
// Parameters:
// - str: The string to be converted (passed by reference to modify the original string)
// - index: The current index being processed in the string
void lower(string &str, int index)
{
    // Base case: If the index is -1, all characters have been processed
    if (index == -1)
    {
        return; // Exit the function
    }

    // Convert the character at the current index from lowercase to uppercase
    // The formula 'A' + (current_char - 'a') works because ASCII values of
    // uppercase and lowercase letters are offset by a fixed value
    str[index] = 'A' + str[index] - 'a';

    // Recursive call: Move to the previous character in the string
    lower(str, index - 1);
}

int main()
{
    // Declare and initialize a lowercase string
    string str = "nosh";

    // Call the `lower` function to convert the string to uppercase
    // Parameters passed:
    // - str: The string to convert
    // - 3: The last index of the string (str.length() - 1)
    lower(str, 3);

    // Print the converted string
    cout << "The converted string is: " << str << endl;

    return 0; // Exit the program
}
