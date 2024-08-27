#include<bits/stdc++.h>
using namespace std;
const int N=2010;
const int M=100010;
int n,m,st,ed;
int h[N],e[2*M],ne[2*M],idx;//e是边  边得存两次
double w[2*M];
int book[N],pre[N];
double d[N],val[N];
void add(int a,int b,double c){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
void spfa(){
    queue<int>q;
    memset(d,0x3f,sizeof(d));
    d[st]=1;q.push(st);
    while(q.size()){
        int t=q.front();
        q.pop();
        book[t]=0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(d[j]<d[t]*w[i]){
                d[j]=d[t]*w[i];
                pre[j]=t;
                val[j]=w[i];
                if(book[j]==0){
                    q.push(j);
                    book[j]=1;
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,1-0.01*c);add(b,a,1-0.01*c);
    }
    cin>>st>>ed;
    spfa();
    printf("%.8lf",100/d[ed]);
    return 0;
}