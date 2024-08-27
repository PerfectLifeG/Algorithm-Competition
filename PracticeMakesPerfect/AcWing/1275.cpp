#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int l,r;
    int sum;
}tr[N*4];
void up(int t){
    tr[t].sum=max(tr[t*2].sum,tr[t*2+1].sum);
}
void build(int t,int l,int r){
    tr[t]={l,r};
    if(l==r){tr[t].sum=a;return;}
    int mid=l+r>>1;
    build(t*2,l,mid);
    build(t*2+1,mid+1,r);
    up(t);
}
void modify(int t,int x,int val){
    if(tr[i].l==x&&tr[t].r==x){tr[t].sum=val;return;}
    int mid=tr[t].l+tr[t].r>>1;
    if(x<=mid)modify(t*2,x,val);
    else modify(t*2+1,x,val);
    up(t);
}
int query(int t,int l,int r){
    if(tr[t].l>=l&&tr[t].r<=r)return tr[t];
    int mid=tr[t].l+tr[t].r>>1;
    if(r<=mid)return query(t*2,l,r);
    else if(l>mid)return query(t*2+1,l,r);
    else{
        auto left=query(t*2,l,r);
        auto right=query(t*2+1,l,r);
        return left+right;
    }
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a;
    }
    while(q--){
        char op[2];
        cin>>op;
        if(*op=='Q'){
            int a,b;cin>>a>>b;
        }else{
            int a,b,c;cin>>a>>b>>c;
            
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