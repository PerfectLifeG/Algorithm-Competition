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
const int N=2e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

struct Node{
    int l,r;
    int val,lz;
}tr[N<<2];

void pushup(int u){
    tr[u].val=max(tr[u*2].val,tr[u*2+1].val);
}

void pushdown(int u){
    auto &root=tr[u],&l=tr[u*2],&r=tr[u*2+1];
    if(root.lz!=-INF){
        l.val=root.lz;
        r.val=root.lz;
        l.lz=root.lz;
        r.lz=root.lz;
        root.lz=-INF;
    }
}

void build(int u, int l, int r){
    tr[u].l=l,tr[u].r=r;
    if(l==r){
        tr[u].val=-INF;//初始化最值
        tr[u].lz=-INF;
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    build(u*2,l,mid); build(u*2+1,mid+1,r);
    pushup(u);
}

void modify(int u, int L, int R, int val){
    if(L<=tr[u].l&&tr[u].r<=R){
        tr[u].val=val;
        tr[u].lz=val;
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(L<=mid) modify(u*2,L,R,val);
    if(R>mid) modify(u*2+1,L,R,val);
    pushup(u);
}

int query(int u, int L, int R){//查询[L,R]最值
    if(L<=tr[u].l&&tr[u].r<=R){
        return tr[u].val;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int mx=-INF;
    if (L<=mid) mx=max(mx,query(u*2,L,R));
    if (R>mid) mx=max(mx,query(u*2+1,L,R));
    return mx;
}

int query(int u, int k){//查询第一个值>=k的下标
    if(tr[u].l==tr[u].r){
        return tr[u].l;
    }
    pushdown(u);
    if (k<=tr[u*2].val) return query(u*2,k);
    else return query(u*2+1,k);
}

void solve(){
    int n;cin>>n;
    set<int>st{0,INF};
    modify(1,1,1,INF);

    auto add=[&](int x){
        auto it=st.insert(x).first;
        auto l=prev(it);
        auto r=next(it);
        // cout<<*l+1<<' '<<x-*l-1<<endl;
        modify(1,*l+1,*l+1,x-*l-1);
        modify(1,x+1,x+1,*r-x-1);
    };

    auto del=[&](int x){
        auto it=st.find(x);
        auto l=prev(it);
        auto r=next(it);
        modify(1,*l+1,*l+1,*r-*l-1);
        modify(1,x+1,x+1,-INF);
        st.erase(x);
    };

    for(int i=0;i<n;i++){
        int a;cin>>a;
        add(a);        
    }
    int q;cin>>q;
    while(q--){
        int x;
        char op[2];cin>>op>>x;
        if(*op=='+'){
            add(x);
        }else if(*op=='-'){
            del(x);
        }else{
            cout<<query(1,x)<<' ';
        }
    }cout<<endl;

    for(auto i:st){
        if(i!=INF)
        modify(1,i+1,i+1,-INF);
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    build(1,1,N);
    while(_--)solve();
    return 0;
}