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
    int dp[n+1][2]={};
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        dp[i][0]=max(abs(dp[i-1][0]+a),abs(dp[i-1][1]+a));
        dp[i][1]=min({dp[i-1][0]+a,dp[i-1][1]+a});
    }
    cout<<max(dp[n][1],dp[n][0])<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}