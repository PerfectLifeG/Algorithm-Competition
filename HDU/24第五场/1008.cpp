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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

struct Dinic {
    struct Edge {int to,cap,rev;};
    int V;
    vector<vector<Edge>> G;
    vector<int> iter,level;
    Dinic(int n) {
        G.resize(n);
        iter.resize(n);
        level.resize(n);
    }

    void add_edge(int u,int v,int cap) {
        G[u].push_back({v,cap,(int)G[v].size()});
        G[v].push_back({u,0,(int)G[u].size() - 1});
    }

    void bfs(int s) {
        for (auto &x:level) x = -1;
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (auto [v,cap,rev]:G[u]) {
                if (cap > 0 && level[v] < 0) {
                    level[v] = level[u] + 1;
                    que.push(v);
                }
            }
        }
    }

    int dfs(int u,int t,int f) {
        if (u == t) return f;
        for (int &i = iter[u]; i < G[u].size(); i++) {
            Edge &e = G[u][i];
            if (e.cap > 0 && level[u] < level[e.to]) {
                int d = dfs(e.to,t,min(f,e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxflow(int s,int t) {
        int flow = 0;
        while (1) {
            bfs(s);
            if (level[t] < 0) return flow;
            for (auto &x:iter) x = 0;
            int f;
            while ((f = dfs(s,t,1e9)) > 0) flow += f;
        }
        return flow;
    }
};

void solve(){
    int n,k;cin>>n>>k;
    Dinic f(3*n+1+2);
    vector<int>book(n+1);
    for(int i=0;i<k;i++){
        int a;cin>>a;
        book[a]=1;
    }
    int tot=0;
    int s=3*n+1;
    int t=s+1;
    int idx=n;
    for(int i=0;i<n-1;i++){
        int u,v,w;cin>>u>>v>>w;
        if(book[u]&&book[v]){
            tot+=w;
            f.add_edge(s,++idx,w);
            f.add_edge(idx,u,INF);
            f.add_edge(idx,v,INF);
        }
    }
    for(int i=0;i<n-1;i++){
        int u,v,w;cin>>u>>v>>w;
        if(book[u]&&book[v]){
            tot+=w;
            f.add_edge(++idx,t,w);
            f.add_edge(u,idx,INF);
            f.add_edge(v,idx,INF);
        }
    }
    cout<<tot-f.maxflow(s,t)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}