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
const int INF=0x3f3f3f3f;
void solve(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int>dp[n+1][2];
    vector<int>l[n+1];
    for(int i=0;i<n;i++){
        dp[i][0]=dp[i-1][0]+v[i];
        dp[i][1]=max(dp[i-1][1],dp[i][0]-v[i]+v[i+1]);
    }
    cout<<dp[n][k]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}