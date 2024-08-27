#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+5;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b){
    x=1;y=0;
    return a;
    }
    ll g=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return g;
}
void solve(ll a,ll&b,ll c,ll&x,ll&y)
{
    ll g=__gcd(a,b),x0,y0;
    a/=g;b/=g;c/=g;
    exgcd(a,b,x0,y0);
    x0*=c;y0*=c;
    x=x0+b;//y=y0-a;
    x=(x%abs(b)+abs(b))%abs(b);y=(c-a*x)/b;
}
int main()
{
    ll a,b,c,k,g,ec,x,y,z,t,tb,tk,ttb;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
    g=__gcd(a,b);
    ec=k%g;
    tb=-g;
    solve(c,tb,ec,z,t);
    tb=abs(tb);
    do{
        tk=k-z*c;ttb=b;
        solve(a,ttb,tk,x,y);
        if(x>=0&&y>=0)
        {
            printf("%lld %lld %lld\n",x,y,z);
            break;
        }
        z+=tb;
    }while(1);
}