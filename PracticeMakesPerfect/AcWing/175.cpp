//必须push前面，因为权值不唯一
#include<bits/stdc++.h>
using namespace std;
const int N =510;
typedef pair<int,int>PII;
#define x first
#define y second
int n,m;
int dir[4][2]={1,1,1,-1,-1,-1,-1,1};
int dir2[4][2]={0,0,0,-1,-1,-1,-1,0};
char op[4]={'\\','/','\\','/'};
char g[N][N];
int book[N][N];
deque<PII>q;
void bfs(){
    while(q.size()){
        auto t=q.front();
        q.pop_front();
        if(t.x==n&&t.y==m)return;
        for(int i=0;i<4;i++){
            int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
            int tx2=t.x+dir2[i][0],ty2=t.y+dir2[i][1];
            if(tx<0||ty<0||tx>n||ty>m)continue;
            if(tx2<0||ty2<0||tx2>=n||ty2>=m)continue;
            if(g[tx2][ty2]==-1)continue;
            if(g[tx2][ty2]==op[i]){
                if(book[tx][ty]>book[t.x][t.y]||book[tx][ty]==-1){
                    book[tx][ty]=book[t.x][t.y];
                    q.push_front({tx,ty});
                }
            }else{
                if(book[tx][ty]>book[t.x][t.y]+1||book[tx][ty]==-1){
                    book[tx][ty]=book[t.x][t.y]+1;
                    g[tx2][ty2]=op[i];
                    q.push_back({tx,ty});
                }
            }
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        memset(g,-1,sizeof g);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>g[i][j];
                
        memset(book,-1,sizeof book);
        book[0][0]=0;
        q.clear();
        q.push_back({0,0});
        
        bfs();
        if(book[n][m]==-1)printf("NO SOLUTION\n");
        else printf("%d\n",book[n][m]);
    }
    return 0;
}