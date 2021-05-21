#include<iostream>
#include<vector>
#include<queue>

using namespace std;

inline void addedge(vector<int> a[],int u,int v){
    a[u].push_back(v);
}

inline void printgraph(vector<int> a[],int n){
    
    for(int i=0;i<n;i++){
        for(auto j:a[i]){
            cout<<"->"<<j;
        }
        cout<<endl;
    }
}

inline bool pathfinder(vector<int> a[],int n,int source,int destination){
    vector<bool> reached(n,0);
    queue<int> path;
    path.push(source);
    reached[source]=true;
    while(!path.size()){
        int s=path.front();
        path.pop();
        if(s==destination){
            return true;
        }
        for(auto i:a[s]){
            if(i!=destination){
                path.push(i);
                reached[i]=true;
            }
        }
    }
    return false;
}

int main(){
    int n=8,source=0,destination=7;
    vector<int> vec[n];
    addedge(vec,0,3);
    addedge(vec,1,0);
    addedge(vec,1,4);
    addedge(vec,1,2);
    addedge(vec,2,7);
    addedge(vec,3,4);
    addedge(vec,3,5);
    addedge(vec,4,3);
    addedge(vec,4,3);
    addedge(vec,5,6);
    addedge(vec,6,7);
    printgraph(vec,n);
    if(pathfinder(vec,n,source,destination)){
        cout<<"Path is possible"<<endl;
    }
    else{
        cout<<"Path is not possible"<<endl;
    }
}
