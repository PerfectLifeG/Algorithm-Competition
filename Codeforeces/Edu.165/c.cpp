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
    vector<int>a(n+2);
    vector<int>v(n+1);
    v[1]=a[1];
    a[0]=INF;
    a[n+1]=INF;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int dp[n+1][k+1];
    for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)dp[i][j]=INF;
    dp[0][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=i&&j<=k;j++){
            dp[i][j]=min(dp[i-1][j]+a[i],dp[i][j]);
            // cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            int mn=a[i+1];
            for(int k=0;k<=j;k++){
                mn=min(mn,a[i-k]);
                dp[i][j]=min(dp[i-k][j-k]+mn*k,dp[i][j]);
                // cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            }
            // dp[i][j][0]=min({dp[i-1][j][0],dp[i-1][j][1],dp[i-1][j][2]})+a[i];
            // dp[i][j][2]=min({dp[i-1][j-1][0],dp[i-1][j-1][1]+v[i-1],dp[i-1][j-1][2]})+a[i+1];
            // dp[i][j][1]=min({dp[i-1][j-1][0]+a[i-1],dp[i-1][j-1][1]+v[i-1],dp[i-1][j-1][2]+a[i]});
            // if(dp[i-1][j-1][1]+v[i-1])v[i]=v[i-1];
        }
    }
    int ans=INF;
    for(int i=0;i<=k;i++){
        ans=min(ans,dp[n][i]);
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