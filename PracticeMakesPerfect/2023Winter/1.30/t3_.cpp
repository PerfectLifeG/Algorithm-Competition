#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
struct Node{
    int h;
    int v;
    int now;
    bool operator<(const Node n)const{
        if(now==n.now)return v<n.v;
        return now<n.now;
    }
}node[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,T,a;cin>>n>>T>>a;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>node[i].h>>node[i].v;node[i].now=node[i].h;
    }
    sort(node,node+n);
    for(int i=0;i<n;i++){
        if(a<node[i].now&&a<=node[i].v*T){cout<<-1;return 0;}
        if(a<node[i].now)
            while(node[i].now>0){
                node[i].now=min(node[i].h,node[i].now+node[i].v);
                cnt++;
                node[i].now-=a;
            }
        else cnt++;
    }
    cout<<1+(cnt-1)*T;
    return 0;
}