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
    vector<int>dp(n+1);
    unordered_map<int,int>mp;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(mp.count(a[i-1]))dp[i]=dp[mp[a[i]-1]]+1;
        else dp[i]=1;
        mp[a[i]]=i;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}