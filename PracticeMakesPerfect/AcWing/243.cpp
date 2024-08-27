#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int l,r;
    int sum;
    int lazy;
}tr[N*4];
int a[N];
void up(int t){
    tr[t].sum=tr[t*2].sum+tr[t*2+1].sum;
}
void down(int t){
    auto &root=tr[t],&l=tr[t*2],&r=tr[t*2+1];
    if(root.lazy){
        l.sum+=root.lazy*(l.r-l.l+1);
        r.sum+=root.lazy*(r.r-r.l+1);
        l.lazy+=root.lazy;
        r.lazy+=root.lazy;
        root.lazy=0;
    }
}
void build(int t,int l,int r){
    if(l==r){tr[t]={l,r,a[l],0};return;}
    tr[t]={l,r};
    int mid=l+r>>1;
    build(t*2,l,mid);
    build(t*2+1,mid+1,r);
    up(t);
}
void modify(int t,int l,int r,int val){
    if(l<=tr[t].l&&r>=tr[t].r){
        tr[t].sum+=val*(tr[t].r-tr[t].l+1);
        tr[t].lazy+=val;
        return;
    }
    down(t);
    int mid=tr[t].l+tr[t].r>>1;
    if(l<=mid)modify(t*2,l,r,val);
    if(r>mid) modify(t*2+1,l,r,val);
    up(t);
}
int query(int t,int l,int r){
    if(tr[t].l>=l&&tr[t].r<=r)return tr[t].sum;
    down(t);
    int mid=tr[t].l+tr[t].r>>1;
    int ret=0;
    if(l<=mid)ret+=query(t*2,l,r);
    if(r>mid)ret+=query(t*2+1,l,r);
    return ret;
} 
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(q--){
        char op[2];
        cin>>op;
        if(*op=='Q'){
            int a,b;cin>>a>>b;
            cout<<query(1,a,b)<<endl;
        }else{
            int a,b,c;cin>>a>>b>>c;
            modify(1,a,b,c);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}