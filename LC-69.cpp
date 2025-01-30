//Leet code problem 69 square root of X

#include<iostream>
using namespace std;

class Solution {
public:

    int mySqrt(int x) {
        //solution start from here
        int start=0,end=x,mid,ans;
while(start<=end){
    mid=start+(end-start)/2;
    if(mid*mid==x){
        return mid;


    }
    else if(mid*mid<x)
    {
        ans=mid;
        start=mid+1;
    }
    else{
        end=mid;
    }

}
return ans;
//end here
    }
};
int main(){
    Solution s;
}