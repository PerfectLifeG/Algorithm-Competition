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
const int N=4e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

set<int>len[N];
struct Node{
    int l,r;
    int val;
}tr[N<<2];

void pushup(int u){
    tr[u].val=min(tr[u*2].val,tr[u*2+1].val);
}

void build(int u, int l, int r){
    tr[u].l=l,tr[u].r=r;
    if(l==r){
        tr[u].val=INF;//初始化最值
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    build(u*2,l,mid); build(u*2+1,mid+1,r);
    pushup(u);
}

void modify(int u, int L, int R, int val){
    if(L<=tr[u].l&&tr[u].r<=R){
        tr[u].val=val;
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    if(L<=mid) modify(u*2,L,R,val);
    if(R>mid) modify(u*2+1,L,R,val);
    pushup(u);
}

int query(int u, int L, int R){//查询[L,R]最值
    if(L<=tr[u].l&&tr[u].r<=R){
        return tr[u].val;
    }
    int mid=tr[u].l+tr[u].r>>1;
    int mn=INF;
    if (L<=mid) mn=min(mn,query(u*2,L,R));
    if (R>mid) mn=min(mn,query(u*2+1,L,R));
    return mn;
}

int query(int u, int k){//查询第一个值>=k的下标
    if(tr[u].l==tr[u].r){
        return tr[u].l;
    }
    if (k<=tr[u*2].val) return query(u*2,k);
    else return query(u*2+1,k);
}

void check(int x){
    if(!x)return;
    if(len[x].size()){
        // cout<<x<<'?'<<*len[x].begin()<<endl;
        modify(1,x,x,*len[x].begin());
    }else if(len[x].size()==0){
        // cout<<x<<' '<<INF<<endl;
        modify(1,x,x,INF);
    }
}

void solve(){
    int n;cin>>n;
    set<int>st{0,N-1};
    modify(1,N-2,N-2,1);

    auto add=[&](int x){
        auto it=st.insert(x).first;
        auto l=prev(it);
        auto r=next(it);
        int ll=*r-*l-1;
        len[ll].erase(*l+1);check(ll);
        len[x-*l-1].insert(*l+1);check(x-*l-1);
        len[*r-x-1].insert(x+1);check(*r-x-1);
    };

    auto del=[&](int x){
        auto it=st.find(x);
        auto l=prev(it);
        auto r=next(it);
        int ll=*r-*l-1;
        len[ll].insert(*l+1);check(ll);
        len[x-*l-1].erase(*l+1);check(x-*l-1);
        len[*r-x-1].erase(x+1);check(*r-x-1);
        st.erase(x);
    };

    for(int i=0;i<n;i++){
        int a;cin>>a;
        st.insert(a);
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
            cout<<query(1,x,N)<<' ';
        }
    }cout<<endl;

    int lst=-1;
    for(auto i:st){
        if(lst!=-1){
            len[i-lst-1].clear();
            check(i-lst-1);
        }
        lst=i;
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