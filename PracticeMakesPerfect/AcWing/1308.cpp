#include<bits/stdc++.h>
using namespace std;
#define int __int128
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=1000000000000000003;
const int INF=0x3f3f3f3f;
void scan(__int128 &x)//输入
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}
void _print(__int128 x)
{
    if(x > 9) _print(x/10);
    putchar(x%10 + '0');
}
void print(__int128 x)//输出
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    _print(x);
}
int qsm(int a,int n,int m){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%m;
        a=a*a%m;
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
        ifac[N - 5] = qsm(fac[N - 5], mod - 2,mod);
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
    int k,x;
    scan(k),scan(x);
    int n=qsm(x%mod,x,1000);
    print(C(n-1,k-1));
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}