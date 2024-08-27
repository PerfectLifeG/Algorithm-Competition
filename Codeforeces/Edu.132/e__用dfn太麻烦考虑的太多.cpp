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
vector<int>v[N];
int dfn[N],idx=1;
int adfn[N];
int val[N];
int sz[N];
int son[N];
int sum[N];
int book[N];
int book2[N];
int ans;
unordered_map<int,int>mp;
int dfs1(int t,int fa){
    sz[t]=1;
    dfn[t]=idx;
    adfn[idx++]=t;
    for(auto j:v[t]){
        if(j==fa)continue;
        sum[j]=sum[t]^val[j];
        sz[t]+=dfs1(j,t);
        if(sz[j]>sz[son[t]])son[t]=j;
    }
    return sz[t];
}
void dfs2(int t,int fa){
    int flag=0;
    for(auto j:v[t]){
        if(j==fa||j==son[t]||book2[j])continue;
        dfs2(j,t);
    }
    if(son[t])dfs2(son[t],t);
    mp[sum[t]]++;
    if(mp[sum[t]^val[t]]>0)flag=1;
    for(auto j:v[t]){
        if(j==fa||j==son[t]||book2[j])continue;
        for(int i=dfn[j];i<dfn[j]+sz[j];i++){
            int p=adfn[i];
            if(book2[p])continue;
            if(!flag&&mp[sum[p]^val[t]]>0)flag=1;
        }
        for(int i=dfn[j];i<dfn[j]+sz[j];i++){
            int p=adfn[i];
            if(book2[p])continue;
            mp[sum[p]]++;
        }
    }
    if(flag){
        ans++;
        mp[sum[t]]--;
        book2[t]=1;
        for(auto j:v[t]){
            if(j==fa||book2[j])continue;
            for(int i=dfn[j];i<dfn[j]+sz[j];i++){
                int p=adfn[i];
                if(book2[p])continue;
                mp[sum[p]]--;
                book2[p]=1;
            }
        }
        return;
    }
    if(!book[t]){
        mp[sum[t]]--;
        for(auto j:v[t]){
            if(j==fa||book2[j])continue;
            for(int i=dfn[j];i<dfn[j]+sz[j];i++){
                int p=adfn[i];
                if(book2[p])continue;
                mp[sum[p]]--;
            }
        }
    }
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
    for(int i=1;i<=n;i++)book[son[i]]=1;
    dfs2(1,1);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}