#include <iostream>
#include <string>
using namespace std;

void lower(string &str, int index)
{

    if (index == -1)
    {
        return;
    }

    str[index] = 'A' + str[index] - 'a';
    lower(str, index - 1);
}

int main()
{

    string str = "nosh";

    lower(str, 3);
    cout << "The reversed string is : " << str << endl;

    return 0;
}