#include <bits/stdc++.h>
using namespace std;
#define pair<double,int>pdi;
#define int long long
struct node
{
    int x;
    int y;
};
double dist(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
signed main()
{
    int n;
    scanf("%lld",&n);
    int i;
    int j;
    node a[n+2];
    bool f=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
    }
    double dis[n+2];
    scanf("%lld%lld%lld%lld",&a[0].x,&a[0].y,&a[n+1].x,&a[n+1].y);
    for(i=1;i<=n+1;i++)dis[i]=1e56;
    dis[0]=0;
    int v1,v2;
    scanf("%lld%lld",&v1,&v2);
    bool st[n+2]={0};
    double ans=1e56;
    for(i=1;i<=n;i++)
    {
        if(a[i].x==a[0].x&&a[i].y==a[0].y)f=1;
    }
    for(i=0;i<=n+1;i++)
    {
        double mn=1e56;
        int bh=-1;
        for(j=0;j<=n+1;j++)
        {
            if(!st[j]&&dis[j]<mn)mn=dis[j],bh=j;
        }
        if(bh==-1)break;
        st[bh]=1;
        if(a[bh].x==a[n+1].x&&a[bh].y==a[n+1].y)
        {
            ans=mn;
            break;
        }
        for(j=0;j<=n+1;j++)
        {
            if(!st[j])
            {
                if(!bh&&!f)
                {
                    double t=dist(a[j],a[bh]);
                    double tt=t/v1;
                    if(dis[j]>dis[bh]+tt)dis[j]=dis[bh]+tt;
                    continue;
                }
                double t=dist(a[j],a[bh]);
                double kk=v2*3;
                double tt=0;
                if(kk>=t)
                {
                    tt=t/v2;
                }
                else
                {
                    tt=3+(t-kk)/v1;
                }
                if(dis[j]>=dis[bh]+tt)dis[j]=dis[bh]+tt;
            }
        }
    }
    printf("%.12lf",ans);

}