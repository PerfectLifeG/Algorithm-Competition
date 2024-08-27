// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <deque>
#include <random>
#include <cmath>
#include <algorithm>
#include <chrono>
using namespace std;
typedef pair<int,int>pii;
#define yes puts("YES")
#define no puts("NO")
#define x first
#define y second
#define int long long
#define ti chrono::system_clock::now().time_since_epoch().count()
mt19937 rnd(ti + size_t(new char));
using namespace std;
const int N=1e5+10;
int fac[N],inv[N];
const int mod=1e9+7;
int modpow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void getinv(int n)
{
    inv[1]=1; inv[0]=1;
    for(int i=2;i<n;i++)
    inv[i]=(1LL*(mod-mod/i)*inv[mod%i])%mod;    
}
void init()
{
    int n=N-1;
    fac[0]=1; inv[0]=1;
    for(int i=1;i<=n;i++)
    fac[i]=(1LL*fac[i-1]*i)%mod;
    inv[n]=modpow(fac[n],mod-2);
    for(int i=n-1;i>=1;i--)
    inv[i]=(1LL*inv[i+1]*(i+1))%mod;
}
int C(int n,int m)
{
    if(n<m||n<0)return 0;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int qk(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
void solve()
{
    int i,j,k;
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%lld",&n);
        int a[n];
        int mp[n+1]={0};
        unordered_map<int,int>res;
        for(i=0;i<n;i++)scanf("%lld",&a[i]),res[a[i]]++;
        for(auto u:res)
        {
            for(j=u.x;j<=n;j+=u.x)
            {
                mp[j]+=u.y;
            }
        }
        int mx=0;
        for(i=1;i<=n;i++)if(mx<mp[i])mx=mp[i];
        printf("%lld\n",mx);
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}