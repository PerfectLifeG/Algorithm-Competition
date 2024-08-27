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
    int n;cin>>n;
    if(n==1){
        cout<<2<<endl;
        return;
    }
    if(n==2){
        cout<<4<<endl;
        return;
    }
    int dp[n+1][8]={};//000 001 010 011 100 101 110 111
    for(int i=0;i<8;i++){
        if(i!=0&&i!=7)dp[3][i]=1;
    }
    for(int i=4;i<=n;i++){
        dp[i][1]+=dp[i-1][4];dp[i][1]%=mod;
        dp[i][2]+=dp[i-1][1]+dp[i-1][5];dp[i][2]%=mod;
        dp[i][3]+=dp[i-1][1]+dp[i-1][5];dp[i][3]%=mod;
        dp[i][4]+=dp[i-1][2]+dp[i-1][6];dp[i][4]%=mod;
        dp[i][5]+=dp[i-1][2]+dp[i-1][6];dp[i][5]%=mod;
        dp[i][6]+=dp[i-1][3];dp[i][6]%=mod;
    }
    int ans=0;
    for(int i=0;i<8;i++){
        ans+=dp[n][i];
        ans%=mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}