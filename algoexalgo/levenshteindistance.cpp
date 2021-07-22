#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

inline int algoguymethod(string str1,string str2){
    int str1size=str1.size(),str2size=str2.size();
    int arr[str1size+1][str2size+1];
    arr[0][0]=0;
    for(int i=1;i<=str2size;i++){
        arr[0][i]=arr[0][i-1]+1;
    }
    for(int j=1;j<=str2size;j++){
        arr[j][0]=arr[j-1][0]+1;
    }

    for(int i=1;i<=str1size;i++){
        for(int j=1;j<=str2size;j++){
            if(str1[i-1]==str2[j-1]){
                arr[i][j]=arr[i-1][j-1];
            }
            else{
                arr[i][j]=min({arr[i-1][j-1],arr[i][j-1],arr[i-1][j]})+1;
            }
        }
    }
    //for(int i=0;i<=str1size;i++){
        //for(int j=0;j<=str2size;j++){
            //cout<<arr[i][j]<<" ";
        //}
        //cout<<"\n";
    //}
    return arr[str1size][str2size];
}

int main(){
    string str1="abc",str2="yabd";
    printf("Answer is:: %d",algoguymethod(str1,str2));
}
