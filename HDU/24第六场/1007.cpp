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

int ksm(int a,int n){
    int r=1;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int inv(int a){
    return ksm(a,mod-2);
}

void solve(){
    int n;cin>>n;
    vector<vector<int>>g(n);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[a[u]].push_back(a[v]);
        g[a[v]].push_back(a[u]);
    }

    vector<int>dp(n);
    vector<int>fa(n);
    function<void(int,int)> dfs=[&](int u,int ff){
        fa[u]=ff;
        dp[u]=1;
        for(auto v:g[u]){
            if(v==ff)continue;
            dfs(v,u);
            dp[u]*=(dp[v]+1);
            dp[u]%=mod;
        }
    };
    dfs(0,0);
    // for(int i=0;i<n;i++)cout<<dp[i]<<' ';cout<<endl;

    vector<int>mex(n);
    int cnt=dp[0]+1;
    int ans=0;
    int now=0;
    for(int i=0;i<n;i++){
        if(mex[i])continue;
        int u=i;
        int lst=i;
        while(mex[u]==0){
            for(auto v:g[u]){
                if(v==fa[u]||v==lst)continue;
                cnt*=(dp[v]+1);cnt%=mod;
            }
            lst=u;
            mex[u]=1;
            u=fa[u];    
        }
        cnt*=inv(dp[lst]+1);cnt%=mod;

        int x=cnt;
        while(now<n&&mex[now])now++;
        if(now==n)break;

        u=fa[now];
        int pp=0;
        lst=now;
        while(mex[u]==0){
            int modify=1;
            for(auto v:g[u]){
                if(v==lst||v==fa[u])continue;
                modify*=dp[v]+1;modify%=mod;
            }
            modify*=(pp+1);modify%=mod;
            // cout<<u<<' '<<modify<<endl;
            pp=modify;
            lst=u;
            u=fa[u];
        }
        cnt*=inv(dp[lst]+1);cnt%=mod;
        // cout<<now<<' '<<cnt<<' '<<modify<<endl;
        cnt*=(pp+1);cnt%=mod;
        // cout<<now<<' '<<cnt<<endl;

        ans+=now*cnt%mod;ans%=mod;
        cnt=x;
    }
    cout<<(ans+n)%mod<<endl;

}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}