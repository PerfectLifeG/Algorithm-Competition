#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10;
struct Node{
    int a,b,c,x,y;
    // bool operator<(const Node &n){
    //     return t<n.t;
    // }
}node[N];
int mx;
int n,tt,p;
int book[N];
void dfs(int t,int time,int score){
    if(t>n)return;
    mx=max(mx,score);
    for(int i=0;i<n;i++){
        auto d=node[i];
        if(book[i]||time+d.x>tt)continue;
        book[i]=1;
        // cout<<i<<' '<<d.a-(d.x+time)*d.b-d.y*p<<endl;
        dfs(t+1,time+d.x,score+max(d.c,d.a-(d.x+time)*d.b-d.y*p));
        book[i]=0;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>tt>>p;
    for(int i=0;i<n;i++){
        int a,b,c,x,y;
        cin>>node[i].a>>node[i].b>>node[i].c>>node[i].x>>node[i].y;
    }
    // sort(node,node+n);
    // for(int i=0;i<n;i++)cout<<node[i].s<<endl;
    dfs(0,0,0);
    cout<<mx;
    return 0;
}