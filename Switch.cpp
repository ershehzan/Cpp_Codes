#include <iostream>
using namespace std;

int main()
{
    int days;

    // Prompt user for input
    cout << "Enter a Day number (1-7): ";
    cin >> days;

    // Switch statement to match input number with corresponding weekday
    switch (days)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        // Handles cases where input is not between 1-7
        cout << "Invalid input! Please enter a number between 1 and 7." << endl;
    }

    return 0;
}
