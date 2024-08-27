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
    int n;cin>>n;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int r,t0;cin>>r>>t0;

    int dp[n+1]={};
    function<int(int,int)> dfs=[&](int t,int fa)->int{
        dp[t]=1;
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
            dp[t]=max(dp[t],dp[j]+1);
        }
        return dp[t];
    };
    vector<int>res(n+1);
    function<void(int,int)> dfs2=[&](int t,int fa){
        vector<PII>tmp;
        tmp.push_back({0,0});
        for(auto w:v[t]){
            tmp.push_back({dp[w],w});
        }
        sort(tmp.begin(),tmp.end());
        res[t]=max({res[t],dp[t],tmp.back().first+1});
        int back=dp[t];
        for(auto j:v[t]){
            if(j==fa)continue;
            if(j==tmp.back().second){
                dp[t]=tmp[tmp.size()-2].first+1;
                res[t]=max(res[t],dp[t]);
            }else{
                dp[t]=tmp[tmp.size()-1].first+1;
                res[t]=max(res[t],dp[t]);
            }
            dfs2(j,t);
            dp[t]=back;
        }
    };

    int ans=INF;
    function<void(int,int,int)> dfs3=[&](int t,int fa,int depth){
        if(depth<=t0){
            ans=min(ans,res[t]);
            // cout<<t<<' '<<res[t]<<' '<<ans<<endl;
            // return;
        }
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs3(j,t,depth+1);
        }
    };

    dfs(r,r);
    // for(int i=1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
    dfs2(r,r);
    // for(int i=1;i<=n;i++)cout<<res[i]<<' ';cout<<endl;
    dfs3(r,r,0);
    cout<<ans+t0-1<<' ';
    for(int i=1;i<n;i++){
        cout<<t0+1<<' ';
    }


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}