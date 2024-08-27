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
static int book[200][200];
int maze[200][200]={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,}
};
int way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int xx,yy;int flag=0;int m;//这个坑
void dfs(int x,int y,int step){
    int tx,ty;
    if(x==xx&&y==yy){
        flag =1;
        return ;
    }
    
    for (int i = 0; i < 4; i++)
    {
        if(flag==1)return;
        tx=x+way[i][0];ty=y+way[i][1];
        if(tx<1||ty<1||tx>m||ty>m||maze[tx][ty]==1)continue;
        if(book[tx][ty]==0){
            book[tx][ty]=1;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
}
int main()
{   
    int n;cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>m;
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                cin>>maze[j][k];
            }
        }
        xx=m;yy=m;
        book[1][1]=1;//
        dfs(1,1,0);
        if(flag==1)
        printf("LCyyds\n");
        else printf("QwQ\n");
        flag=0;
        // for (int j = 1; j <= m; j++)
        // {
        //     for (int k = 1; k <= m; k++)
        //     {
        //         book[j][k]=0;
        //     }
        // }
        
    }
    
    
    return 0;
}