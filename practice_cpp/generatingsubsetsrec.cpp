#include<iostream>
#include <string>
#include<vector>

using namespace std;

inline bool generatesubset(vector<int> &arr,int n,int size){
    if(size>n){
        cout<<"[ ";
        for(auto i:arr) cout<<i<<" ";
        cout<<"]"<<endl;
        return 1;
    }
    else{
    arr.push_back(size);
    generatesubset(arr,n,size+1);
    arr.pop_back();
    generatesubset(arr,n,size+1);
    }
    return 1;
}

int main(){
    vector<int> arr;
    generatesubset(arr,3,1);
}
