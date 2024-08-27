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
const int N=1100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int g[N][N];
int book1[N][N];
int book2[N][N];
int book3[N][N];
int book4[N][N];
int n,m;
int dir[5][2]={1,0,0,1,-1,0,0,-1,1,0};
void dfs(int x,int y,int fx,int fy){
    if(x<1||y<1||x>n||y>m)return;
    if(book1[x][y]||g[x][y]==-1)return;
    if(x==n&&y==m)return;
    book1[x][y]=1;
    for(int i=0;i<3;i++){
        int tx=x+dir[i][0],ty=dir[i][1]+y;
        if(tx==fx&&ty==fy)continue;
        dfs(tx,ty,x,y);
        book2[x][y]|=book2[tx][ty];
    }
}
void dfs2(int x,int y,int fx,int fy){
    if(x<1||y<1||x>n||y>m)return;
    if(book3[x][y]||g[x][y]==-1)return;
    if(x==1&&y==1)return;
    book3[x][y]=1;
    for(int i=2;i<5;i++){
        int tx=x+dir[i][0],ty=dir[i][1]+y;
        if(tx==fx&&ty==fy)continue;
        dfs2(tx,ty,x,y);
        book4[x][y]|=book4[tx][ty];
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    book2[n][m]=1;
    book4[1][1]=1;
    dfs(1,1,1,1);
    dfs2(n,m,n,m);

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cout<<i<<' '<<j<<' '<<book2[i][j]<<' '<<book4[i][j]<<endl;
            if(book2[i][j]&&book4[i][j]&&g[i][j]>0){
                ans+=g[i][j];
            }
        }
    }
    cout<<ans<<endl;


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}