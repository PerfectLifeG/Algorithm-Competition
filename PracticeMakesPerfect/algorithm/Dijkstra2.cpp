#include<bits/stdc++.h>
using namespace std;
int book[10];int dis[10];
int u;
/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
int main()
{   
    int n,m;cin>>n>>m;
    int e[10][10];int min=99999;int max=99999;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j)e[i][j]==0;
            else
            e[i][j]=min;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int a,b,c;cin>>a>>b>>c;
        e[a][b]=c;
    }
    
    for (int i = 1; i <= n; i++)
        dis[i]=e[1][i];
    
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(book[j]==0&&dis[j]<min){
                u=j;
                min=dis[j];
            }
        }    
        book[u]=1;
        min=max;
        for (int v = 1; v <= n; v++)
        {
            if(book[v]==0&&dis[v]>dis[u]+e[u][v])
            dis[v]=dis[u]+e[u][v];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<dis[i]<<" ";
    }
    

    return 0;
}