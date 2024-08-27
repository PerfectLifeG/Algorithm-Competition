#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=10;
const int INF=0x3f3f3f3f;
int n,m;
int book[N],d[N];
typedef pair<int,int>PII;
priority_queue<PII,vector<PII>,greater<PII>>heap;  //维护距离需要知道节点编号，所以使用pair 堆用来找最短距离
int e[N],w[N],ne[N],h[N],idx;                   //多了一个权重数组  w存a到b的距离
void add(int a,int b,int c){                    //多写一个权重即可
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    d[1]=0;//这个很重要
    heap.push({0,1});
    while(!heap.empty()){
        int u=heap.top().second;
        heap.pop();
        if(u==n)return;
        if(book[u]!=0)continue;
        book[u]=1;
        for(int i=h[u];i!=-1;i=ne[i]){//邻接表中的i相当于idx 但是book中的i就是第i个顶点  这点要分清
            int j=e[i];//i是下标  存的数据都在数组所对应的i这个下标中
            if(book[j]==0&&d[j]>d[u]+w[i]){//这里是w[i]
                d[j]=d[u]+w[i];//此时w中表示的是u到j的距离
                heap.push({d[j],j});
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    dijkstra();
    if(d[n]==INF)cout<<-1;
    else cout<<d[n];
    return 0;
}