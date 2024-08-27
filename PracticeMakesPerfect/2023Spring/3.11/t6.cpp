#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000010;
int n,m;
int mn=0x3f3f3f3f;
int h[N],e[N],ne[N],w[N],idx;
void add(int a,int b,int c){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    //s[idx]=1;
    h[a]=idx++;
}
int d[N],d2[N];
queue<int> q;
void bfs(){
    memset(d, 0x6f, sizeof d);
    memset(d2, 0x6f, sizeof d2);
    q.push(1);d[1] = 0;d2[1] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        // if(t == n){mn=min(mn,d2[n]);};   
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(d[j] > d[t] + 1){
                d2[j]=min(d2[j],d2[t]+w[i]);
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);add(b,a,c);
    }
    bfs();
    cout<<d[n]+1<<' '<<d2[n];
    return 0;
}