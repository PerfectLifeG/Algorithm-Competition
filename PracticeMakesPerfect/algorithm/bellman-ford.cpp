#include<bits\stdc++.h>
using namespace std;
/*
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
*/
int main()
{
    int u[6],v[6],w[6];//第几条边
    int max=999999;
    int dis[6]={0,0,max,max,max,max};
    int n,m;//n顶点m边
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
    }
    //核心代码
    for (int k = 0; k < n-1; k++)//走了几次
    {
        for (int i = 1; i <= m; i++)//对每条边进行松弛
        {
            if(dis[v[i]]>dis[u[i]]+w[i])//如果此边能优化到此点的距离那么就更新  //这里也能优化 无变化可跳出
            dis[v[i]]=dis[u[i]]+w[i];     //并且有的路径已经是最短了，但依然遍历，这里浪费了时间
        }
    }
    //判断负权回路
    for (int i = 1; i <= m; i++)
    {
        if(dis[v[i]]>dis[u[i]]+w[i])
        {printf("存在负权回路");break;}
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",dis[i]);
    }
    
    return 0;
}