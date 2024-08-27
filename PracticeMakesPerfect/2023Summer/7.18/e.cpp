#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int qk(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int inv(int a)
{
    return qk(a,mod-2);
}
int n;
vector<int>v[N];
int son[N];
int f1[N];
int dfs1(int t,int fa){
    
    int now=0;
    for(int i=0;i<v[i].size();i++){
        int j=v[t][i];
        if(j==fa)continue;
        now^=(dfs1(j,t)+1);
    }
    f1[u]=now;
    return;
}
void dfs2(int u,int fa){
    int now=0;
    for(int i=0;i<v[i];i=e[i].to){
        int v=e[i].v;
        if(v==fa)continue;
        dfs1(v,u);
        now^=(f1[v]+1);
    }
    f1[u]=now;
    return;
}
void solve()
{
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}