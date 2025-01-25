#include <iostream>
using namespace std;

int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6,7,8,9,10};

    int start = 0, end = 9;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    };
    for (int i = 0; i < 10; i++)
        cout << arr[i];

    return 0;
}
