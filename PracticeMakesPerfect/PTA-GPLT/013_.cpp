#include<bits/stdc++.h>
using namespace std;
int root[505],book[505];
int n,m;
struct edge
{
    int u,v;
}e[5001];
int find(int a){
    if(root[a]==a) return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a);
    int rb=find(b);
    if(ra!=rb)
        root[ra]=rb;
}
int caclu(){
    int cntt=0;
    for (int  i = 0; i < n; i++)
    {
        if(root[i]==i)cntt++;
    }   
    return cntt;
}
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        root[i]=i;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b;cin>>a>>b;
        e[i].u=a;
        e[i].v=b;
        merge(a,b);
    }
    int k;cin>>k;
    int cnt=caclu();
    for (int i = 0; i < k; i++)
    {
        for (int i = 0; i < n; i++)
        {
            root[i]=i;
        }
        int a;cin>>a;book[a]=1;
        for (int j = 0; j < m; j++)
        {
            if(book[e[j].u]==0&&book[e[j].v]==0){
                merge(e[j].u,e[j].v);
            }
        }
        int cacl=caclu();
        if(cacl>cnt+1){
            cout<<"Red Alert: City "<<a<<" is lost!"<<endl;
        }else cout<<"City "<<a<<" is lost."<<endl;
        if(i==n-1) cout<<"Game Over."<<endl;
        cnt=cacl;
    }
    return 0;
}