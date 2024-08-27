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
/*
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2

*/
using namespace std;
struct edge
{
    int u;
    int v;
    int w;
};
int cmp(const void* a,const void* b){
    return (*(edge*)a).w > (*(edge*)b).w ? 1 : -1;
}
edge e[10];int n=6,m=9;
int peo[7];//n+1
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
    int s=0;int cnt=0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    }
    qsort(e,m,sizeof(e[0]),cmp);
    for (int i = 0; i <= n; i++)
    {
        peo[i]=i;
    }
    
    for (int i = 0; i < m; i++)
    {
        if(find(e[i].u)!=find(e[i].v)){
            merge(e[i].u,e[i].v);
            s+=e[i].w;
            cnt++;
        }
        if(cnt==n-1)break;
    }
    printf("%d",s);

    return 0;
}