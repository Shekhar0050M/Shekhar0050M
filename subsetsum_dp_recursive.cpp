//alias accumulate(all(a),0)-->accumulate(all(a),0LL)
//EXCLUDE DOING OPERATION ON SAME ARRAY WE HAVE ENOUGH STORAGE
//KEEP CALM AND TRY TO SOLVE ATLEAST ONE PROBLEM


#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>

using namespace std;

#define FIO	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll	long long
#define ld	long double
#define fi	first
#define se	second
#define mp	make_pair
#define pb	push_back
#define all(a)	a.begin(),a.end()
#define CASE(t)         cout<<"Case #"<<(t)<<": ";
#define mset(a,val)     memset(a,val,sizeof(a))

inline bool subsetsum(int target,int set[],int n){
    if(target==0) return true;
    if(target<0) return false;
    if(n==0) return false;
    
    return subsetsum(target,set,n-1) || subsetsum(target-set[n-1],set,n-1);
}

inline void solve(){
    int target=300;
    int set[]={7,14};
    int n=sizeof(set)/sizeof(set[0]);
    if(subsetsum(target,set,n)==true){
        cout<<"Subset sum is possible."<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }
}

int main(){
    FIO;
        solve();
}




