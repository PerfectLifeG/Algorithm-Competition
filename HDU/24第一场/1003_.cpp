#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=5e5+10;
const int M=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

int tr1[M+1],tr2[M+1],tr3[M+1];//前缀和，平方和，数量
void add(int u,int val,int tr[]){
    for(int i=u;i<M;i+=lowbit(i)){
        tr[i]+=val;
    }
}
int query(int u,int tr[]){
    int res=0;
    for(int i=u;i;i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}


int idx,sz[N],son[N],L[N],R[N],rnk[N];
vector<vector<int>> g(N);
void dfs1(int u,int fa){
    sz[u]=1;
    L[u]=++idx; rnk[idx]=u;
    for(auto v:g[u]){
        if(v==fa)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }
    R[u]=idx;
}

int a[N],ans[N];
void dfs2(int u,int fa,int flag){
    for(auto v:g[u]){
        if(v==fa||v==son[u])continue;
        dfs2(v,u,0);
    }
    if(son[u])dfs2(son[u],u,1);
    for(auto v:g[u]){
        if(v==fa||v==son[u])continue;
        for(int i=L[v];i<=R[v];i++){
            int j=rnk[i];
            ans[u]+=query(a[j]-1,tr3)*a[j]*a[j]-a[j]*query(a[j]-1,tr1)+query(M,tr2)-query(a[j],tr2)-a[j]*(query(M,tr1)-query(a[j],tr1));
            add(a[j],a[j],tr1);
            add(a[j],a[j]*a[j],tr2);
            add(a[j],1,tr3);
        }
    }
    ans[u]+=query(a[u]-1,tr3)*a[u]*a[u]-a[u]*query(a[u]-1,tr1)+query(M,tr2)-query(a[u],tr2)-a[u]*(query(M,tr1)-query(a[u],tr1));
    ans[u]*=2;
    ans[u]+=ans[son[u]];
    add(a[u],a[u],tr1);
    add(a[u],a[u]*a[u],tr2);
    add(a[u],1,tr3);
    if(!flag){
        for(int i=L[u];i<=R[u];++i){
            int j=rnk[i];
            add(a[j],-a[j],tr1);
            add(a[j],-a[j]*a[j],tr2);
            add(a[j],-1,tr3);
        }
    }
}

void solve(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs1(1,1);
    dfs2(1,1,0);

    int res=0;
    for(int i=1;i<=n;i++){
        res^=ans[i];
    }
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}