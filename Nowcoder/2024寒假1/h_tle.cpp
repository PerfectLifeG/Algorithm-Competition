#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<PII>v;
    unordered_map<int,int>mp;
    mp[0]=0;
    // int dp[30];
    int ans=0;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        unordered_map<int,int>t=mp;
        v.push_back({a,b});
        for(int j=0;j<30;j++){
            dp[j]=dp[j-1];
            if((1ll<<j)<=m)dp[j]+=a;
        }
        for(auto [i,j]:t){
            cout<<i<<' '<<j<<endl;
            if(b|i<=m)mp[b|i]+=a;
            ans=max(ans,mp[b|i]);
        }
    }
    cout<<ans<<endl;
    // sort(all(v),[&](PII a,PII b){
    //     return a.y<b.y;
    // });
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}