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
    int max=999999;int tmp[6],flag=0;
    int dis[6]={0,0,max,max,max,max};
    int n,m;//n顶点m边
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
    }
    //核心代码
    for (int k = 0; k < n-1; k++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int i = 1; i <= n; i++)
            {
                tmp[i]=dis[i];
            }
            if(dis[v[i]]>dis[u[i]]+w[i])  //这里也能优化 dis无更新可跳出
            dis[v[i]]=dis[u[i]]+w[i];
            for (int i = 1; i <= n; i++)
            {
                if(dis[i]!=tmp[i]){flag=1;break;}
            }
            if(flag)break;
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