#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int INF=0x3f3f3f3f;
int n,m;
int book[N],d[N];
typedef pair<int,int>PII;
priority_queue<PII,vector<PII>,greater<PII>>heap; 
int e[2*N],w[2*N],ne[2*N],h[2*N],idx;
int pre[N];
void add(int a,int b,int c){                  
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    heap.push({0,1});
    while(!heap.empty()){
        int u=heap.top().second;
        heap.pop();
        if(u==n)return;
        if(book[u]!=0)continue;
        book[u]=1;
        for(int i=h[u];i!=-1;i=ne[i]){
            int j=e[i];
            if(book[j]==0){
                if(d[j]>d[u]+w[i]){
                    d[j]=d[u]+w[i];
                    pre[j]=u;
                }
                heap.push({d[j],j});
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    int dist=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        if(a==1||b==1)dist=c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);add(b,a,c);
    }
    dijkstra();
    int cnt=0;
    int st=n;
    while(st!=1){
        cnt++;
        st=pre[st];
    }
    if(cnt==m){
        cout<<dist+m-1;
    }else cout<<cnt;
    return 0;
}