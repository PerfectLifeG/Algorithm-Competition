#include<bits/stdc++.h>
using namespace std;
const int N=100010;
#define int long long
struct Node{
    int h;
    int v;
    int now;
    bool operator<(const Node n)const{
        if(now==n.now)return v>n.v;
        return now>n.now;
    }
}node[N];
priority_queue<Node,vector<Node>,less<Node>>q;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,T,a;cin>>n>>T>>a;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>node[i].h>>node[i].v;node[i].now=node[i].h;
        q.push(node[i]);
    }
    //cout<<q.top().h<<' '<<q.top().v<<' '<<q.top().now<<endl;
    while(q.size()){
        //cout<<q.top().h<<' '<<q.top().v<<' '<<q.top().now<<endl;
        auto t=q.top();q.pop();
        if(a<t.now&&a<=t.v*T){cout<<-1;return 0;}
        if(a<t.now){t.now=min(t.h,t.now-a+t.v);q.push(t);}
        cnt++;
    }
    cout<<1+(cnt-1)*T;
    return 0;
}