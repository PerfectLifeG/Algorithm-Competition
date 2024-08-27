//此题有负权，输出用sum>INF/2
#include<iostream>
#include<cstring>
using namespace std;
const int N=510;
const int INF=0x3f3f3f3f;
int n,m;
int book[N];int g[N][N];
int d[N];//到集合的距离
int sum;
void prim(){
    memset(d,0x3f,sizeof(d));
    d[1]=0;int u;
    for(int k=0;k<n;k++){
        int mn=INF;
        for(int i=1;i<=n;i++){
            if(book[i]==0&&d[i]<=mn){//等于号  因为prim要求每个点都遍历到
                u=i;
                mn=d[i];
            }
        }
        book[u]=1;
        sum+=d[u];
        if(d[u]==INF)return;
        for(int i=1;i<=n;i++){
            if(book[i]==0){
            d[i]=min(d[i],g[u][i]);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));//这个忘了
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    prim();
    if(sum>INF/2)cout<<"impossible";
    else cout<<sum;
    return 0;
}