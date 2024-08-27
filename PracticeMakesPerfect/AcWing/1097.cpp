#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef pair<int,int>PII;
#define x first
#define y second
char g[N][N];
int book[N][N];
int n,m;
int dir[8][2]={0,-1,-1,0,0,1,1,0,1,1,1,-1,-1,-1,-1,1};
queue<PII>q;
void bfs(int a,int b){
    q.push({a,b});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx=t.x+dir[i][0];int ty=t.y+dir[i][1];            
            if(tx<0||ty<0||tx>=n||ty>=m)continue;            
            if(g[tx][ty]=='.')continue;
            if(book[tx][ty])continue;
            book[tx][ty]=1;
            q.push({tx,ty});
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }    
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(book[i][j]==0&&g[i][j]=='w')
            {
                book[i][j]=1;
                bfs(i,j);
                cnt++;
            }
        }    
    }
    cout<<cnt<<endl;
    return 0;
}