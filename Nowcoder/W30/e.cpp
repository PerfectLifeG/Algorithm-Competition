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
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int dp[n+1][2]={};
    int ans=1;
    function<void(int,int)> dfs=[&](int t,int fa){
        // cout<<t<<' '<<fa<<endl;
        int flag=1;
        int hong=1;
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
            hong=hong*dp[j][1]%mod;
            flag=flag*(dp[j][1]+dp[j][0])%mod;
        }
        dp[t][0]=hong;
        dp[t][1]=flag;
    };
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1])%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}