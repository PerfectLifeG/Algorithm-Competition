#include<bits\stdc++.h>
using namespace std;
/*
4 5
1 4 9
2 4 6
1 2 5
4 3 8
1 3 7
*/
struct edge
{
    int data;
    int w;
    struct edge* next;
};
struct vertex
{
    int data;
    struct edge* next;
};
int main()
{
    //邻接表存边     完美！
    struct edge e[10];
    struct vertex ver[10];
    int n,m;
    scanf("%d %d",&n,&m);
    int u,v,w;
    struct edge* p=new edge;
    for (int i =1; i <= n; i++)
    {
        ver[i].data=i;
        ver[i].next=NULL;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        edge* q=ver[u].next;
        ver[u].next=p;
        p->next=q;p->data=v;p->w=w;
        p=new edge;
    }
    p=ver[1].next;
    while (p!=NULL)
    {
        printf("%d %d\n",p->data,p->w);
        p=p->next;
    }
    return 0;
}