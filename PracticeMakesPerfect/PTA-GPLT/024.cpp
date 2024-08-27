#include<bits/stdc++.h>
using namespace std;
int root[10005];
int maxx;
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a);int rb=find(b); //谁有团伙，连谁
    if(rb!=b) root[ra]=rb;
    else if(ra!=a) root[rb]=ra;
    else root[rb]=ra;
}
int calcu(){
    int cnt=0;
    for (int i = 1; i <= maxx; i++)
    {
        if(root[i]==i)cnt++;
    }
    return cnt;
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < 10005; i++)root[i]=i;
    for (int i = 0; i < n; i++)
    {
        int m;cin>>m;
        int id;cin>>id;
        maxx=max(maxx,id);
        for (int i = 0; i < m-1; i++)
        {
            int a;cin>>a;
            maxx=max(maxx,a);
            merge(id,a);
        }
    }
    cout<<maxx<<" "<<calcu()<<endl;
    int m;cin>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b;cin>>a>>b;
        if(find(a)==find(b))
            cout<<"Y"<<endl;
        else cout<<'N'<<endl;  
    }
    return 0;
}