#include<bits/stdc++.h>
using namespace std;
int ans;
vector<int>v[100005];
int book[100005];
int main()
{
    int n;cin>>n;
    for (int i = 1; i <= n; i++)
    {   
        int m;cin>>m;
        for (int j = 0; j < m; j++)
        {
            int a;cin>>a;
            v[i].push_back(a);
            book[a]=1;
        }
    }
    int r;
    for(int i=1;i<=n;i++){//找头节点
        if(book[i]==0){
            r=i;
        }
    }
    memset(book,0,sizeof(book));
    queue<int>q;
    q.push(r);
    book[r]=1;
    while(!q.empty()){
        ans=q.front();
        q.pop();
        for (int i = 0; i < v[ans].size(); i++)
        {
            if(book[v[ans][i]]==0)
            {
                book[v[ans][i]]=1;
                q.push(v[ans][i]);
            }
        }
    }
    cout<<ans;
    return 0;
}