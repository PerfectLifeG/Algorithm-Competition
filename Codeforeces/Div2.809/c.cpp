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
    vector<int>h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    if(n&1){
        int ans=0;
        for(int i=2;i<=n-1;i+=2){
            ans+=max(0ll,max(h[i-1],h[i+1])-h[i]+1);
        }
        cout<<ans<<endl;
        return;
    }
    vector<int>dp(n+3);
    for(int i=n-1;i>=2;i--){
        dp[i]=dp[i+2]+max(0ll,max(h[i-1],h[i+1])-h[i]+1);
    }
    // for(int i=1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
    int ans=INF;
    int pre=0;
    for(int i=1;i<n-1;i++){
        if(i&1){
            ans=min(ans,pre+dp[i+1]);
            ans=min(ans,pre+dp[i+2]);
        }
        if(i%2==0)pre+=max(0ll,max(h[i-1],h[i+1])-h[i]+1);
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