#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,m,a[1000000],f[4000002];
inline void build(int k,int l,int r){
    if(l==r){
        f[k]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    f[k]=f[k*2]+f[k*2+1];
}
inline void add(int k,int l,int r,int x,long long int y){
    f[k]+=y;
    if(r==l) return;
    int mid=(l+r)>>1;
    if(x<=mid) add(k*2,l,mid,x,y);
    else add(k*2+1,mid+1,r,x,y); 
}
long long sum(int k,int l,int r,int x,int y){
    if(l==x&&r==y)
        return f[k];
    int mid=(l+r)>>1;
    if(y<=mid) return sum(k*2,l,mid,x,y);
    else if(x>mid) return sum(k*2+1,mid+1,r,x,y);
    else return sum(k*2,l,mid,x,mid)+sum(k*2+1,mid+1,r,mid+1,y); 
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%lld",&a[i]);    
    }
    build(1,1,n);
    for (int i = 1; i <= m; i++)
    {   
        long long int t,x,y;
        scanf("%d%d%lld",&t,&x,&y);
        if(t==1)add(1,1,n,x,y);
        else printf("%lld\n",sum(1,1,n,x,y));
    }
    
    return 0;
}