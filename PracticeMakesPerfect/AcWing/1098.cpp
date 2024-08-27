#include<bits/stdc++.h>
using namespace std;
const int N=55;
typedef pair<int,int>PII;
#define x first
#define y second
int g[N][N];
int book[N][N];
int n,m;
int dir[4][2]={0,-1,-1,0,0,1,1,0};
queue<PII>q;
int cnt;int ans;
void bfs(int a,int b){
    q.push({a,b});
    int res=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.x+dir[i][0];int ty=t.y+dir[i][1];            
            if(tx<0||ty<0||tx>=m||ty>=n)continue;            
            if(g[t.x][t.y]>>i&1)continue;
            if(book[tx][ty])continue;
            book[tx][ty]=1;
            q.push({tx,ty});
            res++;
        }
    }
    ans=max(ans,res);
}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }    
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(book[i][j]==0)
            {
                book[i][j]=1;
                bfs(i,j);
                cnt++;
            }
        }    
    }
    cout<<cnt<<endl;
    cout<<ans;
    return 0;
}