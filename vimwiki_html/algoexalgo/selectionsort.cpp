#include <algorithm>
#include<iostream>

using namespace std;

int main(){
    int mainarr[]={8,5,2,9,5,6,3},n=sizeof(mainarr)/sizeof(mainarr[0]),k=0;
    for(int i=0;i<n;i++){
        k=(min_element(mainarr+i,mainarr+n)-mainarr);
        swap(mainarr[i],mainarr[k]);
    }
    for(auto i:mainarr){
        cout<<i<<" ";
    }
}
