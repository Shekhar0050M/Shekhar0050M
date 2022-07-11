#include <iostream>
#include <vector>

using namespace std;

inline bool transverse(int64_t i,int64_t j,int64_t area[7][7],int64_t visited[7][7],vector<int64_t> &sizes,int64_t currentsize){
    if((area[i][j-1]==0 || visited[i][j-1]==1) && (area[i][j+1]==0 || visited[i][j+1]==1) && (area[i+1][j]==0 || visited[i+1][j]==1)){
        sizes.push_back(currentsize);
        return 1;
    }
    if(area[i][j-1]==1 && visited[i][j-1]==0){
        visited[i][j-1]=1;
        transverse(i,j-1,area,visited,sizes,currentsize+1);
    }
    if(area[i][j+1]==1 && visited[i][j+1]==0){
        visited[i][j+1]=1;
        transverse(i,j+1,area,visited,sizes,currentsize+1);
    }
    if(area[i+1][j]==1 && visited[i+1][j]==0){
        visited[i+1][j]=1;
        transverse(i+1,j,area,visited,sizes,currentsize+1);
    }
    return 0;
}

int main(){
    int64_t area[7][7]={
        {0,0,0,0,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,1,0,0,0},
        {0,0,0,1,0,1,0},
        {0,1,0,1,0,1,0},
        {0,1,0,1,1,0,0},
        {0,0,0,0,0,0,0}
    },visited[7][7]={0};
    vector<int64_t> sizes;
    for(int64_t i=0;i<7;i++){
        for(int64_t j=0;j<7;j++){
            if(area[i][j]==0){
                visited[i][j]=1;
            }
            if(visited[i][j]==0){
                visited[i][j]=1;
                transverse(i,j,area,visited,sizes,1);
            }
        }
    }
    for(auto i:sizes){
        cout<<i<<" ";
    }
}
