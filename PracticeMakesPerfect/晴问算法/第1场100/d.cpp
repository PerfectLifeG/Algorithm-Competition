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
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    char g[n+1][m+1]={};
    for(int i=1;i<=n;i++){
        string s;cin>>s;s=' '+s;
        for(int j=1;j<=m;j++){
            g[i][j]=s[j];
        }
    }
    int dp[n+1][m+1][3]={};
    if(g[1][1]=='.')dp[1][1][0]=1;
    if(g[1][1]=='#')dp[1][1][1]=1;
    if(g[1][1]=='*')dp[1][1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)continue;
            if(g[i][j]=='.'){
                dp[i][j][0]=dp[i-1][j][0]+dp[i][j-1][0];dp[i][j][0]%=mod;
                dp[i][j][1]=dp[i-1][j][1]+dp[i][j-1][1];dp[i][j][1]%=mod;
                dp[i][j][2]=dp[i-1][j][2]+dp[i][j-1][2];dp[i][j][2]%=mod;
            }
            else if(g[i][j]=='#'){
                dp[i][j][1]=dp[i-1][j][0]+dp[i][j-1][0];dp[i][j][1]%=mod;
                dp[i][j][2]=dp[i-1][j][1]+dp[i][j-1][1];dp[i][j][2]%=mod;
            }
        }
    }
    cout<<dp[n][m][2]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}