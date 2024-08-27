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
    int n,m;cin>>n>>m;
    vector<int>dp(30);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        for(int j=26;j>=0;j--){
            if((m>>j)&1){
                if(b<(1ll<<j))dp[j]+=a;
                else if(((b>>j)|((m>>j)-1))==(m>>j)-1)dp[j]+=a;
            }
        }
        if((b|m)==m)dp[27]+=a;
    }
    int ans=0;
    for(int i=0;i<=27;i++){
        ans=max(ans,dp[i]);
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