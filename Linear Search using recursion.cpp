#include <iostream>
using namespace std;
bool LinearSearch(int arr[], int x, int index)
{

    if (index == -1)
    {
        return 0;
    }

    if (arr[index] == x)
    {
        return 1;
    }
    return LinearSearch(arr, x, index - 1);
}

int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    cout << LinearSearch(arr, x, 9);

    return 0;
}