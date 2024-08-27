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
    vector<int>v(n+2);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<int>mnr(n+1);
    vector<int>dp(n+2);
    for(int i=0;i<=n;i++){
        mnr[i]=1e18;
    }
    int m;cin>>m;
    while(m--){
        int l,r;cin>>l>>r;
        mnr[l-1]=min(mnr[l-1],r);
    }
    for(int i=n;i>=1;i--){
        mnr[i-1]=min(mnr[i-1],mnr[i]);
        // cout<<i<<' '<<mnr[i]<<endl;
    }
    int q[n];
    int hh=0,tt=0;
    q[0]=0;
    for(int i=1;i<=n+1;i++){
        while(tt>=hh&&mnr[q[hh]]<i)hh++;
        dp[i]=dp[q[hh]]+v[i];
        // cout<<i<<' '<<q[hh]<<' '<<dp[q[hh]]+v[i]<<endl;
        while(tt>=hh&&dp[i]<=dp[q[tt]])tt--;
        q[++tt]=i;
    }
    cout<<dp[n+1]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}