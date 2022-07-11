#include <iostream>

using namespace std;

inline void mymethod(int arr[],int size,int key){
    int start=0,end=size-1;
    while(start<end){
        if(arr[start]==arr[end]==key){
            end--;
        }
        else if(arr[start]==key){
            swap(arr[start],arr[end]);
            if(start!=0)
                start++;
            end--;
        }
        else if(arr[end]==key){
            swap(arr[start],arr[end]);
            end--;
            start++;
        }
        else{
            start++;
        }
    }
    for(int i=0;i<size;i++){
        cout<<i<<" ";
    }
}

inline void expertmethod(int arr[],int size,int key){
    int start=0,end=size-1;
    while(start<end){
        while(start<end && arr[end]==key){
            end--;
        }
        if(arr[start]==2){
            swap(arr[start],arr[end]);
        }
        start++;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={2,1,2,2,2,3,4,2},size=sizeof(arr)/sizeof(arr[0]);
    //mymethod(arr,size,2);
    expertmethod(arr,size,2);
}
