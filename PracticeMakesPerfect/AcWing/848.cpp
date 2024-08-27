#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int h[N],e[N],ne[N],idx;
int book[N];
queue<int>q,tp;
int n,m;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void bfs(){
    while(!q.empty()){
        int t=q.front();
        tp.push(t);
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            book[j]--;
            if(book[j]==0){
                q.push(j);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        book[b]++;
    }
    for(int i=1;i<=n;i++){
        if(book[i]==0)
        q.push(i);
    }
    bfs();
    if(tp.size()!=n)cout<<-1;
    else for(int i=0;i<n;i++){
        printf("%d",tp.front());
        tp.pop();
    }
    return 0;
}