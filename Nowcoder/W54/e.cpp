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
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];

    vector<int>dp(n+1,INF);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=a[i];j--){
            if(dp[j-a[i]]!=INF&&j>=i&&i>j-a[i])dp[j]=min(dp[j-a[i]]+1,dp[j]);
            // cout<<i<<' '<<j<<' '<<dp[j]<<endl;
        }
    }
    if(dp[n]==INF)cout<<-1<<endl;
    else cout<<dp[n]<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}