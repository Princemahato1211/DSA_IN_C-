#include<iostream>
using namespace std;

void bubblesort(int a[],int n){
    int i,j,flag,temp;
    for(i=0; i<n-1;i++){
        flag=0;
        for(j=0; j<(n-1-i);j++){
            if(a[j+1]<a[j]){
                flag=1;
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
        if(flag==0){
            break;
        }
    }
}

int main(){
    int n;
    cout<<"enter the no. of element: ";
    cin>>n;
    int a[n];
    cout<<"enter the element of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    bubblesort(a,n);
    cout<<endl<<"sorted element are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}