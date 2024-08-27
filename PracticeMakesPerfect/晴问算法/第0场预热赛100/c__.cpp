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
    vector<vector<int>>dp(n+1,vector<int>(2,1));
    dp[1][0]=dp[1][1]=1;
    int ans=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(__gcd(a[i],a[j])==1){
                dp[i][1]=max(dp[i][1],dp[j][0]+1);
            }else{
                dp[i][0]=max(dp[i][0],dp[j][1]+1);
            }
        }
        ans=max({ans,dp[i][0],dp[i][1]});
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}