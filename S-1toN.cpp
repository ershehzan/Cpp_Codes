// Sum from 1 to n without loop;
#include <iostream>
using namespace std;

int main()
{
    int n; // Declare an integer variable to store the input number
    cout << "Enter a number : "; // Prompt the user to enter a number
    cin >> n; // Read the input number from the user
    // Calculate the sum from 1 to n using the formula n*(n+1)/2
    cout << "Sum from 1 to " << n << " is " << (n * (n + 1) / 2);
    
    return 0; 
}
