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
vector<int>divs[N];
void divisor(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            divs[j].push_back(i);
        }
    }
}
void solve(){
    divisor();
    int n;cin>>n;
    vector<int>v[N];
    for(int i=0;i<n;i++){
        int a;cin>>a;
        for(auto j:divs[a]){
            v[j].push_back(i);
        }
    }
    vector<int>dp(N);
    for(int i=1;i<N;i++){
        int len=1;
        for(int j=0;j<v[i].size();j++){
            if(j&&v[i][j]!=v[i][j-1]+1)len=1;
            dp[i]+=len*(len+1)/2;dp[i]%=mod;
            len++;
        }
    }
    int ans=0;
    for(int i=N-1;i>=1;i--){
        for(int j=i+i;j<N;j+=i){
            dp[i]=(dp[i]-dp[j]+mod)%mod;
        }
        ans+=dp[i]*i%mod;ans%=mod;
    }
    int t=n*(n+1)/2%mod;
    cout<<ans*inv(t)%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}