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
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int dp[n+1][31]={};
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i&&j<=30;j++){
            dp[i][j]=dp[i-1][j]+(a[i]/(1ll<<j))-k;
            if(j)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]/(1ll<<j));
            if(j==30)dp[i][j]=max(dp[i][j],dp[i-1][j]);
            // cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<dp[i-1][j-1]<<' '<<a[i]/(1ll<<j)<<endl;
        }
    }
    int mx=0;
    for(int i=0;i<=n&&i<=30;i++){
        mx=max(mx,dp[n][i]);
    }
    cout<<mx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}