#include <iostream> // Include the iostream header for input/output operations
#include <string>   // Include the string header to use the string class
using namespace std; // Use the standard namespace to avoid prefixing std::

// Recursive function to count the number of vowels in a string
// Parameters:
// - str: The string to be checked
// - index: The current index in the string being checked
int count(string str, int index)
{
    // Base case: If the index is -1 (we have checked all characters),
    // return 0 as there are no more vowels to count
    if (index == -1)
        return 0;

    // Check if the current character is a vowel (case-sensitive)
    // If it is, add 1 to the result of the recursive call with the previous index
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
        return 1 + count(str, index - 1);

    // If the current character is not a vowel, continue with the recursive call
    // without adding to the count
    else
        return count(str, index - 1);
}

int main()
{
    // Declare and initialize a string to count vowels
    string str = "Shan";

    // Print the number of vowels in the string by calling the `count` function
    // The parameters passed are:
    // - str: The string to check
    // - str.length() - 1: The last index of the string
    cout << "The number of vowels in the string is: " << count(str, str.length() - 1) << endl;

    return 0; // Exit the program
}
