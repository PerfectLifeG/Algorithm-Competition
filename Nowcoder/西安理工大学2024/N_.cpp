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
    function<void(int,int,int)> dfs2=[&](int t,int fa,int x){
        // cout<<t<<' '<<fa<<' '<<x<<endl;
        vector<int>pre(v[t].size());
        vector<int>suf(v[t].size()+1,1);
        for(int i=0;i<v[t].size();i++){
            int j=v[t][i];
            if(j==fa){
                if(i==0) pre[i]=1+x;
                else pre[i]=pre[i-1]*(1+x);
            }else{
                if(i==0) pre[i]=1+dp[j];
                else pre[i]=pre[i-1]*(1+dp[j]);
            }
            pre[i]%=mod;
        }
        for(int i=v[t].size()-1;i>=0;i--){
            int j=v[t][i];
            if(j==fa){
                if(i==0) suf[i]=1+x;
                else suf[i]=suf[i+1]*(1+x);
            }else{
                if(i==0) suf[i]=1+dp[j];
                else suf[i]=suf[i+1]*(1+dp[j]);
            }
            suf[i]%=mod;
        }
        // cout<<t<<' '<<pre[0]<<' '<<suf[0]<<endl;

        for(int i=0;i<v[t].size();i++){
            int j=v[t][i];
            if(j==fa)continue;
            if(i==0)ans[j]=suf[i+1]+1;
            else ans[j]=pre[i-1]*suf[i+1]%mod+1;
            ans[j]*=dp[j];ans[j]%=mod;
            if(i==0) dfs2(j,t,suf[i+1]%mod);
            else dfs2(j,t,pre[i-1]*suf[i+1]%mod);
        }
    };
    dfs(1,-1);
    ans[1]=dp[1];
    dfs2(1,1,1);
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