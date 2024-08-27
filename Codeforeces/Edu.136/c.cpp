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
const int N=200;
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
int C(int a,int b){
    return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
int a[N];//先手获胜
int b[N];//后手获胜
void solve(){
    int n;cin>>n;
    cout<<a[n/2]%mod<<' '<<b[n/2]%mod<<' '<<1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    a[1]=1;b[1]=0;
    for(int i=2;i<=30;i++){
        int n=i*2;
        a[i]=C(n-1,i-1)+b[i-1];a[i]=(a[i]%mod+mod)%mod;
        b[i]=C(n,i)-a[i]-1;b[i]=(b[i]%mod+mod)%mod;
    }

    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}