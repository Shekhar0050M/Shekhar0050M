#include<iostream>

using namespace std;

int main(){
    int arr[]={-1,-5,-10,-1100,-1100,-1101,-1102,-9001},md=0,mi=0,cnst=0,size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            md=1;
        }
        else if(arr[i]<arr[i+1]){
            mi=1;
        }
        else{
            cnst=1;
        }
    }
    if(cnst==1 && mi==0 && md==0){
        cout<<"Error, try next time."<<endl;
    }
    else if(mi==1 && md==1){
        cout<<"Error ,try next time."<<endl;
    }
    else if(mi==1){
        cout<<"Monotonic Increasing"<<endl;
    }
    else{
        cout<<"Monotonic decreasing"<<endl;
    }

}
