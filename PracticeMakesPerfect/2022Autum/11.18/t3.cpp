#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int INF=0x3f3f3f3f;
int n,m,r1,r2;
char g[N][N];
int dir[4][2]={1,0,0,-1,-1,0,0,1};
int book[N][N];
int book2[N][N];
int d[N][N];
int mn=INF;
typedef pair<int,int>PII;
queue<PII>q;
queue<PII>qq;
void bfs2(int a,int b){
    qq.push({a,b});
    memset(book2,0,sizeof(book2));
    book2[a][b]=1;
    while(!qq.empty()){
        int x=qq.front().first;
        int y=qq.front().second;
        qq.pop();
        for(int i=0;i<4;i++){
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&book2[tx][ty]==0&&g[tx][ty]!='*'){
                if((book[tx][ty]==1)){mn=min(d[x][y]+1+d[tx][ty],mn);}
                else {d[tx][ty]=d[x][y]+1;book2[tx][ty]=1;qq.push({tx,ty});}
            }
        }
    }
}
void bfs1(int a,int b,int c,int dd){
    q.push({a,b});
    book[a][b]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&g[tx][ty]!='*'&&book[tx][ty]==0&&d[x][y]+1<=r1){
                book[tx][ty]=1;
                d[tx][ty]=d[x][y]+1;
                if(abs(tx-c)+abs(ty-dd)<=r2){
                    bfs2(c,dd);
                }
                if(tx==c&&ty==dd){mn=d[tx][ty];return;}
                q.push({tx,ty});
            }
        }
    }
}
int main(){
    cin>>n>>m>>r1>>r2;
    int x1,y1,x2,y2;
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%c",&g[i][j]);
            if(g[i][j]=='P'){
                x1=i;y1=j;
            }
            if(g[i][j]=='M'){
                x2=i;y2=j;
            }
        }
        getchar();
    }
    bfs1(x1,y1,x2,y2);
    bfs2(x2,y2);
    if(mn>INF/2)cout<<-1;
    else cout<<mn;
    return 0;
}