#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int top=-1;
    int size;
    public:
    bool flag;
    Stack(int s){
        size=s;
        top=-1;
        arr=new int[s];
        flag=1;
    }
    //push operation
    void push(int value){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=value;
            cout<<"Pushed "<<value<<" to Stack"<<endl;
            flag=0;

        }
    }
    //pop operation
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
            cout<<"Popped "<<arr[top]<<" from Stack"<<endl;
            top--;
            if(top==-1)
            flag=1;
        }
    }
    // peek operation
    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1; // or some error value
        }
        else{
            return arr[top];
        }
    }
    // isEmpty operation
    bool isEmpty(){
        return top==-1;
    }
    // is size
    int isSize(){
        return top+1;
    }
};

int main(){

Stack s(5);
// s.push(10);
// s.push(20);
// s.push(30);
// s.push(40);
// s.push(50);   
s.push(-1);
int value=s.peek();
if(s.flag==0){
    cout<<"Top element is: "<<value<<endl;
}
else{
    cout<<"Stack is empty"<<endl;
}





// cout<<s.peek()<<endl;
// cout<<s.isEmpty()<<endl;
// cout<<s.isSize()<<endl;




}