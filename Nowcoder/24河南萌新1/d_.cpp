#include<bits/stdc++.h>
#define isalive !=0
#define ll long long
#define mod 998244353
using namespace std;
ll l,r,ans,dp[61][61],num[2];
int part[61],len,t;
ll dfs(int need,int pos,int tot,bool limit,bool zero)
{
    if(!pos) return tot;
    if(!limit&&!zero&&dp[pos][tot]!=-1)
        return dp[pos][tot];
    int maxn=limit?part[pos]:1;
    ll sum=0;
    for(int i=0;i<=maxn;++i)
    {
        if(zero&&!i)
        sum+=dfs(need,pos-1,tot,limit&&(i==maxn),1);
        else
        sum+=dfs(need,pos-1,tot+(i==need),limit&&(i==maxn),0);
    }
    if(!limit&&!zero)
        dp[pos][tot]=sum;
    return sum;
}
void dismember(ll victim) 
{ 
    len=0;
    while(victim!=0) part[++len]=victim%2,victim/=2;
    memset(dp,-1,sizeof(dp));
    num[1]=(num[1]-dfs(1,len,0,1,1)+mod)%mod;
} 
void Dismember(ll victim) 
{ 
    len=0;
    while(victim!=0) part[++len]=victim%2,victim/=2;
    memset(dp,-1,sizeof(dp));
    num[1]=dfs(1,len,0,1,1)%mod;
} 
int main() 
{ 
    scanf("%lld",&t);
    while(t--) 
    {    
        ans=0;
        scanf("%lld%lld",&l,&r);
        Dismember(r); dismember(l-1); 
        ans=((ans+num[1]+mod)%mod+mod)%mod;
        printf("%lld\n",ans%mod);
    } 
    return 0;
} 