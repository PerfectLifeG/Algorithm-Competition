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
const int N=100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,k;
vector<vector<int>> g(N);
int siz[N],dep[N],top[N],dfn[N],rnk[N],hson[N],fa[N];
int idx = 0;

void dfs1(int u) {
    siz[u] = 1;
    for(auto v:g[u]) {
        if(v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
        if(siz[v] > siz[hson[u]])
            hson[u] = v;
    }
}

void dfs2(int u,int c) {
    dfn[u] = ++idx;
    rnk[idx] = u;
    top[u] = c;
    if(hson[u]) dfs2(hson[u],c);
    for(auto v:g[u]) {
        if(v == fa[u] || v == hson[u]) continue;
        dfs2(v,v);
    }
}

int lca(int x,int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] > dep[top[y]]) 
            x = fa[top[x]];
        else 
            y = fa[top[y]];
    }
    return dep[x] > dep[y]?y:x;
}

vector<int> a(N);

int ans;
int cnt;
vector<vector<int>> v;

int calc(){
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res+=(a[i]^a[j])*dep[lca(i,j)];
            // cout<<a[i]<<' '<<a[j]<<' '<<i<<' '<<j<<' '<<lca(i,j)<<' '<<dep[lca(i,j)]<<endl;
        }
    }
    return res;
}


void dfs(int u){
    if(u==n+1){
        int res=calc();
        if(res>ans){
            ans=res;
            cnt=1;
            v.clear();
            v.push_back(a);
        }else if(res==ans){
            cnt++;
            v.push_back(a);
        }
        return;
    }
    for(int i=0;i<(1<<k);i++){
        a[u]=i;
        dfs(u+1);
    }
}

void solve(){
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        int f;cin>>f;
        g[f].push_back(i);
        g[i].push_back(f);
    }

    fa[1]=1;dep[1]=1;dfs1(1);
    dfs2(1,1);

    dfs(1);


    cout<<v.size()<<' '<<ans<<endl;
    // for(auto tmp:v){
    //     for(int i=1;i<=n;i++)cout<<tmp[i]<<' ';cout<<endl;
    //     for(int i=1;i<=n;i++){
    //         if(g[i].size()==1)continue;
    //         int res=tmp[i];
    //         for(auto j:g[i]){
    //             if(j==fa[j])continue;
    //             res=tmp[j];
    //         }
    //         cout<<i<<' '<<res<<endl;
    //     }
    // }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}