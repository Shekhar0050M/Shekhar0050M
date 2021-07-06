#include<iostream>

using namespace std;

int main(){
    int mainarr[]={141,1,17,-7,-17,-27,18,541,7,8,8},minthreeelement[3]={0},size=sizeof(mainarr)/sizeof(mainarr[0]);
    for(int i=0;i<3;i++){
        minthreeelement[i]=mainarr[i];
    }
    sort(minthreeelement,minthreeelement+3);
    for(int i=3;i<size;i++){
        for(int j=2;j>=0;j--){
            if(mainarr[i]>minthreeelement[j]){
                for(int k=0;k<j;k++){
                    swap(minthreeelement[k+1],minthreeelement[k]);
                }
                minthreeelement[j]=mainarr[i];
                break;
            }
        }
    }
    for(auto i:minthreeelement){
        cout<<i<<" ";
    }
}
