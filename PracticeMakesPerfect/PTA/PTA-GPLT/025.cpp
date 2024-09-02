#include<bits/stdc++.h>
using namespace std;
struct node
{
    int s;
    int e;
}edge[10001];
int book[10001];
int root[10001];int n,m;
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
	int ra=find(a);int rb=find(b);
    if(ra!=a)root[b]=a;
    else if(rb!=b)root[a]=b;
    else root[a]=b;
}
int calcu(){
    int cnt=0;
    for (int i = 1; i <= n; i++)
    {
        if(root[i]==i)cnt++;
    }
    return cnt;
}
int main()
{
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b;cin>>a>>b;
        edge[i].s=a;
        edge[i].e=b;
    }
    int k;cin>>k;
    for (int i = 0; i < k; i++)
    {
        int p;cin>>p;
        memset(book,0,sizeof(book));
        for (int i = 1; i <= n; i++)root[i]=i;
        for (int i = 0; i < p; i++)
        {
            int a;cin>>a;
            book[a]=1;
        }
        for (int i = 0; i < m; i++)
        {
            if(book[edge[i].e]==0&&book[edge[i].s]==0){
                merge(edge[i].e,edge[i].s);
            }
        }
        if(calcu()==n){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    
    return 0;
}