#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int h[N],e[N],ne[N],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
// class cmp {
// public:
//     bool operator()(const pair<int, int>& a, const pair<int, int>& b) const 
//     {
//         if( a.first == b.first){
//             a.second < b.second;
//         }
//         return a.first > b.first;
//     }
// };
int son[N];int sum[N];int fa[N];
typedef pair<int,int>PII;
set<PII>st[N];
int book[N];
void dfs(int t){
    if(book[t])return;
    book[t]=1;
    for(int i=h[t];~i;i=ne[i]){
        int j=e[i];
        if(book[j])continue;
        dfs(j);
        fa[j]=t;
        sum[t]+=sum[j];
        son[t]+=son[j];
        st[t].insert({-son[j],j});
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        cin>>sum[i];
        son[i]=1;
    }
    for(int i=1;i<=n-1;i++){
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    while(m--){
        int op,x;
        cin>>op>>x;
        if(op==1){
            cout<<sum[x]<<endl;
        }else{
            if(!st[x].size())continue;
            auto t=st[x].begin()->second;
            st[fa[x]].erase({-son[x],x});
            st[x].erase(st[x].begin());
            sum[x]-=sum[t];
            sum[t]+=sum[x];
            son[x]-=son[t];
            son[t]+=son[x];
            st[fa[x]].insert({-son[t],t});
            st[t].insert({-son[x],x});
            fa[t]=fa[x];
            fa[x]=t;
        }
    }
    return 0;
}