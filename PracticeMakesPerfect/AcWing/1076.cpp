#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef pair<int,int>PII;
#define x first
#define y second
int g[N][N];
int book[N][N];
PII pre[N][N];
int n;
int dir[4][2]={0,-1,-1,0,0,1,1,0};
queue<PII>q;
void bfs(int a,int b){
    q.push({a,b});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.x+dir[i][0];int ty=t.y+dir[i][1];            
            if(tx<0||ty<0||tx>=n||ty>=n)continue;
            if(g[tx][ty]==1)continue;
            if(book[tx][ty]!=-1&&book[tx][ty]<book[t.x][t.y]+1)continue;
            book[tx][ty]=book[t.x][t.y]+1;
            pre[tx][ty].x=t.x;
            pre[tx][ty].y=t.y;
            q.push({tx,ty});
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    memset(book,-1,sizeof(book));
    book[n-1][n-1]=0;
    bfs(n-1,n-1);
    int a=0,b=0;
    for(int i=0;i<book[0][0]+1;i++){
        int aa=a;int bb=b;
        printf("%d %d\n",a,b);
        a=pre[aa][bb].x;b=pre[aa][bb].y;
    }
    return 0;
}