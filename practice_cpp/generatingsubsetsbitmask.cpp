#include<iostream>
#include <vector>

using namespace std;

int main(){
    int n=3;
    for(int i=0;i<(1<<3);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cout<<j<<" ";
        }
        cout<<endl;
    }
}
