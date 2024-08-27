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
    int u[10],v[10],w[10];
    int n,m;cin>>n>>m;
    int min=99999;
    int first[10];int next[10];//存第几条边
    for (int i = 1; i <= n; i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        next[i]=first[u[i]];
        first[u[i]]=i;
    }
    for (int i = 2; i <= n; i++)
        dis[i]=min;
    dis[1]=0;

    for (int j = 0; j < n-1; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if(dis[v[i]]>dis[u[i]]+w[i])
            dis[v[i]]=dis[u[i]]+w[i];
        }
    }
    queue<int>q;
    q.push(1);
    while (!q.empty())
    {
        int i=first[q.front()];   
        while(i!=-1){
            if(dis[v[i]]>dis[u[i]]+w[i])
            dis[v[i]]=dis[u[i]]+w[i];
            if(book[v[i]]==0)
            {q.push(v[i]);book[v[i]]=1;}
            i=next[i];
        }
        book[q.front()]=0;
        q.pop();
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<
    // }
    
    
    return 0;
}