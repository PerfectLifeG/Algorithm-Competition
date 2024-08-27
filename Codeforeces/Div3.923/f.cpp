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
const int INF=0x3f3f3f3f;
int root[N];
int find(int a){
    if(a==root[a])return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra>rb)swap(ra,rb);
    root[ra]=rb;
}
void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++)root[i]=i;
    vector<array<int,3>> edge;
    vector<int>V[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edge.push_back({w,u,v});
    }
    sort(all(edge),greater());
    int id;
    for(int i=0;i<edge.size();i++){
        auto [w,u,v]=edge[i];
        if(find(u)==find(v)){
            id=i;
        }else{
            merge(u,v);
            V[u].push_back(v);
            V[v].push_back(u);
        }
    }
    int u=edge[id][1],v=edge[id][2];
    vector<int>ans;
    function<int(int,int)> dfs=[&](int t,int fa)->int{
        if(t==v){
            ans.push_back(t);
            return 1;
        }
        ans.push_back(t);
        for(auto j:V[t]){
            if(j==fa)continue;
            if(t==u&&j==v)continue;
            if(dfs(j,t))return 1;
        }
        ans.pop_back();
        return 0;
    };dfs(u,-1);

    cout<<edge[id][0]<<' '<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}