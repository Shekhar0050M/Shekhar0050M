#include<iostream>

using namespace std;

inline int binarysearch(int arr[],int key,int l,int r){
    int mid=(l+r)/2;
    if(arr[mid]>key){
        r=mid-1;
        binarysearch(arr,key,l,r);
    }
    else if(arr[mid]<key){
        l=mid+1;
        binarysearch(arr,key,l,r);
    }
    else{
        cout<<"Element found at position "<<mid<<endl;
        return 0;
    }
    return 0;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]),k=6;
    binarysearch(arr,k,0,n);
}


