#include<iostream>

using namespace std;

inline void merge(int arr[],int low,int mid,int high){
    int i=low,j=mid+1,b[high],k=low;
    while(i<=mid && k<=high){
        if(arr[i]<=arr[j]){
            b[k++]=arr[i++];
        }
        else{
            b[k++]=arr[j++];
        }
    }
    if(i<mid+1){
        while(i<=mid){
            b[k++]=arr[i++];
        }
    }
    else{
        while(j<=high){
            b[k++]=arr[j++];
        }
    }
    for(k=low;k<=high;k++){
        arr[k]=b[k];
    }
}

inline void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main(){
    int arr[]={34,54,87,6,75,46,29,45,88};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
