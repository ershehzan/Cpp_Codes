// Koko Eating Bananas
#include <iostream>
using namespace std;
int main()
{
    int piles[1000] = {3, 6, 11, 7};
    int h;
    cout << "Enter the hours : ";
    cin >> h;

    int start = 0, end = 0, mid, ans, n = 3;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum += piles[i];
        end = max(end, piles[i]);
    }
    start = sum / h;
    if (!start)
        start = 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        int time = 0;

        for (int i = 0; i < n; i++)
        {
            time += piles[i] / mid;
            if (piles[i] % mid)
                time++;
        }

        if (time > h)
        {
            start = mid + 1;
        }

        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    cout<<"KOKO have to eat "<<ans<<" bananas in 1 hour";

    return 0;
}