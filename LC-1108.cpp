#include <iostream>  // For input-output operations
using namespace std;

class Solution
{
public:
    // Function to "defang" an IP address by replacing '.' with "[.]"
    string lc(string address)
    {
        // Declare an empty string to store the modified IP address
        string ans;
        //size_t index = 0; // Using size_t (better for indexing instead of int)
int index = 0;
        // Iterate through each character in the input string
        while (index < address.size())
        {
            // If the current character is a dot ('.'), replace it with "[.]"
            if (address[index] == '.')
            {
                ans += "[.]"; // Append "[.]" to the result string
            }
            else
            {
                ans += address[index]; // Otherwise, keep the character unchanged
            }
            index++; // Move to the next character
        }
        return ans; // Return the transformed string
    }
};

int main()
{
    Solution solution; // Create an object of the Solution class
    string ipAddress; // Declare a string to store user input

    // Prompt the user to enter an IP address
    cout << "Enter an IP address: ";
    cin >> ipAddress; // Read the input IP address

    // Call the lc function and store the result
    string lc = solution.lc(ipAddress);

    // Output the modified IP address (with defanged format)
    cout << "Defanged IP Address: " << lc << endl;

    return 0; // Exit successfully
}
