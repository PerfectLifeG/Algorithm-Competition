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
    string s;cin>>s;
    int ans=0;
    int n=s.size();
    vector<int>dp(n+1);
    dp[0]=1;dp[1]=2;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=2;j++)for(int k=1;k<=2;k++)for(int t=1;t<=2;t++)if(i+j+k+t<=n){
            string ss="";ss+=s[i];ss+=s[i+j];ss+=s[i+j+k];ss+=s[i+j+k+t];
            if(ss=="mygo"){
                ans+=(dp[i]*dp[n-(i+j+k+t)-1]%mod)%mod;
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}