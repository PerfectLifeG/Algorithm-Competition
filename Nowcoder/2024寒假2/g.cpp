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
struct SegmentTree
{
    struct Node
    {
        int l, r;
        int val, lz;
    };
    vector<Node>tr;
    SegmentTree(int n) {
        tr.resize(4 * n + 5);
    }
    void pushup(int t)
    {
        tr[t].val = max(tr[t * 2].val, tr[t * 2 + 1].val);
    }
    void pushdown(int t)
    {
        if (tr[t].lz) {
            tr[2 * t].val += tr[t].lz;
            tr[2 * t + 1].val += tr[t].lz;
            tr[2 * t].lz += tr[t].lz;
            tr[2 * t + 1].lz += tr[t].lz;
            tr[t].lz = 0;
        }
    }
    template<typename M>
    void build(int t, int l, int r, vector<M>& a)
    {
        tr[t].l = l, tr[t].r = r;
        if (l == r) {
            tr[t].val = a[l];
            return;
        }
        int mid = tr[t].l + tr[t].r >> 1;
        build(t * 2, l, mid, a); build(t * 2 + 1, mid + 1, r, a);
        pushup(t);
    }
    template<typename M>
    void modify(int t, int x, M val) {
        if (tr[t].l == tr[t].r) {
            tr[t].val += val ;
            tr[t].lz += val;
            return;
        }
        pushdown(t);
        int mid = tr[t].l + tr[t].r >> 1;
        if (x <= mid) modify(t * 2, x, val);
        else modify(t * 2 + 1, x, val);
        pushup(t);
    }
    template<typename M>
    void modify(int t, int l, int r, M val) {
        if (l <= tr[t].l && tr[t].r <= r) {
            tr[t].val += val ;
            tr[t].lz += val;
            return;
        }
        pushdown(t);
        int mid = tr[t].l + tr[t].r >> 1;
        if (l <= mid) modify(t * 2, l, r, val);
        if (r > mid) modify(t * 2 + 1, l, r, val);
        pushup(t);
    }
    int query(int t, int l, int r) {
        if (l <= tr[t].l && tr[t].r <= r) {
            return tr[t].val;
        }
        pushdown(t);
        int mid = tr[t].l + tr[t].r >> 1;
        int mx = -INF;
        if (l <= mid) mx = max(mx, query(t * 2, l, r));
        if (r > mid) mx = max(mx, query(t * 2 + 1, l, r));
        return mx;
    }
};
void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n-1;i++){
        pre[i]-=a[i+1];
    }
    SegmentTree tr(n);
    tr.build(1,1,n-1,pre);
    while(q--){
        int op;cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;
            if(x-1>=1)tr.modify(1,x-1,a[x]-y);
            if(x<=n-1)tr.modify(1,x,n-1,y-a[x]);
            a[x]=y;
        }else{
            int l,r;cin>>l>>r;
            if(l==1)cout<<tr.query(1,l,r-1)<<endl;
            else cout<<tr.query(1,l,r-1)-tr.query(1,l-1,l-1)-a[l]<<endl;
        }
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}