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
    string s;cin>>s;s=' '+s;
    int n=s.size()-1;
    int dp[n+1][2][4]={};
    int dp2[n+1][2][4]={};
    for(int i=1;i<=n;i++){
        if(s[i]=='m')dp[i][0][0]=1;
        if(s[i]=='y')dp[i][0][1]+=dp[i-1][0][0]+dp[i-1][1][0];
        if(s[i]=='g')dp[i][0][2]+=dp[i-1][0][1]+dp[i-1][1][1];
        if(s[i]=='o')dp[i][0][3]+=dp[i-1][0][2]+dp[i-1][1][2];
        dp[i][0][3]+=dp[i-1][0][3]+dp[i-1][1][3];

        for(int j=0;j<4;j++){
            dp[i][1][j]+=dp[i-1][0][j];
        }

        cout<<i<<endl;
        for(int j=0;j<4;j++){
            cout<<dp[i][0][j]<<' ';
        }cout<<endl;
        for(int j=0;j<4;j++){
            cout<<dp[i][1][j]<<' ';
        }cout<<endl;
    }
    cout<<dp[n][1][3]+dp[n][0][3]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}