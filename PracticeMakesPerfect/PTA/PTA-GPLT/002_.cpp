#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
struct Node
{
    int num,next,addr,key;
    Node(){
        num=2*maxn;
    }
}node[100000];
int book[100000];
int cmp(Node n1,Node n2){
    return n1.num<n2.num;
}
int main()
{
    int start,n,cnt1=0,cnt2=0;
    scanf("%d %d",&start,&n);
    for (int i = 0; i < n; i++)
    {
        int addr;
        scanf("%d",&addr);
        node[addr].addr=addr;
        scanf("%d %d",&node[addr].key,&node[addr].next);
    }
    for (int i = start; i != -1; i=node[i].next)
    {
        if(book[abs(node[i].key)]==0){
            book[abs(node[i].key)]=1;
            node[i].num=cnt1;
            cnt1++;
        }else{
            node[i].num=maxn+cnt2;
            cnt2++;
        }
    }
    sort(node,node+maxn,cmp);
    for (int i = 0; i < cnt1+cnt2; i++)
    {
        printf("%05d %d ",node[i].addr,node[i].key);
        if(i==cnt1-1||i==cnt1+cnt2-1) printf("-1\n");
        else printf("%05d\n",node[i+1].addr);
    }
    return 0;
}