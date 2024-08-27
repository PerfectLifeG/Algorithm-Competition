#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
// #define x first
// #define y second
int n,m;
int dir[4][2]={0,1,1,0};
int book[N][N];
int d[N][N];
int g[N][N];
int g2[N][N];
int cnt;
void dfs(int x,int y,int t,int ans){
    if(x==n&&y==m){cnt=min(cnt,ans);return;}
    if(x==y&&ans>d[0][0])return;
    if(x<=0||y<=0||x>n||y>m)return;
    d[x][y]=min(d[x][y],ans);
    if(g[x+1][y]!=t)dfs(x+1,y,g[x+1][y],ans+1);
    else dfs(x+1,y,g[x+1][y]^1,ans+2);
    if(g[x][y+1]!=t)dfs(x,y+1,g[x][y+1],ans+1);
    else dfs(x,y+1,g[x][y+1]^1,ans+2);
}
// void bfs(){
//     deque<PII>q;
//     q.push_back({1,1});
//     book[1][1]=1;
//     memset(d,0x3f,sizeof d);
//     d[1][1]=0;
//     while(q.size()){
//         auto t=q.front();
//         q.pop_front();
//         book[t.x][t.y]=1;
//         if(t.x==n&&t.y==m)return;
//         // cout<<t.x<<' '<<t.y<<' '<<g[t.x][t.y]<<' '<<d[t.x][t.y]<<endl;
//         for(int i=0;i<2;i++){
//             int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
//             if(book[tx][ty]||tx<=0||ty<=0||tx>n||ty>m)continue;
//             if(g2[t.x][t.y]==g[tx][ty]){
//                 if(d[tx][ty]>d[t.x][t.y]+2){
//                     g2[tx][ty]=g[t.x][t.y]^1;
//                     d[tx][ty]=d[t.x][t.y]+2;
//                     // cout<<t.x<<' '<<t.y<<' '<<d[t.x][t.y]<<endl;
//                     q.push_back({tx,ty});
//                 }
//             }else {
//                 if(d[tx][ty]>d[t.x][t.y]+1){
//                     d[tx][ty]=d[t.x][t.y]+1;
//                     // cout<<tx<<' '<<ty<<' '<<t.x<<' '<<t.y<<' '<<d[tx][ty]<<' '<<d[t.x][t.y]<<endl;
//                     q.push_front({tx,ty});
//                 }
//             }
//         }
//     }
// }
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=m;j++){
            g[i][j]=s[j-1]-'0';
            // g2[i][j]=g[i][j];
        }
    }
    cnt=0x3f3f3f3f;
    memset(d,0x3f,sizeof d);
    dfs(1,1,g[1][1],0);
    cout<<cnt;
    // int ans=0;
    // for(int i=2;i<=n;i++){
    //     for(int j=2;j<=m;j++){
    //         if(g[i-1][j]!=g[i][j]&&g[i-1][j]!=g[i-1][j-1]||g[i][j-1]!=g[i][j]&&g[i][j-1]!=g[i-1][j-1]){
    //             ans+=2;
    //         }else ans+=3;
    //     }
    // }
    // cout<<ans<<endl;
    // for(int i=0;i<n;i++){
    //     // string s;cin>>s;
    //     for(int j=0;j<m;j++){
    //         cout<<g[i][j];
    //     }
    //     cout<<endl;
    // }
    // bfs();
    // cout<<d[n][m];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}