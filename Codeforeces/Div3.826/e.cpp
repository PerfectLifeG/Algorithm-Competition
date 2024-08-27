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
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool dp[n+1][2]={};
    dp[0][1]=1;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        if(i+a[i]<=n&&(dp[i-1][1]||dp[i-1][0]))dp[i+a[i]][1]=1;
        if(i-a[i]>=1&&(dp[i-a[i]-1][0]||dp[i-a[i]-1][1]))dp[i][0]=1;
    }
    if(dp[n][0]||dp[n][1])yes;
    else no;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}