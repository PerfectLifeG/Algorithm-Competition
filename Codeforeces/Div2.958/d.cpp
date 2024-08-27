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
    vector<int>val(n+1);
    vector<int>v[n+1];
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int dp[n+1][51]={};
    function<void(int,int)> dfs=[&](int t,int fa){
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
            int mn1=1e18,f=0;
            int mn2=1e18;
            for(int i=1;i<=50;i++){
                if(dp[j][i]<mn1){
                    mn2=min(mn2,mn1);
                    mn1=dp[j][i];
                    f=i;
                }else{
                    mn2=min(mn2,dp[j][i]);
                }
            }
            for(int i=1;i<=50;i++){
                if(i==f)dp[t][i]+=mn2;
                else dp[t][i]+=mn1;
            }
        }
        for(int i=1;i<=50;i++){
            dp[t][i]+=i*val[t];
        }
    };

    dfs(1,1);
    int ans=1e18;
    for(int i=1;i<=50;i++)ans=min(ans,dp[1][i]);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}