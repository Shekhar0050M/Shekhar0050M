#include <algorithm>
#include <cstdio>
#include<iostream>
#include <vector>

using namespace std;

class AncestralTree{
    public:
        char name;
        AncestralTree* ancestor;

        AncestralTree(char name){
            this->name=name;
            this->ancestor=NULL;
        }

        void addAsAncestor(vector<AncestralTree*> descendants);
};

inline void mymethod(){
    vector<vector<char>> tree{
            {'A','B','G'},
            {'A','B','H','O'},
            {'A','B','H','P','T'},
            {'A','B','H','P','U'},
            {'A','B','H','Q'},
            {'A','B','H','R','V','W'},
            {'A','B','H','R','V','X','Z'},
            {'A','B','H','R','V','Y'},
            {'A','B','I'},
            {'A','C','J'},
            {'A','D','K'},
            {'A','D','L'},
            {'A','E'},
            {'A','F','M'},
            {'A','F','N'}

    };
    vector<vector<char>> requiredpaths;
    vector<char> descendants{'I','T'};
    vector<int64_t> pos(descendants.size());
    for(auto z:descendants)
        for(auto i:tree){
            for(auto j:i){
                if(j==z){
                    requiredpaths.push_back(i);
                    break;
                }
            }
    }
    for(int64_t i=0;i<descendants.size();i++){
        pos[i]=(find(requiredpaths[i].begin(),requiredpaths[i].end(),descendants[i])-requiredpaths[i].begin());
    }
    pos[1]=pos[0]=min(pos[0],pos[1]);
    while(requiredpaths[0][pos[0]]!=requiredpaths[1][pos[1]]){
        pos[0]--;
        pos[1]--;
    }
    printf("Youngest common ancestor is %c",requiredpaths[0][pos[0]]);
}

int main(){
}
