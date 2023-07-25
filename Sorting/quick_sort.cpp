#include<iostream>
using namespace std;
int partition(int a[],int l,int u){
    int i,j,pivot,temp;
    pivot=a[l];
    i=l;
    j=u;
    while (i<j){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[l]=a[j];
    a[j]=pivot;
    return j;
}

void quicksort(int a[],int l, int u){
    int loc;
    if(l<u){
        loc=partition(a,l,u);
        quicksort(a,l,loc-1);
        quicksort(a,loc+1,u);
    }
}

int main(){
    int n;
    int a[n];
    cout<<"enter the no. of element: ";
    cin>>n;
    cout<<"enter the element of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<"sorted element are: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}