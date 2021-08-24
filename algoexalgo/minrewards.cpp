#include <algorithm>
#include<iostream>
#include<numeric>
#include <vector>

using namespace std;

#define print(val) cout<<val<<endl;

//T.C. O(N²) S.C. O(N)
inline int methodone(int arr[],int size){
    int rewards[size],k=0;
    for(int i=0;i<size;i++){
        rewards[i]=1;
    }
    for(int i=1;i<size;i++){
        if(arr[i]>arr[i-1]){
            rewards[i]=rewards[i-1]+1;
        }
        else{
            k=i-1;
            while(arr[k]>arr[k+1] && k>=0){
                rewards[k]=max(rewards[k],rewards[k+1]+1);
                k--;
            }
        }
    }
    return accumulate(rewards,rewards+size,0);
}

//T.C. O(N) S.C. O(N)
inline int methodtwo(int arr[],int size){
    int rewards[size],k=0;
    for(int i=0;i<size;i++){
        rewards[i]=1;
    }
    vector<int> localminimas;
    if(arr[0]<arr[1]){
        localminimas.push_back(0);
    }
    if(arr[size-1]<arr[size-2]){
        localminimas.push_back(size-1);
    }
    for(int i=1;i<size-1;i++){
        if(arr[i]<arr[i+1] && arr[i]<arr[i-1]){
            localminimas.push_back(i);
        }
    }
    for(auto i:localminimas){
        k=i+1;
        while(arr[k]>arr[k-1]){
            rewards[k]=rewards[k-1]+1;
            k++;
        }
        k=i-1;
        while(arr[k]>arr[k+1]){
            rewards[k]=max(rewards[k],rewards[k+1]+1);
            k--;
        }
    }
    return accumulate(rewards,rewards+size,0);
}

//T.C. O(N) S.C. O(N)
inline int methodthree(int arr[],int size){
    int rewards[size];
    for(int i=0;i<size;i++){
        rewards[i]=1;
    }
    for(int i=0;i<size;i++){
        if(arr[i]>arr[i-1]){
            rewards[i]=rewards[i-1]+1;
        }
    }
    for(int i=size-1;i>=0;i--){
        if(arr[i]>arr[i+1]){
            rewards[i]=max(rewards[i],rewards[i+1]+1);
        }
    }
    return accumulate(rewards,rewards+size,0);
}

int main(){
    int scores[]={8,4,2,1,3,6,7,9,5},sz=sizeof(scores)/sizeof(scores[0]);
    print(methodthree(scores,sz));
}

