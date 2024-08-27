#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=400010;
const int mod=998244353;    
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
    for(int i=0;i<m;i++){
        cin>>node[i].l>>node[i].r;
    }
    sort(node,node+m);
    int s=0;
    for(int i=0;i<m&&node[i].l+node[i+1].l<n;i++){
        int mnr=n-node[i].r;
        int mxl=n-node[i].l+1;
        int j=i+1;
        while(j<m){
            if(node[j].l<mxl&&node[j].r>=mnr){
                int l=n-node[j].r; 
                int r=n-node[j].l;
                if(l<node[i].l)l=node[i].l;
                if(r>node[i].r)r=node[i].r;
                s+=2*(r-l+1)%mod;
            }
            if(node[j].l>=mxl)break;
            j++;
        }
    }
    cout<<s;
    return 0;
}