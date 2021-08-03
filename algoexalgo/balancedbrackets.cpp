#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

inline int64_t checkIfSame(char k,string str){
    int n=str.size();
    for(int i=0;i<n;i++){
        if(str[i]==k){
            return i;
        }
    }
    return -1;
}

inline void balancedBrackets(string str){
    string openingBracket="({[",closingBracket=")}]";
    int x=0;
    stack<char> mystack;
    for(auto i:str){
        x=checkIfSame(i,closingBracket);
        if(x==-1){
            mystack.push(i);
        }
        else{
            if(openingBracket[x]==mystack.top()){
                mystack.pop();
            }
            else{
                printf("Not balanced");
                return;
            }
        }
    }
    printf("Balanced");
}

int main(){
    string str="(([]()()){})";
    balancedBrackets(str);
}
