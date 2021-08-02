#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

inline void insert(vector<pair<int64_t,int64_t>> &minMaxStack,stack<int64_t> &stack,int64_t value){
    if(stack.empty()){
        minMaxStack.push_back(make_pair(value,value));
        stack.push(value);
        return;
    }
    minMaxStack.push_back(make_pair(min(minMaxStack[minMaxStack.size()-1].first,value),max(minMaxStack[minMaxStack.size()-1].second,value)));
    stack.push(value);
}

inline void getMin(vector<pair<int64_t,int64_t>> &minMaxStack){
    printf("%ld ",minMaxStack[minMaxStack.size()-1].first);
}

inline void getMax(vector<pair<int64_t,int64_t>> &minMaxStack){
    printf("%ld ",minMaxStack[minMaxStack.size()-1].second);
}

inline void peek(stack<int64_t> &stack){
    cout<<stack.top()<<" ";
}

int main(){
    vector<pair<int64_t,int64_t>> minMaxStack;
    stack<int64_t> stack;
    insert(minMaxStack,stack,5);
    insert(minMaxStack,stack,7);
    insert(minMaxStack,stack,2);
}
