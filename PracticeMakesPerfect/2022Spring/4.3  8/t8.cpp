#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
struct edge
{
    int u;
    int v;
    int w;
};
int cmp(edge a,edge b){
    return a.w < b.w;
}
int peo[1000];
int find(int a){
    if(a==peo[a])return a;
    return peo[a]=find(peo[a]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    peo[b]=a;
}
int main()
{
    int n,k,m;
    while (scanf("%d %d %d",&n,&k,&m)!=EOF)
    {   
        edge e[100];
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
        }
        sort(e,e+m,cmp);
        for (int i = 0; i < n; i++)
        {
            peo[i]=i;
        }
        int s=0;int cnt=0;int times=2;
        for (int i = 0; i < m; i++)
        {
            if(find(e[i].u)!=find(e[i].v)){
                if((e[i].u==k||e[i].v==k)&&times==0)continue;
                if(e[i].u==k||e[i].v==k)times--;
                merge(e[i].u,e[i].v);
                s+=e[i].w;
                cnt++;
            }
            if(cnt==n-1)break;
        }
        if(cnt!=n-1)printf("-1");
        else printf("%d\n",s);
    }
    return 0;
}