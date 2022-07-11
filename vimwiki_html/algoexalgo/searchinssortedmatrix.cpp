#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

inline bool findval(vector<vector<int64_t>> &twodArray,int64_t key){
    int64_t posI=0,posY=twodArray.size()-1,sz=twodArray.size();
    while(1){
        if(twodArray[posI][posY]==key){
            printf("Found at %ld %ld",posI,posY);
            return 1;
        }
        else if(twodArray[posI][posY]>key){
            posY--;
        }
        else{
            posI++;
        }
        if(posI==sz || posY==-1){
            break;
        }
    }
    return 0;
}

int main(){
    vector<vector<int64_t>> twodArray={
        {1,4,7,12,15,1000},
        {2,5,19,31,32,1001},
        {3,8,24,33,35,1002},
        {40,41,42,44,45,1003},
        {99,100,103,106,128,1004}
    };
    if(!findval(twodArray,10)) printf("Not found.");
}
