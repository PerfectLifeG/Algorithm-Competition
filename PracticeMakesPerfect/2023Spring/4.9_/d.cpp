#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int h[N],e[N],ne[N],w[N],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
class cmp {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const 
    {
        if( a.first == b.first){
            a.second < b.second;
        }
        return a.first > b.first;
    }
};
int son[N];int sum[N];int fa[N];
typedef pair<int,int>PII;
set<PII,cmp>st[N];
int book[N];
int dfs(int t){
    if(book[t])return son[t];
    book[t]=1;
    if(h[t]==-1)return 1;
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(book[j])continue;
        auto s=dfs(j);
        son[t]+=s;
        st[t].insert({s,j});
    }
    return son[t];
}
int dfs2(int t){
    book[t]=1;
    if(h[t]==-1)return w[t];
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(book[j])continue;
        sum[t]+=dfs2(j);
    }
    return sum[t];
}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        cin>>w[i];
        sum[i]=w[i];
        son[i]=1;
    }
    for(int i=1;i<=n-1;i++){
        int a,b;cin>>a>>b;
        add(a,b);
        fa[b]=a;
    }
    dfs(1);
    memset(book,0,sizeof book);
    dfs2(1);
    while(m--){
        int op,x;
        cin>>op>>x;
        if(op==1){
            cout<<sum[x]<<endl;
        }else{
            if(!st[x].size())continue;
            auto t=st[x].begin()->second;
            st[fa[x]].erase({son[x],x});
            sum[x]-=sum[t];
            sum[t]+=sum[x];
            son[x]-=son[t];
            son[t]+=son[x];
            st[fa[x]].insert({son[t],t});
            st[t].insert({son[x],x});
            st[x].erase(st[x].begin());
        }
    }
    return 0;
}