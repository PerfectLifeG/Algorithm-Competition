#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int root[N];
int v[N];
struct Edge{
    int a,b,c;
    bool operator<(const Edge &n)const
    {
        return c<n.c;
    }
}edge[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    root[find(a)]=find(b);
}
void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)root[i]=i;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=0;i<m;i++){
        cin>>edge[i].a>>edge[i].b;
        edge[i].c=max(v[edge[i].a],v[edge[i].b]);
    }
    sort(edge,edge+m);
    // for(int i=0;i<m;i++)cout<<edge[i].a<<' '<<edge[i].b<<' '<<edge[i].c<<endl;
    int q;cin>>q;
    vector<array<int,4>>qu(q);
    for(int i=0;i<q;i++){
        int a,b,e;cin>>a>>b>>e;
        qu[i]={e+v[a],a,b,i};
    }
    sort(qu.begin(),qu.end());
    vector<int>ans(q);
    int j=0;
    for(auto [w,u,v,i]:qu){
        // cout<<w<<' '<<u<<' '<<v<<' '<<i<<endl;
        while(j<m&&edge[j].c<=w){
            merge(edge[j].a,edge[j].b);
            j++;
        }
        // for(int i=1;i<=n;i++)cout<<root[i]<<' ';
        ans[i]=(find(u)==find(v));
        // cout<<i<<' '<<ans[i]<<endl;
    }
    for(int i=0;i<q;i++){
        if(ans[i]){
            yes;
        }else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}