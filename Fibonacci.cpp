#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter a number : ";
    cin >> num;

    int arr[1000];

    // Initialize the first two Fibonacci numbers
    arr[0] = 0; // The 1st Fibonacci number is 0
    arr[1] = 1; // The 2nd Fibonacci number is 1

    // Use a loop to calculate the Fibonacci numbers from 2 to n-1
    for (int i = 2; i <=  num - 1; i++)
    {
        // Each number is the sum of the two preceding numbers
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    // Print the n-th Fibonacci number (indexed at n-1 in the array)

    cout <<"Fibonacci Series : "<< arr[ num - 1] << "  ";

    return 0; 
}
