#include<bits/stdc++.h>
using namespace std;
const int N=155;
int n,m;
int book[N][N];
char g[N][N];
typedef pair<int,int>PII;
#define x first
#define y second
queue<PII>q;
int dir[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
void bfs(int a,int b,int c,int d){
    q.push({a,b});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m)continue;
            if(g[tx][ty]=='*')continue;
            if(book[tx][ty]!=-1)continue;
            book[tx][ty]=book[t.x][t.y]+1;
            if(tx==c&&ty==d)return;
            q.push({tx,ty});
        }
    }
}
int main(){
    cin>>m>>n;
    int a,b,c,d;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='K'){
                a=i;b=j;
            }
            if(g[i][j]=='H'){
                c=i;d=j;
            }
        }
    memset(book,-1,sizeof(book));
    book[a][b]=0;        
    bfs(a,b,c,d);
    cout<<book[c][d];
    return 0;
}