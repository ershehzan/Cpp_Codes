#include <iostream>
using namespace std;

class Solution
{
public:
    string lc(string address)
    {

        // start here
        string ans;
        size_t index = 0;

        while (index < address.size())
        {
            if (address[index] == '.')
            {
                ans += "[.]";
            }
            else
            {
                ans += address[index];
            }
            index++;
        }
        return ans;
        // end here
    }
};

int main()
{
    Solution solution;
    string ipAddress;

    // Taking user input
    cout << "Enter an IP address: ";
    cin >> ipAddress;

    // Calling the function and displaying the result
    string lc = solution.lc(ipAddress);
    cout << "Defanged IP Address: " << lc << endl;

    return 0;
}
