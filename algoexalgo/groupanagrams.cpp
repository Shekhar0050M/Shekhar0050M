#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline void mymethod(vector<string> &group,vector<vector<string>> &answer){
    int64_t k=0;
    string sz;
    vector<pair<string,string>> mymap;
    for(auto i:group){
        sz=i;
        sort(sz.begin(),sz.end());
        mymap.push_back(make_pair(sz,i));
    }
    sort(mymap.begin(),mymap.end());
    int sizeo=group.size();
    answer[0].push_back(mymap[0].second);
    for(int i=1;i<sizeo;i++){
        if(mymap[i].first==mymap[i-1].first){
            answer[k].push_back(mymap[i].second);
        }
        else{
            k++;
            answer[k].push_back(mymap[i].second);
        }
    }
}

inline void myprintsets(vector<vector<string>> &answer){
    for(auto i:answer){
        if(i.size()==0){
            break;
        }
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<string> group{"yo","act","flop","tac","cat","oy","olfp"};
    vector<vector<string>> answer(group.size());
    mymethod(group,answer);
    
}
