#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int arr[1000] = {12, 36, 67, 90}; // Array representing the number of pages in each book

    int start = 0, end = 3, mid, ans; // Initializing search space variables

    while (start <= end)
    {
        mid = start + (end - start) / 2; // Calculate the middle value of the search space
        int page = 0, count = 1; // Variables to track pages allocated and student count

        for (int i = 0; i < n; i++)
        {
            if (start < arr[i]) // Ensure start is at least the max pages in a single book
            {
                start = arr[i]; 
                end += arr[i]; 
            }
            page += arr[i]; // Add current book's pages

            if (page > mid) // If total pages exceed mid, allocate to next student
            {
                count++; // Increase student count
                page = arr[i]; // Start new allocation with current book
            }
        }

        if (count <= n) // If allocation is possible within 'n' students
        {
            ans = mid; // Store the possible answer
            end = mid - 1; // Try to find a better (smaller) allocation
        }
        else
        {
            start = mid + 1; // Increase search space if students exceed the given 'n'
        }
    }
    cout << "Minimum maximum pages allocated: " << ans; // Print the result
    return 0;
}


