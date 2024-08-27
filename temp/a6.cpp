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
typedef long long LL;
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;
int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int inv(int a){
    return ksm(a,mod-2);
}

struct SegmentTree
{

    struct Node
    {
        int l, r;
        int sum, add, mul;
    };
    vector<Node>tr;
    SegmentTree(int n) {
        tr.resize(4 * n + 5);
    }

    void pushup(int u)
    {
        tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
    }

    void eval(Node &t, int add, int mul)
    {
        t.sum = ((LL)t.sum * mul + (LL)(t.r - t.l + 1) * add) % mod;
        t.mul = (LL)t.mul * mul % mod;
        t.add = ((LL)t.add * mul + add) % mod;
    }

    void pushdown(int u)
    {
        eval(tr[u << 1], tr[u].add, tr[u].mul);
        eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
        tr[u].add = 0, tr[u].mul = 1;
    }

    void build(int u, int l, int r,vector<int>& a)
    {
        if (l == r) tr[u] = {l, r, a[r], 0, 1};
        else
        {
            tr[u] = {l, r, 0, 0, 1};
            int mid = l + r >> 1;
            build(u << 1, l, mid,a), build(u << 1 | 1, mid + 1, r,a);
            pushup(u);
        }
    }

    void modify(int u, int l, int r, int add, int mul)
    {
        if (tr[u].l >= l && tr[u].r <= r) eval(tr[u], add, mul);
        else
        {
            pushdown(u);
            int mid = tr[u].l + tr[u].r >> 1;
            if (l <= mid) modify(u << 1, l, r, add, mul);
            if (r > mid) modify(u << 1 | 1, l, r, add, mul);
            pushup(u);
        }
    }

    int query(int u, int l, int r)
    {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int sum = 0;
        if (l <= mid) sum = query(u << 1, l, r);
        if (r > mid) sum = (sum + query(u << 1 | 1, l, r)) % mod;
        return sum;
    }

};

void solve(){
    int n,q;cin>>n>>q;
    string s;cin>>s;s=' '+s;
    set<int>B{0,n+1};
    vector<int>sum(n+2);
    vector<int>r(n+2);
    for(int i=1;i<=n;i++){
        if(s[i]=='B'){
            sum[i]=sum[i-1];
            B.insert(i);
        }
        if(s[i]=='R'){
            sum[i]=sum[i-1]+1;
            r[i]=i;
        }
    }
    vector<int>val(n+2);
    int j=1;
    for(auto i:B){
        while(j<i&&j<n){
            val[j]=ksm(2,sum[i-1]-sum[j]);
            j++;
        }
    }
    return;

    // cout<<s<<endl;
    // for(int i=1;i<=n;i++)cout<<r[i]<<' ';cout<<endl;
    // for(int i=1;i<=n;i++)cout<<val[i]<<' ';cout<<endl;
    // return;


    SegmentTree add(n);
    SegmentTree mul(n);
    add.build(1,1,n,r);
    mul.build(1,1,n,val);
    while(q--){
        int op;cin>>op;
        if(op==1){
            int p;cin>>p;
            char c[2];cin>>c;
            if(s[p]=='B'){
                if(*c=='R')add.modify(1,p,p,1,1);
                B.erase(p);
                auto pre=*prev(B.lower_bound(p));
                auto nx=*B.upper_bound(p);
                int t=add.query(1,p,nx-1);
                mul.modify(1,pre,p-1,0,ksm(2,t));
            }else if(*c=='B'){
                auto pre=*prev(B.lower_bound(p));
                auto nx=*B.upper_bound(p);
                int t=add.query(1,p,nx-1);
                mul.modify(1,pre,p-1,0,inv(ksm(2,t)));

                if(s[p]=='R')add.modify(1,p,p,-1,1);
                B.insert(p);

            }else{
                if(s[p]=='Y'){
                    auto pre=*prev(B.lower_bound(p));
                    auto nx=*B.upper_bound(p);
                    mul.modify(1,pre,p-1,0,2);
                    add.modify(1,p,p,1,1);
                }else{
                    auto pre=*prev(B.lower_bound(p));
                    auto nx=*B.upper_bound(p);
                    mul.modify(1,pre,p-1,0,inv(2));
                    add.modify(1,p,p,-1,1);
                }
            }
            s[p]=*c;
        }else{
            int l,r;cin>>l>>r;
            cout<<mul.query(1,l,r)<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}