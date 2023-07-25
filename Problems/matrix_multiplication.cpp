#include<iostream>
using namespace std;
int main(){
    int row1,col1,col2;                             // row1 and col1 are the rows and column of 1st matrix                                //col2 are the column of 2nd matrix
    cout<<"enter the size of 1st matrix: ";
    cin>>row1>>col1;
    cout<<"enter the size of col2 in 2nd matrix: ";
    cin>>col2;
    cout<<"enter the element of 1st matrix:"<<endl;
    int arr[row1][col1];                           // declaration pf 1st matrix
    for (int i=0; i<row1;i++){                     // taking input for the element of 1st matrix
        for (int j=0;j<col1;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"enter the element of 2nd matrix: "<<endl;
    int row2=col1;                                           // row2 and col2 are the rows and column of 2nd matrix
    int arr2[row2][col2];                                    // declaraton of 2nd matrix 
    for (int i=0; i<row2;i++){                              // taking input for the element of 2nd matrix
        for (int j=0;j<col2;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<endl<<"the elemnt of 1st matrix: "<<endl;
    for (int i=0; i<row1;i++){                          // print the element of 1st matrix
        for (int j=0;j<col1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl<<"the elemnt of 2nd matrix: "<<endl;
    for (int i=0; i<row2;i++){                         // print the element of 2nd matrix
        for (int j=0;j<col2;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<"\n";
    }
    int arr3[row1][col2];
    for (int i=0;i<row1;i++){                    // multiplication of 1st and 2nd matrix
        for(int j=0;j<col2;j++){
            arr3[i][j]=0;
            for(int k=0;k<col1;k++){
                arr3[i][j]=arr3[i][j]+(arr[i][k]*arr2[k][j]);
            }
        }
    }
    cout<<endl<<"the elemnt of multiplication matrix: "<<endl;
    for (int i=0; i<row1;i++){                  // print the element of multilication matrix
        for (int j=0;j<col2;j++){ 
            cout<<arr3[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}