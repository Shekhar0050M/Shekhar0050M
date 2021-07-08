#include <iostream>

using namespace std;

inline int* nestedloop(int arr[],int sum,int size){
    static int array[3];
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int k=j+1;k<size;k++){
                if(arr[i]+arr[j]+arr[k]==sum){
                    array[0]=arr[i];
                    array[1]=arr[j];
                    array[2]=arr[k];
                    return array;
                }
            }
        }
    }
    return array;
}

inline void pointermethod(int arr[],int sum,int size){
    int start=1,end=size-1;
    sort(arr,arr+size);
    for(int i=0;i<size;i++){
        while(start<end){
            if(arr[i]+arr[start]+arr[end]==sum){
                cout<<arr[i]<<" "<<arr[start]<<" "<<arr[end]<<endl;
                start++;
                end--;
            }
            else if(arr[i]+arr[start]+arr[end]>sum){
                end--;
            }
            else if(arr[i]+arr[start]+arr[end]<sum){
                start++;
            }
            if(start>=end){
                break;
            }
        }
        start=i+2;
        end=size-1;
    }
}

inline void printarr(int ptr[]){
    for(int i=0;i<3;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={12,3,1,2,-6,5,-8,6},sum=0,size=sizeof(arr)/sizeof(arr[0]);
    int *ptr;
    ptr=nestedloop(arr,sum,size);
    pointermethod(arr,sum,size);
}
