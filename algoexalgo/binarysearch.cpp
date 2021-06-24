#include <iostream>

using namespace std;

inline bool binarysearch(int arr[],int upper,int lower,int key){
    int mid=(lower+upper)/2;
    if(lower==upper){
        return 0;
    }
    if(arr[mid]==key){
        cout<<arr[mid]<<" ";
        return 0;
    }
    binarysearch(arr,upper,mid,key);
    binarysearch(arr,mid+1,lower,key);
    return 0;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    binarysearch(arr,0,sizeof(arr)/sizeof(arr[0])-1,4);
}
