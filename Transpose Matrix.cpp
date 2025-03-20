#include <iostream>
#include <vector>
using namespace std;
int main()
{

    vector<vector<int>> arr = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}};
    int trans[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            trans[j][i] = arr[i][j];
            cout << trans[j][i] << "";
        }
    }
    return 0;
}