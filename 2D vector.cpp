#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of rows and columns";
    cin>>n>>m;

    vector<vector<int>>matrix(n,vector<int>(m,1));


// for(int i=0;i<3;i++){
//     for(int j=0;j<3;j++){
//         cout<<matrix[i][j]<<" ";
//     }
// }
// cout<<"Rows"<<matrix.size();

// cout<<"col"<<matrix[0].size();

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>matrix[i][j];
    }
}


for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<matrix[i][j]<<" ";
    }
}
cout<<endl;
}