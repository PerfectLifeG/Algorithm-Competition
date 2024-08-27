#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=300005;
#define lowbit(x) (x&(-x))
int tr[N];
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
    return ksm(a,mod-2)%mod;
}

vector<int>v[N];
void add(int t,int val){
    for(int i=t;i<N;i+=lowbit(i)){
        tr[i]+=val;
    }
}
int query(int t){
    int res=0;
    for(int i=t;i;i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}
int val[N];
int val2[N];
int sz[N];
int fac[N];
int sum=1;
int n;
void dfs(int t,int fa,int depth){
    val[t]+=query(n)-query(t);
    int cnt=0;
    add(t,1);
    sz[t]=1;
    for(auto j:v[t]){
        if(j==fa)continue;
        dfs(j,t,depth+1);
        sz[t]+=sz[j];
        cnt++;
    }
    sum=sum*fac[cnt]%mod;
    val2[t]=n-depth-sz[t];
    add(t,-1);
}
signed main(){
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    int r;cin>>n>>r;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(r,r,0);
    int ans1=0;
    int ans2=0;
    for(int i=1;i<=n;i++){
        if(val[i]){ans1+=sum*val[i]%mod;ans1%=mod;}
        if(val2[i]){ans2+=sum*val2[i]%mod*inv(2)%mod;ans2%=mod;}
    }
    int ans=ans1+ans2*inv(2)%mod;ans%=mod;
    cout<<ans<<endl;
}