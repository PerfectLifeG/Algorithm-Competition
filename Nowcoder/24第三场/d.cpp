#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<PII>v[N];
map<PII,int>mp;
void dfs(){
    
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        mp[{x,y}]++;
    }
    int cnt=0;
    for(auto &[i,j]:mp){
        v[i.first].push_back({i.second,j});
    }
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}