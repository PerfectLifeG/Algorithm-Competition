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
    int n,p;cin>>n>>p;
    vector<int>dp(n+1,INF);
    dp[0]=0;
    for(int i=1;i<=n+1;i++){
        int w,v;
        if(i==n+1)w=p,v=1;
        else cin>>w>>v;
        for(int j=1;j<=n-1;j++){
            dp[j]=min(dp[j],dp[max(j-v,0ll)]+w);
        }
    }
    cout<<dp[n-1]+p<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}