#include <iostream>
#include <climits>
using namespace std;
int main(){
    int arr[1000];  // Array to store elements
    int n;
    int ans = INT_MIN;  // Variable to store the largest element
    // Taking input for number of elements
    cout << "Enter the number of elements: ";
    cin >> n;
    // Taking input for array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)  // Loop correctly runs n times
    {
        cin >> arr[i];
    }

    // Finding the largest element
    for (int i = 0; i < n; i++)  
    {
        if (arr[i] > ans)  
        {
            ans = arr[i];  // Update the largest element
        }
    }

    // Finding the second largest element
    int sec = INT_MIN;
    for (int i = 0; i < n; i++)  
    {
        if (arr[i] != ans && arr[i] > sec)  // Ensuring it's not equal to the largest element
        {
            sec = arr[i];  // Update second largest element
        }
    }

    // Displaying results
    cout << "Largest Element is: " << ans << endl;
    cout << "Second Largest Element is: " << sec << endl;
    
    return 0;
}




