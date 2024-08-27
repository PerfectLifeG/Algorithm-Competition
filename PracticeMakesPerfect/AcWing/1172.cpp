#include<bits/stdc++.h>
using namespace std;
const int N=40010;
int n,m;
int h[N],e[N*2],ne[N*2],idx;
int depth[N],fa[N][16];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void bfs(int t){
    memset(depth,-1,sizeof depth);
    queue<int>q;
    q.push(t);
    depth[0]=0;depth[t]=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(depth[j]!=-1)continue;
            depth[j]=depth[t]+1;
            fa[j][0]=t;
            for(int k=1;k<16;k++){
                fa[j][k]=fa[fa[j][k-1]][k-1];
            }
            q.push(j);
        }
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b])swap(a,b);
    for(int j=15;j>=0;j--){
        if(depth[fa[a][j]]>=depth[b]){
            a=fa[a][j];
        }
    }
    if(a==b)return a;
    for(int j=15;j>=0;j--){//二进制思想优化
        if(fa[a][j]!=fa[b][j]){
            a=fa[a][j];
            b=fa[b][j];
        }
    }
    return fa[a][0];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int root=0;
    memset(h,-1,sizeof(h));
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(b==-1){
            root=a;
        }else{
            add(a,b);
            add(b,a);
        }
    }
    bfs(root);
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        int t=lca(a,b);
        if(a==t){
            puts("1");
        }else if(b==t){
            puts("2");
        }else puts("0");
    }
    return 0;
}