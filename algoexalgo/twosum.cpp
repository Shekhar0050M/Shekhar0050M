#include <algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

//O(n²) TC / O(1) SC
inline int* nestedloop(int arr[],int sum,int n){
    static int array[2]={0};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
                array[0]=arr[i];
                array[1]=arr[j];
                return array;
            }
        }
    }
    return array;
}


//O(nlogn) TC / O(1) SC
inline int* twopointer(int arr[],int sum,int n){
    static int array[2]={0};
    int begin=0,end=n-1;
    for(int i=0;i<n;i++){
        if(begin==end){
            break;
        }
        if(arr[begin]+arr[end]<sum){
            begin++;
        }
        else if(arr[begin]+arr[end]>sum){
            end--;
        }
        else if(arr[begin]+arr[end]==sum){
            break;
        }
    }
    array[0]=arr[begin];
    array[1]=arr[end];
    return array;
}

//O(n) TC / O(n) SC
inline int* hashmaping(int arr[],int sum,int n){
    static int array[2]={0};
    unordered_map<int,int> nums;
    for(int i=0;i<n;i++){
        if(nums.find(sum-arr[i])==nums.end()){
            nums[arr[i]]=1;
        }
        else{
            array[0]=sum-arr[i];
            array[1]=arr[i];
            return array;
        }
    }
    return array;
}

inline void print(int array[]){
    for(int i=0;i<2;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={3,5,-4,8,11,1,-1,6},sum=10,n=sizeof(arr)/sizeof(arr[0]);
    int *ptr=nestedloop(arr,sum,n);
    print(ptr);
    ptr=twopointer(arr,sum,n);
    print(ptr);
    ptr=hashmaping(arr,sum,n);
    print(ptr);
}
