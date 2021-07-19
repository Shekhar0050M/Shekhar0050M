#include <algorithm>
#include <iostream>

using namespace std;

//T.C.O(N) / S.C. O(N)
inline int mthd1(int arr[],int n){
    int maxsum[n];
    maxsum[0]=arr[0];
    maxsum[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        maxsum[i]=max(maxsum[i-1],maxsum[i-2]+arr[i]);
    }
    return maxsum[n-1];
}

//T.C.O(N) / S.C. O(1)
inline int mthd2(int arr[],int n){
    int maxvalue=0,first=arr[0],second=max(arr[0],arr[1]);
    for(int i=2; i<n; i++){
        maxvalue=max(first+arr[i],second);
        first=second;
        second=maxvalue;
    }
    return maxvalue;
}

int main(){
    int arr[]={7,10,12,7,9,14},n=sizeof(arr)/sizeof(arr[0]);
    cout<<mthd1(arr,n)<<" "<<mthd2(arr,n);
}
