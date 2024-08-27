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
//此题不用标记  也相当于标记了，用maze直接标记  
struct node
{
    int x;
    int y;
    int day;
};
int way[4][2]={ 0,1, 1,0, 0,-1, -1,0};
int maze[50][50];
int main()
{
    int m,n;
    cin>>m>>n;  
    queue<node>q;
    int cnt=0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]==2)q.push({i,j,0});
            if(maze[i][j]==1)cnt++;
        }
    }
    int maxday=0;
    while (!q.empty())
    {
        node t=q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx=t.x+way[i][0];int ty=t.y+way[i][1];
            if(tx<1||ty<1||tx>m||ty>n||maze[tx][ty]==0)continue;
            if(maze[tx][ty]==1){
                cnt--;              //别漏了
                maze[tx][ty]=2;
                q.push({tx,ty,t.day+1});
            }
            if(maxday<q.back().day)maxday=q.back().day;
        }
    }
    if(cnt)cout<<"victory";//有人没被感染
    else cout<<maxday;
    
    return 0;
}