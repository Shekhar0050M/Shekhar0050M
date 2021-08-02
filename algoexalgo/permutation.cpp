#include <algorithm>
#include<iostream>

using namespace std;

inline int factorial(int n){
    if(n==1 || n==0) return 1;
    return n*factorial(n-1);
}

inline void standardmethod(string s){

    for(int i=0;i<factorial(s.size());i++){
        next_permutation(s.begin(),s.end());
        cout<<s<<"\n";
    }
}

inline void nonstandardmethod(string s,int start,int end){
    if(start==end){
        cout<<s<<"\n";
        return;
    }
    for(int i=1;i<=end;i++){
        swap(s[start],s[i]);
        nonstandardmethod(s,start+1,end);
        swap(s[start],s[i]);
    }
}

int main(){
    string s="123";
    //standardmethod(s);
    nonstandardmethod(s,0,s.size()-1);
}
