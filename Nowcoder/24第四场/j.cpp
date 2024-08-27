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
const int N=1e5+10;
const int mod=998244353;
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
int fac[N],ifac[N];
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--){
        ifac[i]=ifac[i+1]*(i+1)%mod;
    }
}
int C(int n,int m){
    if(m<0||n<m)return 0;
    return fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}

void solve(){
    init();
    int n,K;cin>>n>>K;
    string s;cin>>s;s=' '+s;
    int x=inv(2);int ans=0;
    int dp[n+1][K+1]={};
    for(int i=1;i<=n;i++){
        if(s[i]=='1'||s[i]=='?'){
            for(int j=0;j<=K;j++){
                for(int k=0;k<=j;k++){
                    dp[i][j]+=C(j,k)*dp[i-1][k]%mod;dp[i][j]%=mod;
                }
                dp[i][j]++;dp[i][j]%=mod;
                if(s[i]=='?'){
                    dp[i][j]=dp[i][j]*x%mod;dp[i][j]%=mod;
                }
            }
        }
        ans+=dp[i][K];ans%=mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}