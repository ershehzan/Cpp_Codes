#include <iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace to simplify code

// Recursive function to solve Tower of Hanoi
// Parameters:
// n - the number of disks
// sou - the source rod
// help - the auxiliary/helper rod
// des - the destination rod
void toh(int n, int sou, int help, int des)
{
    // Base case: If there's only one disk, move it directly from source to destination
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << sou << " to rod " << des << endl;
        return;
    }

    // Recursive step 1: Move the top (n-1) disks from the source rod to the helper rod
    toh(n - 1, sou, des, help);

    // Move the nth disk (largest disk) from the source rod to the destination rod
    cout << "Move disk " << n << " from rod " << sou << " to rod " << des << endl;

    // Recursive step 2: Move the (n-1) disks from the helper rod to the destination rod
    toh(n - 1, help, sou, des);
}

int main()
{
    int n; // Number of disks
    cout << "Enter the number of disks: "; // Prompt user for input
    cin >> n; // Read user input for the number of disks
    
    // Inform the user about the result
    cout << "The sequence of moves involved in the Tower of Hanoi are :\n";

    // Initialize rod identifiers: 1 for source, 2 for helper, 3 for destination
    int sou = 1, help = 2, des = 3;

    // Call the Tower of Hanoi function to display the sequence of moves
    toh(n, sou, help, des);

    return 0; // End of the program
}
