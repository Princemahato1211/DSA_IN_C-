#include<iostream>
using namespace std;

void countingsort(int a[],int n,int p){
    int b[n];
    int count[10];
    for(int z=0; z<10; z++){
        count[z]=0;
    }
    for(int i=0; i<n;i++){
        ++count[((a[i]/p)%10)];
    }
    for(int j=1; j<10; j++){
        count[j]=count[j]+count[j-1];
    }
    for(int l=n-1; l>=0;l--){
        b[--count[((a[l]/p)%10)]]=a[l];
    }
    for(int m=0; m<n;m++){
        a[m]=b[m];
    }
}
void radixsort(int a[],int n,int p){
    int poss=1;
    for(int i=0; i<p; i++){
        countingsort(a,n,poss);
        poss=poss*10;
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
    int large=a[0];
    for(int i=1; i<n; i++){
        if(a[i]>large){
            large=a[i];
        }
    }
    int passes=0;
    while (large>0){
        passes++;
        large=large/10;
    }
    radixsort(a,n,passes);
    cout<<endl<<"sorted element are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}