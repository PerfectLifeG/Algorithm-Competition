#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
// struct SegmentTree
// {
struct Node{
    int l,r;
    int sum;
    int lz;
};
vector<Node>tr;
Node tr[N];
SegmentTree(int n){
    tr.resize(4*n+5);
}
void up(int t){
    tr[t].sum=tr[t*2].sum+tr[t*2+1].sum;
}
void down(int t){
    auto &root=tr[t],&l=tr[t*2],&r=tr[t*2+1];
    if(root.lz){
        l.sum+=root.lz*(l.r-l.l+1);
        r.sum+=root.lz*(r.r-r.l+1);
        l.lz+=root.lz;
        r.lz+=root.lz;
        root.lz=0;
    }
}
void build(int t,int l,int r,vector<int>& a){
    if(l==r){tr[t]={l,r,a[l],0};return;}
    tr[t]={l,r};
    int mid=l+r>>1;
    build(t*2,l,mid,a);
    build(t*2+1,mid+1,r,a);
    up(t);
}
void modify(int t,int l,int r,int val){
    if(l<=tr[t].l&&tr[t].r<=r){
        tr[t].sum+=val*(tr[t].r-tr[t].l+1);
        tr[t].lz+=val;
        return;
    }
    down(t);
    int mid=tr[t].l+tr[t].r>>1;
    if(l<=mid)modify(t*2,l,r,val);
    if(r>mid) modify(t*2+1,l,r,val);
    up(t);
}
int query(int t,int l,int r){
    if(l<=tr[t].l&&tr[t].r<=r)return tr[t].sum;
    down(t);
    int mid=tr[t].l+tr[t].r>>1;
    int res=0;
    if(l<=mid)res+=query(t*2,l,r);
    if(r>mid)res+=query(t*2+1,l,r);
    return res;
} 
void solve(){
    int n;cin>>n;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}