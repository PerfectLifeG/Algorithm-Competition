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
int book[7];
int e[17][17];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {   
        int dis[n+1]={};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin>>e[i][j];
                if(i==1)dis[j]=e[i][j];
            }
        }
        int max= 999999;int min= 999999;
        book[1]=1;
        int u;
        
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
        int s=0;
        for (int i = 2; i <= n; i++)
        {
            s+=dis[i];
        }
        cout<<s<<endl;
    }
    
    
    
    return 0;
}