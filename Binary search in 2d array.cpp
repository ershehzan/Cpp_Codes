#include <iostream>
#include <vector>
using namespace std;
int main()
{

    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    int n = 4, m = 4;
    int start = 0, end = n * m - 1;

    while (start <= end)
    {

        int mid = (start + end) / 2;

        int row_index = mid / m;
        int col_index = mid % m;

        int k = arr[row_index][col_index];

        if (k == x)
        {
            cout << "Element found at index: " << mid << endl;
            return 0;
        }
        else if (k < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return 0;
}