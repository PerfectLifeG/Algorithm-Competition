#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=10010;
queue<int>q;
int n,m;
int h[N],e[N],ne[N],idx;
int book[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void bfs(){
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            if(book[e[i]]==0){
                book[e[i]]=book[t]+1;
                q.push(e[i]);
            }
            if(e[i]==n)return;
        }
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    q.push(1);
    book[1]=1;
    bfs();
    if(book[n]==0)cout<<-1;
    else cout<<book[n]-1;
    return 0;
}