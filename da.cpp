#include<iostream>

using namespace std;

int main(){
    int x;cin>>x;
    int arr[]={2,3,4,5};
    int *ar=new int(x);
    for(int i=0;i<x+4;i++){
        cout<<arr[i]<<endl;
    }
}
