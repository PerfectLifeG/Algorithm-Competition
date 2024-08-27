#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int book[10][10];
int maze[10][10]={
    {1,1,1,1,1},
    {1,0,0,1,0},
    {1,0,0,0,0},
    {1,0,0,1,0},
    {1,0,1,0,0},
    {1,0,0,0,1}
};
int way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int xx=4,yy=3;int n=5,m=4;int s=1000;//这个坑
void dfs(int x,int y,int step){
    int tx,ty;
    if(x==xx&&y==yy){
        if(s>step)s=step;
        return ;
    }
    
    for (int i = 0; i < 4; i++)
    {
        tx=x+way[i][0];ty=y+way[i][1];
        if(tx<1||ty<1||tx>n||ty>m||maze[tx][ty]==1)continue;
        if(book[tx][ty]==0){
            book[tx][ty]=1;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
}
int main()
{   
    book[1][1]=1;//
    dfs(1,1,0);
    printf("%d",s);
    return 0;
}