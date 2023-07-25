#include<iostream>
using namespace std;

void selectionsort(int a[],int n){
    int i,j,temp,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main(){
    int n;
    cout<<"enter the no. of element: ";
    cin>>n;
    int b[n];
    cout<<"enter the element of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    selectionsort(b,n);
    cout<<endl<<"sorted element are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
