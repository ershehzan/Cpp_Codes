#include <iostream>
using namespace std;
int main()
{

    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // i=row j=column
    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 4; j++)

            if (arr[i][j] == x)
            {
                cout << "Element found at " << i << " " << j << endl;
                return 0;
            }
    }
    cout << "Element not found";
    return 0;
}