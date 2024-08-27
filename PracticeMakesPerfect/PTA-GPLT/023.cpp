//直接遍历就过了，不需要bfs
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    vector<int>v;
    int col;
    int thi;
}node[505];
// int book[505];
int main()
{
    int n,m,p;cin>>n>>m>>p;
    for (int i = 0; i < n; i++)node[i].thi=i;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        node[a].v.push_back(b);
        node[b].v.push_back(a);
    }
    int k;cin>>k;
    for (int i = 0; i < k; i++)
    {
        map<int,int>m;
        for (int j = 1; j <= n; j++)
        {
            int a;cin>>a;
            node[j].col=a;
            m[a]++;
        }
        if(m.size()!=p){cout<<"No"<<endl;continue;}
        int flag=1;
        for (int i = 1; i <= n; i++)
        {
            int len=node[i].v.size();
            for (int j = 0; j < len; j++)
            {
                if(node[i].col==node[node[i].v[j]].col){flag=0;break;}
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        // queue<Node>q;q.push(node[1]);
        // int flag=1;
        // memset(book,0,sizeof(book));
        // while(!q.empty()){
        //     Node temp=q.front();
        //     q.pop();
        //     int len=temp.v.size();
        //     for (int j = 0; j < len; j++)
        //     {
        //         if(node[temp.v[j]].col==temp.col){flag=0;break;}
        //         if(book[temp.v[j]]==0)
        //         q.push(node[temp.v[j]]);
        //     }
        //     if(flag==0)break;
        //     book[temp.thi]=1;
        // }
    }
    return 0;
}