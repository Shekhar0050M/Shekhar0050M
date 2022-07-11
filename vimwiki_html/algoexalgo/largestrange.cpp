#include <algorithm>
#include<iostream>
#include <vector>
#include<unordered_map>
#include <set>

using namespace std;

inline int minemethod(int arr[],int size){
    int maxCount=0,currentRange=0,temp=0,temp2=0;
    set<int> newArray;
    for(int i=0;i<size;i++){
        newArray.insert(arr[i]);
    }
    for(set<int>::iterator it=newArray.begin();it!=newArray.end();++it){
        temp=*it++;
        temp2=*it--;
        if(temp2-temp==1){
            maxCount+=1;
            currentRange=max(currentRange,maxCount);
        }
        else{
            maxCount=0;
        }
    }
    return currentRange+1;
}

int main(){
    int arr[]={1,11,3,0,15,5,2,4,10,7,12,6},sz=sizeof(arr)/sizeof(arr[0]);
    cout<<minemethod(arr,sz)<<endl;
}

