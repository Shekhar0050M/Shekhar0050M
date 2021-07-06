#include<iostream>

using namespace std;

int main(){
    int mainarr[]={8,5,2,9,5,6,3},n=sizeof(mainarr)/sizeof(mainarr[0]),key=0,j=0;
    for(int i=1;i<n;i++){
        key=mainarr[i];
        j=i-1;
        while(j>=0 && mainarr[j]>key){
            mainarr[j+1]=mainarr[j];
            j--;
        }
        mainarr[j+1]=key;
    }
    for(auto i:mainarr){
        cout<<i<<" ";
    }
}
