#include <iostream>
using namespace std;

// Function to convert a lowercase character to uppercase
char convert(char name)
{
    char ans = name - 'a' + 'A'; // Convert the character. This works by adjusting ASCII values.
                                 // Specifically, 'a' has an ASCII value of 97 and 'A' has 65.
                                 // Therefore, subtracting 'a' (97) from the character and adding 'A' (65)
                                 // effectively changes the character from lowercase to uppercase.
    return ans;
}

int main()
{
    char name;
    cout << "Enter a character  : ";
    cin >> name;
    cout << convert(name); // Call the convert function with 'name' as an argument and output the result

    return 0;
}