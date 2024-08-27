#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int bl[N];
int ans[N];
vector<int>v[N];
int a[N];
int res;
int qsm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}
int find(vector<int>&t,int x)
{
    int le=-1;
    int ri=t.size();
    while(le+1!=ri)
    {
        int mid=le+ri>>1;
        if(t[mid]<x)le=mid;
        else ri=mid;
    }
    return ri;
}
void del(int x,int l,int r)
{
    int p1=find(v[x],l);
    int p2=find(v[x],r+1);
    res-=(p2-p1);
}
void add(int x,int l,int r)
{
    int p1=find(v[x],l);
    int p2=find(v[x],r+1);
    res+=(p2-p1);
}
struct node
{
    int l;
    int r;
    int id;
    bool operator<(const node&a)const
    {
        if(bl[l]!=bl[a.l])return bl[l]<bl[a.l];
        return r<a.r;
    }
}b[N];
void solve()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int pos[n+1];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    int t=2*n+1;
    vector<int>q;
    for(i=2;i*i<=t;i++)q.push_back(i*i);
    for(i=1;i<=n/2;i++)
    {
        for(j=0;j<q.size();j++)
        {
            int t=q[j]-i;
            if(t<=i)continue;
            v[i].push_back(pos[t]);
            v[pos[t]].push_back(pos[i]);
        }
    }
    int sz=sqrt(n);
    int num=(n+sz-1)/sz;
    for(i=1;i<=num;i++)
    {
        for(j=(i-1)*sz+1;j<=i*sz;j++)bl[j]=i;
    }
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        b[i]={l,r,i};
    }
    sort(b,b+m);
    int ans[m];
    int l=1;
    int r=0;
    for(i=0;i<m;i++)
    {
        while(l<b[i].l)del(a[l],l,r),l++;
        while(l>b[i].l)l--,add(a[l],l,r);
        while(r<b[i].r)r++,add(a[r],l,r);
        while(r>b[i].r)del(a[r],l,r),r--;
        ans[i]=res;
    }
    for(i=0;i<m;i++)printf("%d\n",ans[i]);
    for(i=1;i<=n;i++)v[i].clear();

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}