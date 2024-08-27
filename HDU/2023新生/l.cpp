#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v(n);
    vector<int>w(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }
    for(int i=0;i<n;i++){
    	cin>>w[i];
    }
    sort(all(v));
    sort(all(w));
    for(int i=0;i<n;i++){
    	if(v[i]<w[i]){
    		no;
    		return;
    	}
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}