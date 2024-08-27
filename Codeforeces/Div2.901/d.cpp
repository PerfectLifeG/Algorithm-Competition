#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
    }
    vector<int>nx(n+1);
    vector<int>cnt(n+1);
    for(auto &[x,y]:mp){
        if(x<=n){
            nx[x]=x;
            cnt[x]=y;
        }
    }
    for(int i=0;i<=n;){
        int j=i+1;
        nx[i]=j;
        while(j<=n&&cnt[j]){
            j++;
        }
        if(j==i+1)break;
        for(;i<j;i++){
            nx[i]=j;
            // cout<<i<<' '<<=nx[i]<<endl;
        }
    }
    int f[n+1][n+1]={};
    for(int i=0;i<=n;i++){
        if(!cnt[i])break;
        for(int j=i+1;j<=n;j++){
            if(nx[i]>=j)f[i][j]=(cnt[i]-1)*j+i;
            else f[i][j]=(cnt[i]-1)*nx[i]+i;
            // cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
        }
    }
    vector<int>dp(n+1,1e18);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(!cnt[i])break;
        for(int j=0;j<i;j++){
            dp[i]=min(dp[j]+f[j][i],dp[i]);
        }
        // cout<<i<<' '<<dp[i]<<endl;
    }
    int ans=1e18;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[i]+f[i][n]);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}