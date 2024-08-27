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
    vector<int>dp(k+1,INF);dp[0]=0;
    for(int i=1;i<=n;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        for(int j=k;j>=1;j--){
            if(j-1>=0)dp[j]=min(dp[j],dp[j-1]+a);
            if(j-2>=0)dp[j]=min(dp[j],dp[j-2]+b);
            if(j-3>=0)dp[j]=min(dp[j],dp[j-3]+c);
            if(j-4>=0)dp[j]=min(dp[j],dp[j-4]+d);
        }
    }
    cout<<dp[k]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}