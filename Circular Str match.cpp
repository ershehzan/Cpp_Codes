// Circuler string matching
#include<iostream>
#include<vector>
using namespace std;
void lpsfind(vector<int>&lps,string txt)
{
    int prefix=0,suffix=1;
    while(suffix<txt.size())
    {
        if(txt[prefix]==txt[suffix])
        {
            lps[suffix]=prefix+1;
            prefix++,suffix++;
        }
        else
        {
            if(prefix==0)
            {
                lps[suffix]=0;
                suffix++;
            }
            else
            prefix=lps[prefix-1];
        }
    }
}
int main()
{
    string txt="cdeabroab";
    string pattern="abcde";
    txt+=txt;
    vector<int>lps(pattern.size(),0);
    lpsfind(lps,pattern);
    int first=0,second=0;
    while(second<pattern.size() && first<txt.size())
    {
        if(pattern[second]==txt[first])
        second++,first++;
        else
        {
            if(second==0)
            first++;
            else
            second=lps[second-1];
        }
    }
    if(second==pattern.size())
    cout<<"Matching";
    else
    cout<<"Not Matching";
}