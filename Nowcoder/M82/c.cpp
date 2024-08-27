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
int dp[N][4];
void solve(){
    dp[1][0]=25;dp[1][1]=1;dp[1][2]=0;
    dp[2][0]=26*25-1;dp[2][1]=26;dp[2][2]=1;
    for(int i=3;i<N;i++){
        dp[i][0]=((dp[i-1][0]+dp[i-1][2])%mod*25+dp[i-1][1]%mod*24)%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][2]=(dp[i-1][1])%mod;
        dp[i][3]=(dp[i-1][2]+dp[i-1][3]%mod*26)%mod;
    }
    int n;cin>>n;
    while(n--){
        int a;cin>>a;
        cout<<dp[a][3]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}