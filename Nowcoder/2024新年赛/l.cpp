#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int l,r;
    ll mx;
}tr[N*4];
void up(Node &t,Node &l,Node &r){
    t.mx=max(l.mx,r.mx);
}
void up(int t){
    tr[t].mx=max(tr[t*2].mx,tr[t*2+1].mx);
}
void build(int t,int l,int r){
    tr[t]={l,r};
    if(l==r){tr[t].mx=0ll;return;}
    int mid=l+r>>1;
    build(t*2,l,mid);
    build(t*2+1,mid+1,r);
    up(t);
}
Node query(int t,int l,int r){
    if(tr[t].l>=l&&tr[t].r<=r)return tr[t];
    int mid=tr[t].l+tr[t].r>>1;
    if(r<=mid)return query(t*2,l,r);
    else if(l>mid)return query(t*2+1,l,r);
    else {
        auto left=query(t*2,l,r);
        auto right=query(t*2+1,l,r);
        Node root;
        up(root,left,right);
        return root;
    }
}
void modify(int t,int x,ll val){//第x个位置
    if(tr[t].l==x&&tr[t].r==x){tr[t].mx=val;return;}
    int mid=tr[t].l+tr[t].r>>1;
    if(x<=mid)modify(t*2,x,val);
    else modify(t*2+1,x,val);
    up(t);
}

void solve(){
    int n,k1,k2;cin>>n>>k1>>k2;
    build(1,1,n);
    vector<int>v(1+n);
    vector<ll>s(1+n);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        v[i]=a;
        s[i]=(ll)v[i]+s[i-1];
        ll t=-1e18;
        if(i>=k1)t=s[i]-s[i-k1];
        modify(1,i,t);
    }
    ll ans=-1e18;
    for(int i=k1+k2;i<=n-k1;i++){
        if(i+k1>n)break;
        ll t=s[i]-s[i-k2];
        auto a1=query(1,1,i-k2);
        auto a2=query(1,i+k1,n);
        ans=max(ans,a1.mx+a2.mx-t);
        // cout<<i<<' '<<a1.mx<<' '<<a2.mx<<' '<<t<<' '<<ans<<endl;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}