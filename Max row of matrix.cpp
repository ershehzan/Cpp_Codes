#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int arr[3][3] = {11, 23, 33,
                     41, 55, 61,
                     74, 85, 99};
    int sum = INT_MIN, index = -1;

    for (int i = 0; i < 3; i++)
    {
        int total = 0;
        for (int j = 0; j < 3; j++)

            total += arr[i][j];

        if (total > sum)
        {
            sum = total;
            index = i;
        }
    }
    cout << index;
    return 0;
}
