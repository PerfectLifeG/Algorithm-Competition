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
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];

    vector<int>L(n+1);
    vector<int>dp(n+1);
    for(int i=1;i<=n;i++){
        int x=upper_bound(pre.begin()+i,pre.end(),q+pre[i-1])-pre.begin();
        if(x!=n+1){
            L[x]=i;
            dp[x]+=dp[i-1];
            dp[x]++;
        }
    }
    // for(int i=1;i<=n;i++)cout<<i<<' '<<L[i]<<' '<<dp[i]<<endl;

    int ans=0;
    for(int i=1;i<=n;i++){
        // if(L[i])dp[i]+=dp[L[i]-1];
        ans+=dp[i];
    }
    cout<<n*(n+1)/2-ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}