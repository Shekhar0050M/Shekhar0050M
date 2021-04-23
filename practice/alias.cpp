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
typedef vector<int> vi;
typedef set<int> si;


inline void solve(){
    int n=4;
    for(int b=1;b<(1<<n);b++){
	for(int k=1;k<n;k++){
	    if(b&(1<<k)){
		cout<<k<<" ";
	    }
	}
	cout<<endl;
    }
}

int main(){
    FIO;
    //int64_t t;cin>>t;while(t--)
    solve();
}


