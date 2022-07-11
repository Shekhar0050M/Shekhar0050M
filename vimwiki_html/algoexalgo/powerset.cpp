#include <cstdio>
#include<iostream>
#include <vector>

using namespace std;

inline void iterativemethod(vector<vector<int>> &powerset,vector<int> &arr,int n){
    int sz=0;
    vector<int> currentvec;
    powerset.push_back({});
    for(int i=0;i<n;i++){
        sz=powerset.size();
        for(int j=0;j<sz;j++){
            for(auto k:powerset[j]){
                currentvec.push_back(k);
            }
            currentvec.push_back(arr[i]);
            powerset.push_back(currentvec);
            currentvec.clear();
        }
    }
}

inline void printarr(vector<vector<int>> &powerset){
    for(auto i:powerset){
        cout<<"[ ";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"]\n";
    }
}

int main(){
    vector<int> arr;
    for(int i=1;i<10;i++){
        arr.push_back(i);
    }
    vector<vector<int>> powerset;
    iterativemethod(powerset,arr,arr.size());
    printf("Iterative method:: \n");
    printarr(powerset);
}
