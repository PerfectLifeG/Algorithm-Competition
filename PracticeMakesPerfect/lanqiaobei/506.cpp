#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10000;
struct Node{
    int a,b;
}e[N];
int h[N],ne[N],w[N],d[N],idx;
int n,m,k,ed;
void add(int c,int a,int b){
    e[idx]={a,b};   
    ne[idx]=h[c];
    h[c]=idx++;
}
int book[N];
int dfs(int t){
    if(book[t])return d[t];
    book[t]=1;
    for(int i=h[t];~i;i=ne[i]){
        auto a=e[i].a,b=e[i].b;
        d[t]=min(d[t],max(w[a],w[b])+max(dfs(a),dfs(b)));
    }
    return d[t];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k>>ed;
    memset(h,-1,sizeof h);
    memset(d,0x3f,sizeof d);
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=0;i<m;i++){
        int a;cin>>a;
        d[a]=0;
        book[a]=1;
    }
    for(int i=0;i<k;i++){
        int a,b,c;cin>>a>>b>>c;
        add(c,a,b);
    }
    dfs(ed);
    cout<<d[ed];
    return 0;
}