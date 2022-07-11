#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

//O(n³) T.C. O(1) S.C. i prefer this one
inline void fournumbersummymtd(int arr[],int value,int size){
    sort(arr,arr+size);
    int k=0,l=size-1;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            k=j+1;
            l=size-1;
            while(k<l){
                if(arr[i]+arr[j]+arr[k]+arr[l]==value){
                    printf("Values are :: %d %d %d %d",arr[i],arr[j],arr[k],arr[l]);
                    break;
                }
                else if(arr[i]+arr[j]+arr[k]+arr[l]>value){
                    l--;
                }
                else{
                    k++;
                }
            }
        }
    }
}

// O(n²) T.C. O(n²) S.C.
inline bool methodbyalgoguy(int arr[],int value,int size){
    unordered_map<int,vector<int>> allpairsum;
    vector<vector<int>> quadruplets;
    int currentsum=0,difference=0;
    for(int i=1;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            difference=value-arr[i]-arr[j];
            if(allpairsum.find(difference)!=allpairsum.end()){
                for(int x=0;x<allpairsum[difference].size();x+=2){
                    quadruplets.push_back({arr[x],arr[x+1],arr[i],arr[j]});
                }
            }
        }
        for(int k=0;k<i;k++){
            currentsum=arr[i]+arr[k];
            if(allpairsum.find(currentsum)==allpairsum.end()){
                allpairsum[currentsum]=vector<int>();
                allpairsum[currentsum].push_back(arr[i]);
                allpairsum[currentsum].push_back(arr[k]);
            }
            else{
                allpairsum[currentsum].push_back(arr[i]);
                allpairsum[currentsum].push_back(arr[k]);
            }
        }
    }
    for(auto i:quadruplets){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 1;
}

int main(){
    int arr[]={7,6,4,-1,1,2},value=16;
    //fournumbersummymtd(arr,value,sizeof(arr)/sizeof(arr[0]));
    methodbyalgoguy(arr,value,sizeof(arr)/sizeof(arr[0]));
}
