#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>

using namespace std;

inline int getnextindex(int arr[],int currentindex,int n){
    int jump=(currentindex+arr[currentindex])%n;
    if(jump<0){
        return n+jump;
    }
    return jump;
}

inline bool mymethod(int arr[],int n){
    int numberfocount=0,currentindex=0;
    while(numberfocount<n){
        if(numberfocount>0 && currentindex==0){
            return 0;
        }
        numberfocount+=1;
        currentindex=getnextindex(arr,currentindex,n);
    }
    return 1;
}

int main(){
    int arr[]={2,3,1,-4,-4,2},n=sizeof(arr)/sizeof(arr[0]);
    if(mymethod(arr,n)){
        printf("It is single cyclic.\n");
    }
    else{
        printf("Not single cyclic.\n");
    }
}
