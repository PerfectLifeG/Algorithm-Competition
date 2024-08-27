#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
struct SegmentTree
{
    struct Node
    {
        int l, r;
        int x, y;
    };
    vector<Node>tr;
    SegmentTree(int n) {
        tr.resize(4 * n + 5);
    }
    void pushup(int t)
    {
        tr[t].x = max(tr[t * 2].x, tr[t * 2 + 1].x);
        tr[t].y = min(tr[t * 2].y, tr[t * 2 + 1].y);
    }
    template<typename M>
    void build(int t, int l, int r, vector<M>& a)
    {
        tr[t].l = l, tr[t].r = r;
        if (l == r) {
            tr[t].x = a[l];
            tr[t].y = a[l];
            return;
        }
        int mid = tr[t].l + tr[t].r >> 1;
        build(t * 2, l, mid, a); build(t * 2 + 1, mid + 1, r, a);
        pushup(t);
    }
    PII query(int t, int l, int r) {
        if (l <= tr[t].l && tr[t].r <= r) {
            return {tr[t].x,tr[t].y};
        }
        int mid = tr[t].l + tr[t].r >> 1;
        int mx = -INF;
        int mn = INF;
        if (l <= mid) {
            auto res=query(t * 2, l, r);
            mx = max(mx, res.x);
            mn = min(mn, res.y);
        }
        if (r > mid){
            auto res=query(t * 2 + 1, l, r);
            mx = max(mx, res.x);
            mn = min(mn, res.y);
        }
        return {mx,mn};
    }
};
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    SegmentTree tr(n);
    tr.build(1,0,n,a);

    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        auto ans=tr.query(1,l-1,r);
        cout<<ans.x-ans.y<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}