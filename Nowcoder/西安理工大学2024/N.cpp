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
int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n>>mod;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int dp[n+1]={};
    function<void(int,int)> dfs=[&](int t,int fa){
        dp[t]=1;
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
            dp[t]*=(dp[j]+1);dp[t]%=mod;
        }
    };
    vector<int>ans(n+1);
    function<void(int,int)> dfs2=[&](int t,int fa){
        if(t!=1)
        for(auto j:v[t]){
            if(j==fa)continue;
            ans[t]*=(1+dp[j]);ans[t]%=mod;
        }
        for(auto j:v[t]){
            if(j==fa)continue;
            ans[j]=ans[t]/(dp[j]+1)+1;ans[j]%=mod;
            dfs2(j,t);
        }
    };
    dfs(1,-1);
    ans[1]=dp[1];
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}