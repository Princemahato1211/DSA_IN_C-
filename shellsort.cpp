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
    int gap=n/2;
    for(gap=n/2; gap>=1; gap=gap/2){
        for(int j=0;j<n;j++){
            for(int i=j-gap; i>=0; i=i-gap){
                if(a[i+gap]>a[i]){
                    break;
                }else{
                    int temp=a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=temp;
                }
            }
        }
    }
    cout<<endl<<"sorted element are: "<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}