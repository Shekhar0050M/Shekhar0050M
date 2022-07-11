#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int denominations[]={1,5,10,25},n=sizeof(denominations)/sizeof(denominations[0]),amount=10;
    vector<int> ways(11);
    ways[0]=1;
    for(int i=0;i<n;i++){
        for(int j=denominations[i];j<=amount;j++){
            ways[j]+=ways[j-denominations[i]];
        }
    }
    printf("Number of ways:: %d",ways[10]);
}
