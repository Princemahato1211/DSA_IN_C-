// 1st method 

// #include<iostream>
// using namespace std;

// int main(){
//     int n,x;
//     cout<<"enter the number ofelement :";
//     cin>>n;
//     int a[100];
//     for(int i=0; i<100; i++){
//         a[i]=0;
//     }
//     for(int i=0; i<n; i++){
//         cin>>x;
//         a[x]++;
//     }
//     cout<<"sorted element are: ";
//     for(int j=0; j<100; j++){
//         if(a[j]>0){
//             while (a[j]>0){
//                 cout<<j<<" ";
//                 a[j]--;
//             }   
//         }
//     }
//     return 0;
// }


// 2nd methodh
#include<iostream>
using namespace std;
int main(){
    int n,k=0;;
    cout<<"enter the no. of element: ";
    cin>>n;
    int alist[n];
    cout<<"enter the element of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>alist[i];
    }
    for(int i=1; i<n; i++){
        if(alist[i]>k){
            k=alist[i];
        }
    }
    k++;
    int count[k];
    int b[n];
    for(int i=0; i<k;i++){
        count[i]=0;
    }
    for(int j=0;j<n;j++){
        count[alist[j]]++;
    }
    for(int l=1; l<n;l++){
        count[l]=count[l]+count[l-1];
    }
    for(int m=n-1; m>=0; m--){
        b[--count[alist[m]]]=alist[m];
    }
    for(int x=0; x<n; x++){
        alist[x]=b[x];
    }

    cout<<endl<<"sorted element are: "<<endl;
    for(int j=0; j<n; j++){
        cout<<alist[j]<<" ";
    }
    return 0;
}

/* 2 4 1 9 6 3 2 1 7 9 5 4 3 4 2 1 3 5 7 8
  20 */