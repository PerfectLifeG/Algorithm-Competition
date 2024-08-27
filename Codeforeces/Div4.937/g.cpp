#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<string,string> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    int g[n][n]={};
    vector<PII>v;
    for(int i=0;i<n;i++){string a,b;cin>>a>>b;v.push_back({a,b});}
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i].x==v[j].x||v[i].y==v[j].y)g[i][j]=1,g[j][i]=1;
        }
    }
    int dp[n][1<<n]={};
    for(int i=0;i<n;i++)for(int j=0;j<1<<n;j++)if(j>>i&1)dp[i][j]=1;
    int ans=1;
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i>>j&1){
                for(int k=0;k<n;k++){
                    if(!g[k][j]||(i>>k&1)==0)continue;
                    dp[j][i]=max(dp[k][(1<<j)^i]+1,dp[j][i]);
                    ans=max(ans,dp[j][i]);
                }
            }
        }
    }
    cout<<n-ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}