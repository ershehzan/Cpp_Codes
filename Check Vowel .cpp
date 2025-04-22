#include <iostream>
#include <string>
using namespace std;

int count(string str, int index)
{

    if (index == -1)
        return 0;

    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
        return 1 + count(str, index - 1);
    else
        return count(str, index - 1);
}

int main()
{

    string str = "Shan";

    cout << "The number of vowels in the string is : " << count(str, str.length() - 1) << endl;

    return 0;
}