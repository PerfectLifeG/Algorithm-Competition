#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Edge{
    int a;
    int b;
    int c;
    bool operator<(const Edge &n)const
    {
        return c<n.c;
    }
};
int root[N],siz[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra==rb)return;
    root[ra]=rb;
    // cout<<a<<' '<<b<<' '<<ra<<' '<<rb<<' ';
    siz[rb]+=siz[ra];
    // cout<<siz[rb]<<endl;
}
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
void solve()
{
    int n,k;cin>>n>>k;
    Edge edge[n-1];
    for(int i=1;i<=n;i++)siz[i]=1;
    for(int i=1;i<=n;i++)root[i]=i;
    for(int i=0;i<n-1;i++){
        cin>>edge[i].a>>edge[i].b>>edge[i].c;
    }
    int ans=1;
    sort(edge,edge+n-1);
    for(auto [u,v,w]:edge){
        u=find(u),v=find(v);
        if(u==v){
            continue;
        }
        // cout<<u<<' '<<v<<' '<<w<<' '<<siz[u]<<' '<<siz[v]<<'.'<<endl;
        // cout<<k-w+1<<' '<<siz[u]*siz[v]-1<<endl;
        ans=ans*ksm(k-w+1,siz[u]*siz[v]-1)%mod;
        merge(u,v);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}