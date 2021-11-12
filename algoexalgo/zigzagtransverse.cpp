#include <iostream>

using namespace std;

inline void mycode(int arr[4][4],int sizearray){
    int arraysize=sizearray,arraylength=sizeof(arr[0])/sizeof(arr[0][0]),i=0,j=0,k=2*arraysize-2,up=0;
    cout<<arr[0][0]<<" ";
    while(k--){
        if(i==0 && j==0){
            i++;
            up=1;
        }
        else if(i==0 && j<arraylength-1){
            j++;
            up=0;
        }
        else if(i<arraysize-1 && j==0){
            i++;
            up=1;
        }
        else if(i<arraysize-1 && j==arraylength-1){
            i++;
            up=0;
        }
        else if(i==arraysize-1 && j<arraylength-1){
            j++;
            up=1;
        }
        if(up==1){
            while(i<arraysize && j<arraylength && i>=0 && j>=0){
                cout<<arr[i][j]<<" ";
                i--;
                j++;
            }
            i++;
            j--;
        }
        else{
            while(i<arraysize && j<arraylength && i>=0 && j>=0){
                cout<<arr[i][j]<<" ";
                i++;
                j--;
            }
            i--;
            j++;
        }
    }
}

int main(){
    int arr[4][4]={
        {1,3,4,10},
        {2,5,9,11},
        {6,8,12,15},
        {7,13,14,16}
    };
    mycode(arr,sizeof(arr)/sizeof(arr[0]));
}
