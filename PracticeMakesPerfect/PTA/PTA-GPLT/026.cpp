#include<bits/stdc++.h>
using namespace std;
struct Node
{
    vector<int>v;
    int cnt;
}node[100001];
int book[100001];
int maxx;
void dfs(int n){
    int len=node[n].v.size();
    for (int i = 0; i < len; i++)
    {
        int index=node[n].v[i];
        if(book[index]==0)
        {
            book[index]=1;
            node[index].cnt=node[n].cnt+1;
            maxx=max(maxx,node[index].cnt);
            dfs(index);
        }
    }
}
set<int>s;
void dfs2(int n){
    int len=node[n].v.size();
    for (int i = 0; i < len; i++)
    {
        int index=node[n].v[i];
        if(node[index].cnt==maxx)
            s.insert(index);
        if(book[index]==0)
        {
            book[index]=1;
            dfs2(index);
        }
    }
}
int main()
{
    int n;cin>>n;
    vector<int>root;
    for (int i = 1; i <= n; i++)
    {
        int a;cin>>a;
        if(a!=-1)node[a].v.push_back(i);
        if(a==-1){root.push_back(i);node[i].cnt=1;}
    }
    for (int i = 0; i < root.size(); i++)
    {
        dfs(root[i]);
    }
    cout<<maxx<<endl;
    memset(book,0,sizeof(book));
    for (int i = 0; i < root.size(); i++)
    {
        dfs2(root[i]);
    }
    if(!s.empty()){
        cout<<*s.begin();
        auto it=s.begin();it++;
        for (; it != s.end(); it++)
        {
            cout<<" "<<*it;
        }
    }
    return 0;
}