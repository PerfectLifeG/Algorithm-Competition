#include<bits/stdc++.h>
using namespace std;
const int N=50010;
struct Node{
    int w;
    int s;
    int a;
    bool operator<(const Node &n) const
    {
        return a<n.a;
    }
}node[N];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>node[i].w>>node[i].s;
        node[i].a=node[i].w+node[i].s;
    }
    sort(node+1,node+n+1);
    int mx=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        node[i].w+=node[i-1].w;
        node[i].a=node[i-1].w-node[i].s;
        if(node[i].a>mx){
            mx=node[i].a;
        }
    }
    cout<<mx;
    return 0;
}