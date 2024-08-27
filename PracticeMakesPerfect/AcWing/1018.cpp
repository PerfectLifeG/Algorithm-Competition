#include<bits/stdc++.h>
using namespace std;
const int N=105;
int w[N][N];
int f[N][N];
int dis[4][2]={0,1,0,-1,1,0,-1,0};
typedef pair<int,int> PII;
#define x first
#define y second
void bfs(){
    queue<PII>q;
    q.push({1,1});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.x+dis[i][0];int ty=t.y+dis[i][1];
            if(w[tx][ty]&&!f[tx][ty])q.push({tx,ty});
            if(f[tx][ty]){
                f[tx][ty]=min(f[tx][ty],f[t.x][t.y]+w[tx][ty]);
            }else f[tx][ty]=f[t.x][t.y]+w[tx][ty];
        }
    }
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    f[1][1]=w[1][1];
    bfs();
    cout<<f[n][n];
    return 0;
}