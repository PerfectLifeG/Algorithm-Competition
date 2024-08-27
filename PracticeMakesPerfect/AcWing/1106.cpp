#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef pair<int,int>PII;
#define x first
#define y second
int g[N][N];
int book[N][N];
int n,m,cnt1,cnt2;
int dir[8][2]={0,-1,-1,0,0,1,1,0,1,1,1,-1,-1,-1,-1,1};
queue<PII>q;
void bfs(int a,int b){
    q.push({a,b});
    int sg=0,sf=0;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx=t.x+dir[i][0];int ty=t.y+dir[i][1];            
            if(tx<0||ty<0||tx>=n||ty>=n)continue;
            if(g[tx][ty]<g[t.x][t.y]){sf++;continue;}
            if(g[tx][ty]>g[t.x][t.y]){sg++;continue;}
            if(book[tx][ty])continue;
            book[tx][ty]=1;
            q.push({tx,ty});
        }
    }
    if(sg&&!sf)cnt2++;
    if(!sg&&sf)cnt1++;
    if(!sg&&!sf){cnt2++;cnt1++;}
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }    
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(book[i][j]==0)
            {
                book[i][j]=1;
                bfs(i,j);
            }
        }    
    }
    cout<<cnt1<<' '<<cnt2;
    return 0;
}