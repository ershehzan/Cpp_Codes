#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        
          stack<int>st;
          int index;
          int ans=0;
           // Next Smallest right
           for(int i=0;i<n;i++){

              while(!st.empty()&&heights[st.top()]>heights[i]){
              index=st.top();
              st.pop();

              if(!st.empty())
                ans=max(ans,heights[index]*(i-st.top()-1));
                else
                   ans=max(ans,heights[index]*i);
              
              }
              st.push(i);
           }
             while(!st.empty()){
                 index=st.top();
              st.pop();

              if(!st.empty())
                ans=max(ans,heights[index]*(n-st.top()-1));
                else
                   ans=max(ans,heights[index]*n);
             }
         
      return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of bars in the histogram: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int result = solution.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << result << endl;
    return 0;
}