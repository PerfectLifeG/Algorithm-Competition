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
void solve(){
    int n;cin>>n;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int root,t0;cin>>root>>t0;

    vector<int>depth(n+1);
    vector<vector<int>>f(n+1,vector<int>(30));
    function<void(int,int)> dfs=[&](int t,int fa){
        depth[t]=depth[fa]+1;
        f[t][0]=fa;
        for(int i=1;(1<<i)<=depth[t];i++){
            f[t][i]=f[f[t][i-1]][i-1];
        }
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
        }
    };
    auto lca=[&](int x,int y){
        if(depth[x]<depth[y])swap(x,y);
        while(depth[x]>depth[y])x=f[x][log2(depth[x]-depth[y])];
        if(x==y)return x;
        for(int j=log2(depth[x]);j>=0;j--){
            if(f[x][j]!=f[y][j]){
                x=f[x][j];
                y=f[y][j];
            }
        }
        return f[x][0];
    };
    auto dist=[&](int a,int b){
        return depth[a]+depth[b]-2*depth[lca(a,b)]+1;
    };
    dfs(root,0);

    vector<array<int,3>> diam(n+1);
    diam[1]={1,root,root};//d u v
    queue<PII>q;
    q.push({root,1});
    while(q.size()){
        auto [t,dep]=q.front();
        q.pop();
        auto [d,u,vv]=max(diam[dep-1],diam[dep]);
        int ut=dist(u,t),vt=dist(vv,t);
        if(ut>d){
            diam[dep]=max(diam[dep],{ut,u,t});
        }
        if(vt>d){
            diam[dep]=max(diam[dep],{vt,vv,t});
        }
        diam[dep]=max(diam[dep],diam[dep-1]);
        for(auto j:v[t]){
            if(j==f[t][0])continue;
            q.push({j,dep+1});
        }
    }

    for(int i=1;i<=n;i++)diam[i][0]=max(diam[i][0],diam[i-1][0]);
    int j=n+t0;
    for(int i=1;i<=n;i++){
        while((diam[min(n,j)][0])/2<=(j-t0-1)*i)j--;
        cout<<j<<' ';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}