#include<bits/stdc++.h>
using namespace std;
const int N=6010;
int n;
int h[N],e[N],ne[N],idx;
int w[N];
int f[N][2];
int root[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dfs(int t){
    f[t][1]+=w[t];
    for(int i=h[t];i!=-1;i=ne[i]){
        int j=e[i];
        dfs(j);
        f[t][0]+=max(f[j][0],f[j][1]);
        f[t][1]+=f[j][0];
    }
}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        root[a]=b;
        add(b,a);
    }

    int r=1;
    while(root[r]!=0)r++;
    dfs(r);
    printf("%d",max(f[r][0],f[r][1]));
    return 0;
}