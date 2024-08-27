#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
/*
5 4 4 3
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
*/
struct node
{
    int x;
    int y;
    int step;
};
int maze[100][100];int book[100][100];//不用book好像就行
int way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    int n,m;cin>>n>>m;//地图边界
    int xx,yy;cin>>xx>>yy;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }

    //bfs模板
    queue<node>q;
    q.push({1,1,0});
    while (!q.empty())
    {
        node t=q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx=t.x+way[i][0];
            int ty=t.y+way[i][1];
            if(tx<1||ty<1||tx>n||ty>m||maze[tx][ty]==1)continue;
            if(maze[tx][ty]==0){
                q.push({tx,ty,t.step+1});
                maze[tx][ty]=1;
            }
            if(tx==xx&&ty==yy){
                cout<<q.back().step;return 0;
            }
        }
    }
    return 0;
}