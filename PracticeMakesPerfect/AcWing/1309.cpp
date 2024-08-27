#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=1e5+3;
const int mod=100003;
const int INF=0x3f3f3f3f;
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
namespace binom {
    int fac[N], ifac[N];
    int __ = []
    {
        fac[0] = 1;
        for (int i = 1; i <= N - 5; i++)
            fac[i] = fac[i - 1] * i % mod;
        ifac[N - 5] = ksm(fac[N - 5], mod - 2);
        for (int i = N - 5; i; i--)
            ifac[i - 1] = ifac[i] * i % mod;
        return 0;
    }();
    inline int C(int n, int m)
    {
        if (n < m || m < 0)return 0;
        return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
    }
    inline int A(int n, int m)
    {
        if (n < m || m < 0)return 0;
        return fac[n] * ifac[n - m] % mod;
    }
}
using namespace binom;
void solve()
{
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    int ans=0;
    for(int i=0;i<=k;i++){
        ans=(ans+C(b,i)%mod*A(a,i)%mod*C(d,k-i)%mod*A(a+c-i,k-i)%mod)%mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}