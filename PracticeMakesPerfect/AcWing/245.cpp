#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
struct Node{
    int l,r;
    int sum=0,lmx=0,rmx=0,mx=0;
}tr[N*4];
int n,m;
int a[N];
void up(Node &t,Node &l,Node &r){
    t.sum=l.sum+r.sum;
    t.lmx=max(l.lmx,l.sum+r.lmx);
    t.rmx=max(r.rmx,r.sum+l.rmx);
    t.mx=max({l.mx,r.mx,l.rmx+r.lmx});
}
void up(int t){
    up(tr[t],tr[t*2],tr[t*2+1]);
}
void build(int t,int l,int r){
    if(l==r){tr[t]={l,r,a[l],a[l],a[l],a[l]};return;}
    tr[t]={l,r};
    int mid=l+r>>1;
    build(t*2,l,mid);
    build(t*2+1,mid+1,r);
    up(t);
}
void modify(int t,int x,int val){
    if(tr[t].l==x&&tr[t].r==x){tr[t]={x,x,val,val,val,val};return;}
    int mid=tr[t].l+tr[t].r>>1;
    if(x<=mid)modify(t*2,x,val);
    else modify(t*2+1,x,val);
    up(t);
}
Node query(int t,int l,int r){
    if(tr[t].l>=l&&tr[t].r<=r)return tr[t];
    int mid=tr[t].l+tr[t].r>>1;
    Node ret,left,right;
    cout<<ret.mx<<endl;cout<<left.mx<<endl;
    if(l<=mid)left=query(t*2,l,r);
    if(r>mid)right=query(t*2+1,l,r);
    up(ret,left,right);
    return ret;
}
// Node query(int u, int l, int r)
// {
//     if (tr[u].l >= l && tr[u].r <= r) return tr[u];
//     else
//     {
//         int mid = tr[u].l + tr[u].r >> 1;
//         if (r <= mid) return query(u << 1, l, r);
//         else if (l > mid) return query(u << 1 | 1, l, r);
//         else
//         {
//             auto left = query(u << 1, l, r);
//             auto right = query(u << 1 | 1, l, r);
//             Node res;
//             up(res, left, right);
//             return res;
//         }
//     }
// }
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    build(1,1,n);
    while(m--){
        int op,b,c;cin>>op>>b>>c;
        if(op==1){
            if(b>c)swap(b,c);
            cout<<query(1,b,c).mx<<endl;
        }else{
            modify(1,b,c);
        }
    }
    return 0;
}