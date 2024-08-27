#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=1e9+7;
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
int inv(int a){
    return ksm(a,mod-2);
}
int h[N],e[2*N],ne[2*N],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int son[N];
int ans;int n,k;
void dfs(int t,int fa){
    son[t]=1;
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        dfs(j,t);
        son[t]+=son[j];
    }
    ans=(ans+(n-son[t])*(son[t]))%mod;
}
void solve()
{
    cin>>n>>k;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    if(k==1||k==3){cout<<1<<endl;return;}
    dfs(1,0);
    cout<<(ans+n*(n-1)/2)%mod*inv(n*(n-1)/2%mod)%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}