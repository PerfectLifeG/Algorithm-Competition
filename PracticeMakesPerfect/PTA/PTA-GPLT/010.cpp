#include<bits/stdc++.h>
using namespace std;
int peo[101][101];
int peo2[101];
int find(int a){
    if(a==peo2[a])return a;
    return peo2[a]=find(peo2[a]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    if(a!=b)peo2[a]=b;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            peo[i][j]=0;
        }
        peo2[i]=i;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b,c;cin>>a>>b>>c;
        if(c==1){
            merge(a,b);
        }else if(c==-1){
            peo[a][b]=1;
            peo[b][a]=1;
        }
    }
    for (int i = 0; i < k; i++)
    {
        int a,b;cin>>a>>b;
        if(peo[a][b]==0&&find(a)==find(b))cout<<"No problem"<<endl;
        else if(peo[a][b]==0&&find(a)!=find(b))cout<<"OK"<<endl;
        else if(find(a)==find(b)&&peo[a][b]==1)cout<<"OK but..."<<endl;
        else if(peo[a][b]==1&&find(a)!=find(b))cout<<"No way"<<endl;
    }
    return 0;
}