#include<bits/stdc++.h>
using namespace std;
const int N=310;
int n,m;
int h[N][N];
int f[N][N];
int dis[4][2]={0,1,0,-1,-1,0,1,0};
int dp(int x,int y){
    int &t=f[x][y];
    if(t!=-1)return t;
    t=1;
    for(int i=0;i<4;i++){
        int tx=x+dis[i][0];
        int ty=y+dis[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&h[tx][ty]<h[x][y]){
            t=max(t,dp(tx,ty)+1);
        }
    }
    return t;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>h[i][j];
        }
    }
    memset(f,-1,sizeof f);
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)    
            res=max(res,dp(i,j)); 
    cout<<res;
    return 0;
}