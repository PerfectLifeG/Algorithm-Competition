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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<PII>v(n+1);
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        pre[i]=pre[i-1]+a;
        v[i]={a,b};
    }

    vector<int>dp(n+1);
    unordered_map<int,int>mp;
    dp[1]=v[1].x;
    if(n>1&&dp[1]>v[2].x)mp[v[1].y]=1;
    for(int i=2;i<=n;i++){
        // if(v[i].y==v[i-1].y){
        //     dp[i]=dp[i-1]+v[i].x;
        // }else{
            // if(dp[i-1]>v[i].x)dp[i]=v[i].x;
            // else{
                // if(mp.count(v[i].y)){
                    // cout<<v[i].y<<' '<<mp[v[i].y]<<endl;
            dp[i]=max(v[i].x,dp[mp[v[i].y]]+v[i].x-(pre[i-1]-pre[mp[v[i].y]]));
                    // mp.erase(v[i].y);
                // }else dp[i]=v[i].x;
            // }
            // if(i!=n&&dp[i]>v[i+1].x)mp[v[i].y]=i;
            if(i!=n)mp[v[i].y]=i;
        // }
        // cout<<i<<' '<<dp[i]<<endl;
    }

    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,dp[i]);
        cout<<mx<<' ';
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}