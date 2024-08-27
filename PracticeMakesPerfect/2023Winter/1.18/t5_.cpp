#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=50;
const int mod=998244353;    
int a[N],b[N];
struct Node
{
    int l;
    int r;
    bool operator<(const Node n)const{
        return l<n.l;
    }
}node[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    int mx=0;
    for(int i=0;i<m;i++){
        cin>>node[i].l>>node[i].r;
        b[node[i].l]++;b[node[i].r+1]--;
        mx=max(mx,node[i].r);
    }
    sort(node,node+m);
    for(int i=node[0].l;i<=mx;i++){
        b[i]+=b[i-1];
    }
    for(int i=node[0].l;i<=mx;i++){
        a[i]=b[i];
        a[i]+=a[i-1];
    }
    int s=0;
    for(int i=0;i<m;i++){
        if(node[i].l>=n)continue;
        int l=max(node[0].l,n-node[i].r);
        int r=min(n-node[i].l,mx);
        if(l>r)continue;
        int mnl=max(l,node[i].l);
        int mxr=min(r,node[i].r);
        s+=(a[r]-a[l-1])-max((int)0,mxr-mnl+1))%mod;
    }
    cout<<s;
    return 0;
}