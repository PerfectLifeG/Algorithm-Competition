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
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;



struct Node{
    int l,r;
    int val,add;
}tr[N<<2];

void pushup(int u){
    tr[u].val=tr[u*2].val+tr[u*2+1].val;
}

void pushdown(int u){
    auto &root=tr[u],&l=tr[u*2],&r=tr[u*2+1];
    if(root.add){
        l.val+=root.add*(l.r-l.l+1);
        r.val+=root.add*(r.r-r.l+1);
        l.add+=root.add;
        r.add+=root.add;
        root.add=0;
    }
}

void build(int u, int l, int r){
    tr[u].l=l,tr[u].r=r;
    if(l==r){
        tr[u].val=0;//初始化值
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    build(u*2,l,mid); build(u*2+1,mid+1,r);
    pushup(u);
}


int x;
void modify(int u, int L, int R, int val){
    if(L<=tr[u].l&&tr[u].r<=R){
        if(tr[u].val+x>=val){
            tr[u].val+=val*(tr[u].r-tr[u].l+1);
            tr[u].add+=val;
        }
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(L<=mid) modify(u*2,L,R,val);
    if(R>mid) modify(u*2+1,L,R,val);
    pushup(u);
}

// void modify2(int u, int L, int R, int val){
//     if(L<=tr[u].l&&tr[u].r<=R){
//         tr[u].val+=val*(tr[u].r-tr[u].l+1);
//         tr[u].add+=val;
//         return;
//     }
//     pushdown(u);
//     int mid=tr[u].l+tr[u].r>>1;
//     if(L<=mid) modify(u*2,L,R,val);
//     if(R>mid) modify(u*2+1,L,R,val);
//     pushup(u);
// }

int query(int u, int L, int R){
    if(L<=tr[u].l&&tr[u].r<=R){
        return tr[u].val;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    int mx=0;
    if (L<=mid) mx=max(mx,query(u*2,L,R));
    if (R>mid) mx=max(mx,query(u*2+1,L,R));
    return mx;
}

void solve(){
    int n;cin>>n>>x;
    vector<array<int,3>>v;
    vector<int>vv;
    for(int i=0;i<n;i++){
        int l,r,y;cin>>l>>r>>y;
        v.push_back({l,r,y});
        vv.push_back(l);
        vv.push_back(r);
    }
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    unordered_map<int,int>mp;
    int idx=1;
    for(auto i:vv)mp[i]=idx++;
    // for(auto i:vv)cout<<i<<' '<<mp[i]<<endl;

    sort(all(v),[&](array<int,3> &a,array<int,3> &b){
        return a[2]<b[2];
    });
    build(1,1,n);
    for(int i=0;i<1;i++){
        // cout<<1<<' '<<mp[v[i][0]]<<' '<<mp[v[i][1]]<<' '<<v[i][2]<<endl;
        modify(1,mp[v[i][0]],mp[v[i][1]],v[i][2]);
    }
    return;

    cout<<query(1,1,mp[vv.back()])<<endl;
    for(int i=0;i<n;i++){
        modify(1,mp[v[i][0]],mp[v[i][1]],-v[i][2]);
    }

}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}