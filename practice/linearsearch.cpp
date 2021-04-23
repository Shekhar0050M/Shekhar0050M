#include<iostream>

using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]==4){
            cout<<"Element found at position "<<i+1<<endl;;
        }
    }
    return 0;
}
