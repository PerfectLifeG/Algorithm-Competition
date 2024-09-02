#include<bits/stdc++.h>
using namespace std;
int dis[1100];int book[1100];int pre[1100];int cnt[1100];int sum[1100];int value[1100];int e[1100][1100];
int main(){
    int n,m,start,end;int max=9999;int min=9999;
    cin>>n>>m>>start>>end;
    for (int i = 0; i < n; i++)
    {
        cin>>value[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i==j)e[i][j]=0;
            else e[i][j]=max;
        }
    }
   
    for (int i = 0; i < m; i++)
    {
        int a,b,c;cin>>a>>b>>c;
        e[a][b]=c;
        e[b][a]=c;//我去！！！  此题为双向图！！！！！！不是单向图  这是本题的重点  但是因为从start到end，所以我们把双向图好像又变成了单向图
        
        if(a==start)//初始化中start非常重要，只初始化与start有关的
        {sum[b]=value[b]+value[a];cnt[b]=1;pre[b]=a;}
        if(b==start)
        {sum[a]=value[a]+value[b];cnt[a]=1;pre[a]=b;}
    }

    for (int i = 0; i < n; i++)
        dis[i]=e[start][i];//初始化中start很重要
    dis[start]=0;
    book[start]=1;
    cnt[start]=1;
    int u;
    for (int i = 0; i < n-1; i++)//n-1成立
    {
        for (int j = 0; j < n; j++)
        {
            if(book[j]==0&&dis[j]<min)
            {min=dis[j];
            u=j;
            }
        }
        min=9999;
        book[u]=1;
        for (int v = 0; v < n; v++)
        {
            if(book[v]==0&&dis[v]>dis[u]+e[u][v]){
                dis[v]=dis[u]+e[u][v];
                pre[v]=u;
                sum[v]=sum[u]+value[v];
                cnt[v]=cnt[u];
            }else if(book[v]==0&&dis[v]==dis[u]+e[u][v]){
                cnt[v]+=cnt[u];
                if(sum[v]<sum[u]+value[v]){
                    pre[v]=u;
                    sum[v]=sum[u]+value[v];
                }
            }
        }
    }
    cout<<cnt[end]<<" "<<sum[end]<<endl;
    cout<<start;
    int temp[1100];int i=0;
    while (end!=start)
    {
        i++;
        temp[i]=end;
        end=pre[end];
    }
    for (; i > 0; i--)
    {
        cout<<" "<<temp[i];
    }
    return 0;
}