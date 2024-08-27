#include<bits/stdc++.h>
using namespace std;
const int N=1010,INF=0x3f3f3f3f;
int n,m,st,ed;
int res[N];
int ans[N];
int g[N][N];
int d[N];
int book[N];
int cnt[N];
void dijkstra(){
    memset(d,0x3f,sizeof d);
    d[st]=0;cnt[st]=1;
    for(int k=0;k<n;k++){
        int mn=INF,t;
        for(int i=0;i<n;i++){
            if(!book[i]&&mn>=d[i]){
                mn=d[i];
                t=i;
            }
        }
        book[t]=1;
        for(int j=0;j<n;j++){
            if(d[j]>=d[t]+g[t][j]){
                if(d[j]==d[t]+g[t][j])cnt[j]+=cnt[t];
                else cnt[j]=cnt[t];
                d[j]=d[t]+g[t][j];
                ans[j]=max(ans[j],ans[t]+res[j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>st>>ed;
    for(int i=0;i<n;i++){
        cin>>res[i];
        ans[i]=res[i];
    }
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=c;
        g[b][a]=c;
    }
    dijkstra();
    cout<<cnt[ed]<<' '<<ans[ed];
    return 0;
}