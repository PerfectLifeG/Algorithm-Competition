#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<int>dp(n+1);
    int mx=-1e18;
    int r;
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i-1]+v[i],v[i]);
        if(dp[i]>mx){
            mx=dp[i];
            r=i;
        }
    }
    int l;int t=0;
    for(int i=r;i>=1;i--){
        t+=v[i];
        if(t==mx){
            l=i;
            break;
        }
    }
    if(mx<0)cout<<0<<' '<<v[1]<<' '<<v[n]<<endl;
    else cout<<mx<<' '<<v[l]<<' '<<v[r]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}