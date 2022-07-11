#include <cstdio>
#include<iostream>
#include <vector>

using namespace std;

inline int64_t peek(vector<int64_t> &arr,int64_t k);

inline void siftdown(vector<int64_t> &arr,int64_t pos);

inline void printheap(vector<int64_t> &arr);

//T.C. O(N) S.C. O(1)
inline void buildheap(vector<int64_t> &arr){
    for(int64_t i=arr.size()-1;i>=0;i--){
        siftdown(arr,i);
    }
}

//T.C. O(logN) S.C. O(1)
inline void siftup(vector<int64_t> &arr){
    int i=arr.size()-1;
    while(i>0){
        if(arr[i]<arr[(i-1)/2]){
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
        else{
            break;
        }
    }
}

//T.C. O(l9gN) S.C. O(q)
inline void siftdown(vector<int64_t> &arr,int64_t pos){
    int i=pos,arrsize=arr.size();
    while(i<arrsize){
        if(arr[2*i+1]<=arr[2*i+2] && arr[i]>arr[2*i+1] && 2*i+1<arrsize){
            swap(arr[i],arr[2*i+1]);
            i=2*i+1;
        }
        else if(arr[2*i+2]<arr[2*i+1] && arr[i]>arr[2*i+2] && 2*i+2<arrsize){
            swap(arr[i],arr[2*i+2]);
            i=2*i+2;
        }
        else{
            break;
        }
    }
}

//T.C. O(logN) S.C. O(1)
inline void insert(vector<int64_t> &arr){
    int64_t k;
    printf("Enter the data you want to insert:: ");
    scanf("%ld",&k);
    arr.push_back(k);
    siftup(arr);
}

//T.C. O(logN) S.C. O(1)
inline void remove(vector<int64_t> &arr){
    swap(arr[0],arr[arr.size()-1]);
    arr.pop_back();
    siftdown(arr,0);
}

//T.C. O(1) S.C. O(1)
inline int64_t peek(vector<int64_t> &arr){
    printf("Min value:: %ld",arr[0]);
    return 0;
}

//T.C. O(N) S.C. O(1)
inline void printheap(vector<int64_t> &arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int64_t> arr{8,12,23,17,31,30,44,102,18};
    swap(arr[0],arr[arr.size()-1]);
    buildheap(arr);
    printheap(arr);
}
