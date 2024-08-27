#include<bits/stdc++.h>
using namespace std;
const int N=100010;
const int INF=0x3f3f3f3f;
int w[N],e[N],ne[N],h[N],idx;
int n,m;
int d[N],book[N];
void add(int a,int b,int c){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
queue<int>q;
void spfa(){
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    q.push(1);
    while(q.size()){
        int t=q.front();
        q.pop();
        book[t]=0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(d[j]>d[t]+w[i]){
                d[j]=d[t]+w[i];
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
        add(a,b,c);
    }
    spfa();
    if(d[n]>INF/2)cout<<"impossible";
    else cout<<d[n];
    return 0;
}