#include<iostream>
using namespace std;
#define MAX 30

void merge(int a[], int lo,int mi,int up){
    int c[MAX];
    int i,j,k;
    i=lo;
    j=mi+1;
    k=0;
    while(i<=mi && j<=up){
        if(a[i]<a[j]){
            c[k]=a[i];
            i++; 
            k++;
        }else{
            c[k]=a[j];
            j++; 
            k++;
        }
    }
    while (i<=mi){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<=up){
        c[k]=a[j];
        j++;
        k++;
    }
    for(int i=lo, j=0; i<=up; i++,j++){
        a[i]=c[j];
    }
}

void mergesort(int a[],int l,int u){
    int mid;
    if(l<u){
        mid=(l+u)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,u);
        merge(a,l,mid,u);
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
    mergesort(a,0,n-1);
    cout<<endl<<"sorted element are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}