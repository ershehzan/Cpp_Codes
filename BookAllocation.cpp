#include <iostream>
#include <climits>
using namespace std;

// Function to check if it's possible to allocate books among 'students' such that 
// no student reads more than 'maxPages'
bool isPossible(int arr[], int n, int students, int maxPages) {
    int studentCount = 1, pagesSum = 0; 

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)  // If a single book has more pages than maxPages, return false
            return false;

        if (pagesSum + arr[i] > maxPages) { 
            studentCount++;  // Allocate to next student
            pagesSum = arr[i]; // Start new allocation
            
            if (studentCount > students) // If more students are needed, return false
                return false;
        } else {
            pagesSum += arr[i]; // Add book pages to the current student's allocation
        }
    }

    return true; // If allocation is possible within 'students', return true
}

// Function to find the minimum possible max pages allocated
int findPages(int arr[], int n, int students) {
    if (students > n) // If there are more students than books, allocation is impossible
        return -1;

    int start = INT_MAX, end = 0; 
    for (int i = 0; i < n; i++) {
        start = min(start, arr[i]); // Start should be the max book pages
        end += arr[i]; // End should be the sum of all pages
    }

    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, students, mid)) { 
            ans = mid; // Store the potential answer
            end = mid - 1; // Try for a better (smaller) answer
        } else {
            start = mid + 1; // Increase max pages and search again
        }
    }

    return ans;
}
int main() {
    int n, students;
    
    cout << "Enter number of books: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter number of pages in each book: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number of students: ";
    cin >> students;

    int result = findPages(arr, n, students);

    if (result == -1)
        cout << "Book allocation is not possible!" << endl;
    else
        cout << "Minimum maximum pages allocated: " << result << endl;

    return 0;
}

