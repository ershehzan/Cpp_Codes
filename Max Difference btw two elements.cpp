#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[1000] = {9,5,8,12,2,3,7,4}; 
    int n = 8;                                
    int suffix=arr[n-1];                         // Array to store the suffix sums
int ans=INT_MIN;


for(int i=n-2;i>=0;i--)
{
    ans=max(ans,suffix-arr[i]);
    suffix=max(suffix,arr[i]);
    

}    
cout<<"Max difference between two elements: "<<ans;

 
   
    return 0;
}