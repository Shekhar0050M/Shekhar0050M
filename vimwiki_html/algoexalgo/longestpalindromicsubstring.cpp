#include <cstdio>
#include<iostream>
#include <string>

using namespace std;

inline int64_t mymethod(string str){
    int64_t x=0,y=0,currentMax=0,sz=str.size();
    for(int64_t j=0;j<sz;j++){
        x=y=j;
        while(1){
            if(str[x]==str[y+1]){
                y++;
            }
            else if(str[x-1]==str[y+1]){
                x--;
                y++;
            }
            else{
                currentMax=max(currentMax,abs(x-y)+1);
                break;
            }
        }
    }
    return currentMax;
}

int main(){
    string str="abaxyzzyxf";
    printf("Palindrome maximum of size %ld",mymethod(str));
}
