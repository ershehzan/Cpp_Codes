#include <iostream>
using namespace std;
int main()
{

    int arr[8] = {35, 33, 42, 10, 14, 19, 27, 44};

    for (int i = 0; i < 7; i++)
    {

        for (int j = 0; j < 8 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}