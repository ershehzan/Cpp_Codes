#include <iostream>
using namespace std;

int main()
{
    // Declare variables: n for the number of rows, i for the current row, j for the current column
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number of rows: ";
    cin >> n;

    // First half of the pattern (upper part)
    for (i = 1; i <= n; i++)
    {
        // Print leading spaces
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // Print stars followed by a space
        for (j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // Move to the next line
        cout << endl;
    }

    // Second half of the pattern (lower part)
    for (i = n - 1; i >= 1; i--)
    {
        // Print leading spaces
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // Print stars followed by a space
        for (j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // Move to the next line
        cout << endl;
    }

    return 0;
}

/*
Output:

         * 
        * *         
       * * *        
      * * * *       
     * * * * *      
    * * * * * *     
   * * * * * * *    
  * * * * * * * *   
 * * * * * * * * *  
* * * * * * * * * * 
 * * * * * * * * *  
  * * * * * * * *   
   * * * * * * *    
    * * * * * *     
     * * * * *      
      * * * *       
       * * * 
        * *  
         *   
*/
