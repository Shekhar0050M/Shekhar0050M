#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// My method
inline bool leastcoins(int denominations[],int amount,int currentsum,int n,vector<int> &coins,vector<int> &coinnum){
    if(currentsum==amount){
        coinnum.push_back(coins.size());
        return 1;
    }
    else if(currentsum>amount){
        return 0;
    }
    for(int i=0;i<n;i++){
        coins.push_back(denominations[i]);
        leastcoins(denominations,amount,currentsum+denominations[i],n,coins,coinnum);
        coins.pop_back();
    }
    return 0;
}

int main(){
    int denominations[]={1,2,4},amount=6,n=sizeof(denominations)/sizeof(denominations[0]);
    vector<int> ways,coinnum;
    leastcoins(denominations,amount,0,n,ways,coinnum);
    printf("Minimum coins can be of :: %d",*min_element(coinnum.begin(),coinnum.end()));
}
