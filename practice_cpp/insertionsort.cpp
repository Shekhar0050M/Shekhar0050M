#include<iostream>

using namespace std;

int main(){
    int arr[]={24,87,65,87,45,98,35,76};
    int n=sizeof(arr)/sizeof(arr[0]),j=0,temp=0;
    for(int i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
