#include <iostream>
using namespace std;

int main()
{
    int i, j, key;
    int arr[6] = {10, 41, 64, 29, 11, 9};

    for (i = 1; i < 6; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for ( i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}