#include <iostream>

using namespace std;

int main(){
    int mainarr[]={8,5,2,9,5,6,3},size=sizeof(mainarr)/sizeof(mainarr[0]),x=size;
    while(x--){
        for(int i=0;i<size-1;i++){
            if(mainarr[i]>mainarr[i+1]){
                swap(mainarr[i],mainarr[i+1]);
            }
        }
    }
    for(auto i:mainarr){
        cout<<i<<" ";
    }
}
