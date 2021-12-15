//KEEP CALM AND TRY TO SOLVE ATLEAST ONE PROBLEM
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<numeric>
#include<iomanip>

using namespace std;

#define FIO		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld		long double
#define endl		"\n"
#define fi		first
#define se		second
#define mp		make_pair
#define pb		push_back
#define all(a)		a.begin(),a.end()
#define CASE(t)         cout<<"Case #"<<(t)<<": ";
#define watch(x)	cout<<x<<endl;
#define watch2(x,y)	cout<<x<<" "<<y<<endl;
#define loop(i,a,b)	for(int i=a;i<b;i++)
//TEMPLATES
typedef vector<int64_t> vi;
typedef set<int64_t> si;


inline void solve(){
    int64_t n,reward=0;cin>>n;
    vector<pair<int64_t,int64_t>> deadlocks(n);
    for(int i=0;i<n;i++){
        cin>>deadlocks[i].first>>deadlocks[i].second;
    }
    sort(all(deadlocks));
    for(int i=0;i<n;i++){
        reward+=deadlocks[i].se-deadlocks[i].fi;
        deadlocks[i+1].fi+=deadlocks[i].fi;
    }
    cout<<reward<<endl;
}

int main(){
    FIO;
    //int64_t t;cin>>t;while(t--)
    solve();
}



