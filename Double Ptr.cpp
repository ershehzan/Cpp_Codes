#include<iostream>
using namespace std;
int main(){

    int n=10;
    int *p=&n;//single pointer
    int **p1=&p;// double pointer
    int ***p2=&p1;//triple pointer

    cout<<p<<endl; //address of n
    cout<<&p<<endl; //address of p
    cout<<p1<<endl;
    cout<<&p1<<endl;
cout<<p2<<endl;


*p=*p+5;
cout<<n<<endl; //15


    return 0;
}