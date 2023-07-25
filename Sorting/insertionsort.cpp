#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the no. of element: ";
    cin>>n;
    int a[n];
    cout<<"enter the element of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    // insertion sort method
    int i,j,temp;
    for(i=1;i<n; i++){
        temp=a[i];
        for(j=i-1; j>=0 and a[j]>temp;j--){
                a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
    // end

    cout<<endl<<"sorted element are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}