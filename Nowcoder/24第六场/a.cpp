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
    vector<PII>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    vector<double>mn_dp(n+1,1);
    vector<double>mx_dp(n+1);
    function<void(int,int,int,int,double)> dfs=[&](int t,int fa,int c0,int dep,double res){
        if(t!=1)res=max(res,c0*1.0/dep);
        if(t!=1&&v[t].size()==1){
            mx_dp[t]=mn_dp[t]=res;
            return;
        }
        for(auto [j,w]:v[t]){
            if(j==fa)continue;
            dfs(j,t,c0+(w==0),dep+1,res);
            mx_dp[t]=max(mx_dp[t],mn_dp[j]);
            mn_dp[t]=min(mn_dp[t],mx_dp[j]);
        }
    };
    dfs(1,1,0,0,0);

    cout<<fixed<<setprecision(12)<<1.0-mn_dp[1]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}