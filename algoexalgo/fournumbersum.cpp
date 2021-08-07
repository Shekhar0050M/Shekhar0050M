#include <cstdio>
#include <iostream>

using namespace std;

inline void fournumbersummymtd(int arr[],int value,int size){
    int k=0,l=size-1;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            k=j+1;
            l=size-1;
            while(k<l){
                if(arr[i]+arr[j]+arr[k]+arr[l]==value){
                    printf("Position of coordinates are :: %d %d %d %d",i,j,k,l);
                    break;
                }
                else if(arr[i]+arr[j]+arr[k]+arr[l]>value){
                    l--;
                }
                else{
                    k++;
                }
            }
        }
    }
}

int main(){
    int arr[]={7,6,4,-1,1,2},value=16;
    fournumbersummymtd(arr,value,sizeof(arr)/sizeof(arr[0]));
}
