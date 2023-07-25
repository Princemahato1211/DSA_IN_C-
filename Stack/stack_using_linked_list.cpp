#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *previous;
}node;
node *top=0;

void push(int x);
void pop();
void peak();
bool isempty();
void display();

int main(){
    push(23);
    push(11);
    push(45);
    push(12143);
    push(1);
    display();
    pop();
    pop();
    peak();
    push(111111);
    display();
    return 0;
}

void push(int x){
    node *newnode;
    cout<<"the pushed element are: "<<x<<endl;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->previous=top;
    top=newnode;
}

void pop(){
    node *temp;
    temp=top;
    cout<<"the pop element are: "<<top->data<<endl;
    top=top->previous;
    free(temp);
}

void peak(){
    cout<<"the top element are: "<<top->data<<endl;
}

bool isempty(){
    if(top==0){
        return true;
    }
    else{
        return false;
    }
}

void display(){
    node *temp;
    temp=top;
    cout<<"the element are: ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->previous;
    }
    cout<<endl;
}