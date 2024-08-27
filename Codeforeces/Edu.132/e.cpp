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
set<int>st[N];
vector<int>v[N];
int val[N];
int sum[N];
int ans;
void dfs1(int t,int fa){
    for(auto j:v[t]){
        if(j==fa)continue;
        sum[j]=val[j]^sum[t];
        dfs1(j,t);
    }
}
void dfs2(int t,int fa){
    st[t].insert(sum[t]);
    int flag=0;
    for(auto j:v[t]){
        if(j==fa)continue;
        dfs2(j,t);
        if(st[t].size()<st[j].size())swap(st[t],st[j]);
        for(auto i:st[j]){
            if(!flag&&st[t].count(i^val[t]))flag=1;
        }
        for(auto i:st[j])st[t].insert(i);
    }
    if(flag)ans++,st[t].clear();
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    sum[1]=val[1];
    dfs1(1,1);
    dfs2(1,1);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}