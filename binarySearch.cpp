// Binary search
#include <iostream>
using namespace std;

int main()
{

    int n, l = 0, r=n-1, m,target;
    
    int arr[1000];
    cout<<"Enter the index: ";
    cin>>n;
    cout<<"Enter the Elements of Array: ";

    for(int i=0;i<n;i++){
cin>>arr[i];
    }
    
    cout << "Enter the Number to search: ";

    cin >> target;
 // Set r to the last index of the array

    // Begin binary search

    while (l <= r)
    {

        m = l + (r - l) / 2; //  calculation of the mid index

        if (arr[m] == target)
        {

            cout << "Element is present at index " << m << endl;

            return 0; // Exit if element is found
        }

        else if (arr[m] < target)
        {

            l = m + 1; // Move to the right half
        }

        else
        {

            r = m - 1; // Move to the left half
        }
    }

    cout << "Element is not present in the array" << endl; // If element is not found

    return 0;
}
