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
    int m,n,k;cin>>n>>m>>k;
    vector<int>v;
    vector<int>w;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        int t=n-1;
        if(n%a==0){
            t=n/a-1;
        }
        int cnt=1;
        while(t>cnt){
            v.push_back(cnt*a);
            w.push_back(cnt*b);
            t-=cnt;
            cnt*=2;
        }
        if(t>0){
            v.push_back(t*a);
            w.push_back(t*b);
        }
    }
    vector<int>dp(n+1,1e18);
    dp[0]=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<=n;j++){
            dp[j]=min(dp[j],dp[((j-v[i])%n+n)%n]+w[i]);
        }
    }
    if(dp[n-k]==1e18)cout<<-1<<endl;
    else cout<<dp[n-k]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}