#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=1e5+5;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n,q;
struct nod
{
    int ne,a,b;
}nn[N];
struct Tree
{
    int l,r,k,x;
}t[N*4];
Tree up(Tree k1,Tree k2)
{
    Tree tt;
    tt.l=k1.l,tt.r=k2.r;
    tt.k=k1.k*k2.k;
    tt.x=k1.x*k2.k+k2.x;
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
    if(l==r){
        if(l<=n){
        t[p].k=nn[l].a,t[p].x=nn[l].b;
    }else{
        t[p].k=nn[l-n].a,t[p].x=nn[l-n].b;
    }
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p]=up(t[p*2],t[p*2+1]);
}
Tree ask(int p,int l,int r)
{
    if(l<=t[p].l&&r>=t[p].r) return t[p];
    int mid=(t[p].l+t[p].r)/2;
    Tree tt=t[p];
    if(l<=mid) tt=up(ask(p*2,l,r),tt);
    if(r>mid) tt=up(tt,ask(p*2+1,l,r));
    return tt;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>nn[i].a;
        for(int i=1;i<=n;i++) cin>>nn[i].b;
        for(int i=1;i<=n;i++) cin>>nn[i].ne;
        vector<int>qu;
    qu.push_back(0);
        for(int i=1;i!=1;i=nn[i].ne){
            qu.push_back(i);
        }
        for(int i=1;i<=n;i++){
            qu.push_back(i);
        }
        build(1,1,2*n);
        while(q--)
        {
            int x1,l1,y1;
            cin>>x1>>l1>>y1;
            for(int i=1;i<=n;i++){
                if(qu[i]==x1){
                    Tree tt=ask(1,i+1,i+l1);
                    cout<<y1*tt.k+tt.x<<'\n';
                }
            }
        }
    }
}