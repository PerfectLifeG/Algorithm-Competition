#include<bits/stdc++.h>
using namespace std;
int book[7];
int main()
{
    int n=6;int max=999999,min=999999;
    book[1]=1;
    int dis[7]={
        1,0,1,12,max,max,max
    };
    int u;
    int e[7][7]={
        {1,1,1,1,1,1,1},
        {1,0,1,12,max,max,max},
        {1,max,0,9,3,max,max},
        {1,max,max,0,max,5,max},
        {1,max,max,4,0,13,15},
        {1,max,max,max,max,0,4},
        {1,max,max,max,max,max,0}
    };
    //时间复杂度n^2  适用稠密图（边多）  权值为正
    for (int i = 0; i < n; i++)//每次确定一个距离
    {
        for (int j = 1; j <= n; j++)//找一个离源点最近的点记为u,其实这里能优化
        {
            if(book[j]==0&&dis[j]<min)
            {min=dis[j];
            u=j;}
        }
        min=max;
        book[u]=1;
        for (int v = 1; v <= n; v++)//找u的出路看能否缩短路径，这里也能优化
        {
            if(book[v]==0&&dis[v]>dis[u]+e[u][v])
            {dis[v]=dis[u]+e[u][v];}
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",dis[i]);
    }
    
    return 0;
}