#include <iostream>
#include <string>
using namespace std;

bool pal(string str, int start, int end)
{

    if (start >= end)
    {
        return 1;
    }
    if (str[start] != str[end])

        return 0;
    else
        return pal(str, start + 1, end - 1);
}

int main()
{

    string str = "madam";

    cout << "The string is pallindrome : " << pal(str, 0, 4) << endl;

    return 0;
}