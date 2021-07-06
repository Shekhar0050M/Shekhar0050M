#include <iostream>

using namespace std;

int main(){
    char s[]="abcdcba";
    int k=7;
    for(int i=0;i<k/2+1;i++){
        if(s[i]!=s[k-1-i]){
            cout<<"NOT A PALINDROME"<<endl;
            return 0;
        }
    }
    cout<<"PALINDROME"<<endl;
}
