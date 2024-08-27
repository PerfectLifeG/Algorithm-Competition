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
void solve(){
    int n,m;cin>>n>>m;
    vector<PII>edge;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        edge.push_back({a,b});
    }
    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            int a;cin>>a;
            mp[a]=1;
        }
        int flag=1;
        for(auto [i,j]:edge){
            if(mp.count(i)||mp.count(j));
            else {flag=0;break;}
        }
        if(flag)yes;
        else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}