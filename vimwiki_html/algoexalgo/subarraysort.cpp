#include <cstdio>
#include<iostream>

using namespace std;

inline bool isOutOfOrder(int pos,int value,int arr[],int size){
    if(pos==0){
        return value>arr[pos+1];
    }
    if(pos==size-1){
        return value<arr[pos-1];
    }
    return (value>arr[pos+1] || value<arr[pos-1]);
}

int main(){
    int arr[]={1,2,4,7,10,11,7,12,6,7,16,18,19},minposition=INT_MAX,maxposition=INT_MIN,sz=sizeof(arr)/sizeof(arr[0]),subArrayIndexLeft=0,minElementPosAmongUnsortedArray=0;
    for(int i=0;i<sz;i++){
        if(isOutOfOrder(i,arr[i],arr,sz)){
            minposition=min(minposition,i);
            maxposition=max(maxposition,i);
        }
    }
    if(minposition==INT_MAX){
        printf("Sorted array\n");
        return 0;
    }
    minposition++;
    maxposition++;
    minElementPosAmongUnsortedArray=(min_element(arr+minposition,arr+maxposition+1)-arr);
    for(int i=0;i<sz;i++){
        if(arr[i]>arr[minElementPosAmongUnsortedArray]){
            subArrayIndexLeft=i;
            break;
        }
    }
    sort(arr+subArrayIndexLeft,arr+maxposition+1);
    for(auto i:arr){
        cout<<i<<" ";
    }
}
