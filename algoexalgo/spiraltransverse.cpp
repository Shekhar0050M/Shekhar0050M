#include <iostream>

using namespace std;

#define N 4

inline void mymethoditerative(int64_t arr[N][N]){
    for(int i=0;i<N/2;i++){
        for(int j=i;j<N-i;j++){
            cout<<arr[i][j]<<" ";
        }
        for(int j=i+1;j<N-i;j++){
            cout<<arr[j][N-i-1]<<" ";
        }
        for(int j=N-i-1-1;j>=i;j--){
            cout<<arr[N-i-1][j]<<" ";
        }
        for(int j=N-i-1-1;j>=0;j--){
            if(j==i){
                break;
            }
            cout<<arr[j][i]<<" ";
        }
    }
}

inline void algoexpertrecursive(int64_t arr[N][N],int64_t startrow,int64_t endrow,int64_t startclmn,int64_t endclmn){
    if(startrow>endrow && startclmn>endclmn){
        return;
    }
    for(int j=startclmn;j<=endclmn;j++){
        cout<<arr[startrow][j]<<" ";
    }
    for(int i=startrow+1;i<=endrow;i++){
        cout<<arr[i][endclmn]<<" ";
    }
    for(int j=endclmn-1;j>=startclmn;j--){
        cout<<arr[endrow][j]<<" ";
    }
    for(int i=endrow-1;i>=startrow;i--){
        if(i==startrow){
            break;
        }
        cout<<arr[i][startclmn]<<" ";
    }
    algoexpertrecursive(arr,startrow+1,endrow-1,startclmn+1,endclmn-1);
}

int main(){
    int64_t arr[N][N]={
        {1,2,3,4},
        {12,13,14,5},
        {11,16,15,6},
        {10,9,8,7}
    };
    cout<<"Iterative Method:: ";
    mymethoditerative(arr);
    cout<<endl<<"Recursove Method:: ";
    algoexpertrecursive(arr,0,N-1,0,N-1);
}

