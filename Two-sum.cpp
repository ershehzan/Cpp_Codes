#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Array to store elements
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the Target: ";
    cin >> target;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
                cout << "Pair found" << "[" << i << "," << j << "]" << endl;
        }
    }

    return 0;
}
