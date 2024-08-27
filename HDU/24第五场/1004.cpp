#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
typedef pair<int,int> PII;
const int N=1e5+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

struct BIT {
    #define lowbit(x) (x&(-x))
    vector<int>tr;
    BIT(int size){
        tr.resize(size, 0);
    }
    void add(int t,int val){
        for(int i=t;i<tr.size();i+=lowbit(i)){
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
};

vector<vector<int>> g(N);
int siz[N],dep[N],top[N],L[N],R[N],rnk[N],hson[N],fa[N];
int cnt = 0;

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
    L[u]=++cnt;
    // dfn[u] = ++cnt;
    rnk[cnt] = u;
    top[u] = c;
    if(hson[u]) dfs2(hson[u],c);
    for(auto v:g[u]) {
        if(v == fa[u] || v == hson[u]) continue;
        dfs2(v,v);
    }
    R[u]=cnt;
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

vector<int>divs[N];
vector<PII>LCM[N];
void divisor(int n=N){
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j+=i){
            divs[j].push_back(i);
        }
    }
}

void solve(){
    int n;cin>>n;
    cnt=0;
    for(int i=0;i<=n;i++)g[i].clear(),hson[i]=0,fa[i]=0;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1);
    dfs2(1,1);

    int Q;cin>>Q;
    vector<array<int,3>>q;
    for(int i=0;i<Q;i++){
        int r,x;cin>>r>>x;
        q.push_back({x,r,i});
    }
    sort(all(q));

    BIT tr(n+1);
    vector<int>ans(Q);
    int l=1;
    for(int k=0;k<Q;k++){
        while(l<=q[k][0]){
            for(auto &[x,y]:LCM[l]){
                if(y<=n)tr.add(L[lca(x,y)],1+(x!=y));
            }
            l++;
        }   
        ans[q[k][2]]=tr.query(R[q[k][1]])-tr.query(L[q[k][1]]-1);
    }

    for(int i=0;i<Q;i++)cout<<ans[i]<<' ';cout<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    divisor();
    for(int i=1;i<N;i++){
        for(int l=i;l<N;l+=i){
            for(auto j:divs[l]){
                if(i<=j&&lcm(i,j)==l){
                    LCM[l].push_back({i,j});
                }
            }
        }
    }

    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}