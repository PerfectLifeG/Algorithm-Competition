#include<bits/stdc++.h>
using namespace std;
struct Node{
    int start;
    int end;
    int a;int b;int c;
    int d;int e;int f;
};
int cmp(Node n1,Node n2){
    return n1.start<n2.start;
}
int main()
{
    int n;cin>>n;
    Node node[n];
    for (int i = 0; i < n; i++)
    {
        int a,b,c,d,e,f;
        scanf("%d:%d:%d - %d:%d:%d",&a,&b,&c,&d,&e,&f);
        node[i].a=a;node[i].b=b;node[i].c=c;
        node[i].d=d;node[i].e=e;node[i].f=f;
        int time=a*3600+b*60+c;
        node[i].start=time;
        time=d*3600+e*60+f;
        node[i].end=time;
    }
    sort(node,node+n,cmp);
    if(node[0].start!=0){
        printf("00:00:00 - %02d:%02d:%02d\n",node[0].a,node[0].b,node[0].c);
    }
    int idx=node[0].end;
    for (int i = 1; i < n; i++)
    {
        if(idx!=node[i].start){
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n",node[i-1].d,node[i-1].e,node[i-1].f,node[i].a,node[i].b,node[i].c);
        }
        idx=node[i].end;
    }
    if(node[n-1].end!=86399){
        printf("%02d:%02d:%02d - 23:59:59\n",node[n-1].d,node[n-1].e,node[n-1].f);
    }
    return 0;
}