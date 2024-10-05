#include <iostream>
#include <climits>
using namespace std;

int main()
{
int arr[5] = {13, 24, 35, 40, 51};

int i;
int ans = INT_MAX;
// Min value
for (i = 0; i < 5; i++)
{
    if (arr[i] < ans)
        ans = arr[i];
}
cout << "Min value is : ";
cout << ans << endl;

// Max value
ans = INT_MIN;

for (i = 0; i < 5; i++)
{
    if (arr[i] > ans)
        ans = arr[i];
}
cout << "Max value is : ";
cout << ans << endl;

return 0;
}