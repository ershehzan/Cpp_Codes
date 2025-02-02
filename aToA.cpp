#include <iostream>
using namespace std;

int main()
{
    char name, ans; // Declare variables to store user input and the converted character

    cout << "Enter a lowercase character: ";
    cin >> name;

    // Convert the lowercase character to uppercase using ASCII value manipulation
    ans = name - 'a' + 'A';

    // Display the converted uppercase character
    cout << "Uppercase: " << ans << endl;

    return 0;
}
