#include <iostream>
#include <climits>

using namespace std;

int minelement(int arr[], int index, int n)
{
    if (index == n - 1)
    {
        return arr[index];
    }

    return min(arr[index] , minelement(arr, index + 1, n));
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Minimum Elements is:" << minelement(arr, 0, 5) << endl;

    return 0;
}