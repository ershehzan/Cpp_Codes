#include <iostream>
using namespace std;

int main()
{
    // Initializing the banana piles
    int piles[1000] = {3, 6, 11, 7};
    int h; // Number of hours available
    
    cout << "Enter the hours : ";
    cin >> h;

    // Variables for binary search approach
    int start = 0, end = 0, mid, ans, n = 3;
    long long sum = 0;
    
    // Calculating total bananas and finding the maximum pile size
    for (int i = 0; i < n; i++)
    {
        sum += piles[i];
        end = max(end, piles[i]); // Maximum number of bananas in a single pile
    }
    
    // Setting the lower bound of the search space
    start = sum / h;
    if (!start)
        start = 1; // Ensuring minimum speed is at least 1
    
    // Binary search for the minimum eating speed
    while (start <= end)
    {
        mid = start + (end - start) / 2; // Midpoint of the search space

        int time = 0; // Variable to store total hours required at speed `mid`

        // Calculating the total hours required at speed `mid`
        for (int i = 0; i < n; i++)
        {
            time += piles[i] / mid;
            if (piles[i] % mid)
                time++; // If there's a remainder, one more hour is needed
        }

        // Adjusting search range based on time required
        if (time > h)
        {
            start = mid + 1; // Increase the eating speed
        }
        else
        {
            ans = mid; // Store the possible answer
            end = mid - 1; // Try for a smaller eating speed
        }
    }
    
    cout << "KOKO has to eat " << ans << " bananas in 1 hour";
    return 0;
}
