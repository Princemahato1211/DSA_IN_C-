#include<iostream>
using namespace std;

int n=10;
int stack[10];
int top=-1;

void push(int x);
void pop();
int peak();
bool isEmpty();

int main(){
    int a, k;
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    k=peak();
    cout<<"the top element are: "<<k<<endl;
    cout<<"the elements are : ";
    while(!isEmpty()){
        cout<<peak()<<" ";
        pop();
    }
    return 0;
}

void push(int x){
    if(top>n-1){
        cout<<"stack overflow"<<endl;
    }
    else{
        top++;
        stack[top]=x;
        cout<<"the pushed element are: "<<x<<endl;
    }
}

void pop(){
    if(top<0){
        cout<<"stack underflow";
    }
    else{
        top--;
    }
}

int peak(){
    int a=0;
    if(top<0){
        cout<<"stack is empty ";
    }
    else{
        a=stack[top];
    }
    return a;
}

bool isEmpty(){
    if(top<0){
        return true;
    }
    else{
        return false;
    }
}
