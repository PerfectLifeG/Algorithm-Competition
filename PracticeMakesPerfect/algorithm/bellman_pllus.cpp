#include<bits/stdc++.h>
using namespace std;
//思路是按边来优化路径

/*
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4 
4 5 5
5 3 6
*/
int book[6];
//仅对路径变化的点的相邻边松弛    松弛成功就入列
int main()
{
    queue<int>q;//简化head、tail
    int dis[6];int max=999999;
    int n,m;//n顶点m边
    scanf("%d %d",&n,&m);
    int u[m+1],v[m+1],w[m+1];//第几条边
    int first[n+1],next[m+1];//first记录顶点的第一条边  next记录边的下条边
    for (int i = 1; i <= n; i++) {first[i]=-1;book[i]=0;dis[i]=max;} 
    dis[1]=0;book[1]=1;
    q.push(1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
        next[i]=first[u[i]];
        first[u[i]]=i;
    }
    //核心代码
    while (!q.empty())
    {
        int i=first[q.front()];//注意i是队列中顶点的边  不是顶点
        while (i!=-1)
        {
            if(dis[v[i]]>dis[u[i]]+w[i])
            {
                dis[v[i]]=dis[u[i]]+w[i];//松弛成功就入列
                if(book[v[i]]==0)
                {q.push(v[i]);book[v[i]]=1;}
            }
            i=next[i];
        }
        book[q.front()]=0;
        q.pop();
    }
    
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",dis[i]);
    }
    
    return 0;
}