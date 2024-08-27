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

vector<vector<int>> g(N),dag(N);
vector<int> a(N),dfn(N),low(N),scc(N);
vector<int> w(N),siz(N),out(N);
int tim = 0,tot = 0;
// stack<int> sta;
vector<int> sta;
vector<int> insta(N);
void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    sta.push_back(u);insta[u] = 1;
    for(auto v:g[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!scc[v]){
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == dfn[u]) {
        ++tot;
        while(!sta.empty()) {
            int t = sta.back();sta.pop_back();
            scc[t] = tot;
            insta[t] = 0;
            if(t == u) break;
        }
    }
}


void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }



    for (int i = 1; i <= n; i++) {
        siz[scc[i]]++;
        w[scc[i]] += a[i];
        for (auto v:g[i]) {
            if (scc[i] != scc[v]) {
                dag[scc[i]].push_back(scc[v]);
                out[scc[i]]++;
            }
        }
    }

    int f=0;
    int ans=0;
    for(int i=1;i<=tot;i++){
        if(!out[i]){
            if(f){
                cout<<0<<endl;
                return;
            }
            f=1;
            ans+=siz[i];
        }
    }
    cout<<ans<<endl;



}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}