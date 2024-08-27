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
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int inv(int a){
    return ksm(a,mod-2);
}
void solve(){
    string s;cin>>s;
    int n=s.size();s=' '+s;
    int dp[n+1]={};
    int L[n+1]={};
    int LL[n+1]={};
    int ans=0;
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1]){
            if(s[L[i-1]-1]!=s[i])L[i]=max(0ll,L[i-1]-1);
            else L[i]=LL[max(0ll,L[i-1]-1)];
        }else L[i]=i-1;
        if(s[L[i]-1]!=s[i])LL[i]=max(0ll,L[i]-1);
        else  LL[i]=LL[max(0ll,L[i]-1)];
        if(L[i]>=1)dp[i]=dp[L[i]-1]*inv(n-L[i]+2)%mod*(n-i+1)%mod+(L[i])*(n-i+1)%mod;
        ans+=dp[i];ans%=mod;dp[i]%=mod;
        // cout<<i<<' '<<L[i]<<' '<<dp[L[i]-1]<<' '<<dp[L[i]-1]*inv(n-L[i]+2)%mod<<' '<<dp[i]<<endl;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}