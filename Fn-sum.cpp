#include <iostream>
using namespace std;
// Function to calculate the sum of two integers
int sum(int a, int b){
    
    int result = a + b;  // Add the two numbers
    return result;       // Return the result
}

int main(){
    int x, y;  // Variables to store user input

    // Prompt the user to enter two numbers
    cout << "Enter the numbers: ";
    cin >> x >> y;  // Take input for both numbers

    // Call the sum function and display the result
    cout << "The sum of the two numbers is: " << sum(x, y) << endl;

    return 0; 
}




