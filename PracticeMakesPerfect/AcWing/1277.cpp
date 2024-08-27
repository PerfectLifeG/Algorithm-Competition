#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
struct Node{
    int l,r;
    int sum,add=0,mul=1;
}tr[N*4];
int a[N];
int n,p;
void up(int t){
    tr[t].sum=(tr[t*2].sum+tr[t*2+1].sum)%p;
}
void down(int t){
    auto &root=tr[t],&left=tr[t*2],&right=tr[t*2+1];
    if(root.mul>1||root.mul==0){//这有点离谱
        left.mul=left.mul*root.mul%p,left.sum=left.sum*root.mul%p;
        left.add=left.add*root.mul%p;
        right.mul=right.mul*root.mul%p,right.sum=right.sum*root.mul%p;
        right.add=right.add*root.mul%p;
        root.mul=1;
    }
    if(root.add){//其实这个有没有都行
        left.add=(left.add+root.add)%p,left.sum=(left.sum+(left.r-left.l+1)*root.add)%p;
        right.add=(right.add+root.add)%p,right.sum=(right.sum+(right.r-right.l+1)*root.add)%p;
        root.add=0;
    }
}
// void eval(Node &t, int add, int mul)
// {
//     t.sum = (t.sum * mul + (t.r - t.l + 1) * add) % p;
//     t.mul = t.mul * mul % p;
//     t.add = (t.add * mul + add) % p;
// }
// void down(int u)
// {
//     eval(tr[u << 1], tr[u].add, tr[u].mul);
//     eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
//     tr[u].add = 0, tr[u].mul = 1;
// }
void bulid(int t,int l,int r){
    if(l==r){tr[t]={l,r,a[l],0,1};return;}
    tr[t]={l,r};
    int mid=l+r>>1;
    bulid(t*2,l,mid);
    bulid(t*2+1,mid+1,r);
    up(t);
}
void modify1(int t,int l,int r,int val){
    if(tr[t].l>=l&&tr[t].r<=r){
        tr[t].sum=(tr[t].sum+(tr[t].r-tr[t].l+1)*val)%p;
        tr[t].add=(tr[t].add+val)%p;
        return;
    }
    down(t);
    int mid=tr[t].l+tr[t].r>>1;
    if(l<=mid)modify1(t*2,l,r,val);
    if(r>mid)modify1(t*2+1,l,r,val);
    up(t);
}
void modify2(int t,int l,int r,int val){
    if(tr[t].l>=l&&tr[t].r<=r){
        tr[t].sum=tr[t].sum*val%p;
        tr[t].add=tr[t].add*val%p;
        tr[t].mul=tr[t].mul*val%p;
        return;
    }
    down(t);
    int mid=tr[t].l+tr[t].r>>1;
    if(l<=mid)modify2(t*2,l,r,val);
    if(r>mid)modify2(t*2+1,l,r,val);
    up(t);
}
int query(int t,int l,int r){
    if(tr[t].l>=l&&tr[t].r<=r)return tr[t].sum;
    down(t);
    int mid=tr[t].l+tr[t].r>>1;
    int ret=0;
    if(l<=mid)ret=query(t*2,l,r)%p;
    if(r>mid)ret=(ret+query(t*2+1,l,r))%p;
    return ret;
}
signed main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    bulid(1,1,n);
    int m;cin>>m;
    while(m--){
        int op,l,r,d;
        cin>>op>>l>>r;
        if(op==1){
            cin>>d;
            modify2(1,l,r,d);
        }else if(op==2){
            cin>>d;
            modify1(1,l,r,d);
        }else{
            cout<<query(1,l,r)%p<<endl;
        }
    }
    return 0;
}