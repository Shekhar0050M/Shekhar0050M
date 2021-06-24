#include <cstdio>
#include <iostream>
#include <any>
#include <vector>
using namespace std;

inline int productsum(vector<any> arr,int multiplier){
    int result=0;
    for(auto i:arr){
        if(i.type() == typeid(vector<any>)){
            result+=productsum(any_cast<vector<any>>(i),multiplier+1);
        }
        else{
            result+=any_cast<int>(i);
        }
    }
    return result*multiplier;
}

int main(){
    vector<any> a{5,2,vector<any> {7,-1},3,vector<any> {6,vector<any> {-13,8},4}};
    int sum=productsum(a,1);
    printf("%d",sum);
}
