#include<bits/stdc++.h>
using namespace std;
struct Node{
    int fa;
    int cnt;
}node[10005];
int edge[10005][10005];
int book[10005];
int cnt,Max=1,ind;
int main()
{
    int n;cin>>n;
    // if(n==1){cout<<1<<endl<<0;return 0;}
    for (int i = 0; i < n; i++)
    {
        int m;cin>>m;
        for (int j = 0; j < m; j++)
        {
            int a;cin>>a;
            edge[i][a]=1;
            edge[a][i]=1;
            book[a]=1;
        }
    }
    int j=0;
    while(book[j]!=0){
        j++;
    }
    memset(book,0,sizeof(book));
    queue<int>q;
    q.push(j);
    node[j].cnt=1;book[j]=1;
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if(edge[t][i]==1&&book[i]==0){
                book[i]=1;
                q.push(i);
                node[i].fa=t;
                node[i].cnt=node[t].cnt+1;
                if(node[i].cnt>Max){
                    Max=node[i].cnt;
                    ind=i;
                }
            }
        }
    }
    cout<<Max<<endl;
    int a[Max];
    for (int i = 0; i < Max; i++)
    {
        a[i]=ind;
        ind=node[ind].fa;
    }
    cout<<a[Max-1];
    for (int i = Max-2; i >= 0; i--)
    {
        cout<<" "<<a[i];
    }
    return 0;
}