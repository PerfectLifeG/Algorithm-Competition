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
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int dp[2][N][2];
void solve(){
    int n;cin>>n;
    string s[2];cin>>s[0]>>s[1];
    s[0]=' '+s[0];
    s[1]=' '+s[1];

    //0从左边转移而来
    //1从上下转移而来
    int ans=0;
    for(int i=1;i<=n;i++){
        if(s[0][i]=='R'){
            dp[0][i][0]=max(dp[0][i-1][1],dp[0][i-1][0])+1;
        }
        if(s[1][i]=='R'){
            dp[1][i][0]=max(dp[1][i-1][1],dp[1][i-1][0])+1;
        }
        if(s[0][i]=='R'){
            dp[0][i][1]=dp[1][i][0]+1;
        }
        if(s[1][i]=='R'){
            dp[1][i][1]=dp[0][i][0]+1;
        }
        ans=max({ans,dp[0][i][0],dp[1][i][0],dp[0][i][1],dp[1][i][1]});
    }
    if(ans)ans--;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}