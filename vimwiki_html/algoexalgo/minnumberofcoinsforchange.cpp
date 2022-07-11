#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// My method
//Never use
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

inline int algoguymethod(int denominations[],int n,int amount){
    sort(denominations,denominations+n);
    vector<int> ways(amount+1);
    for(int i=0;i<n;i++){
        for(int j=denominations[i];j<=amount;j++){
            ways[j]=ways[j-denominations[i]]+1;
        }
    }
    return ways[amount];
}

int main(){
    int denominations[]={1,2,4},amount=6,n=sizeof(denominations)/sizeof(denominations[0]);
    vector<int> ways,coinnum;
    //leastcoins(denominations,amount,0,n,ways,coinnum);
    //printf("Minimum coins can be of :: %d\n",*min_element(coinnum.begin(),coinnum.end()));


    printf("Minimum coins by algo guy:: %d",algoguymethod(denominations,n,amount));
}
