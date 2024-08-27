#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
struct stu
{
    int name;
    int time;
    int h,m,s;
    string con;
    int cha;
};
int cmp(stu p1,stu p2){
    return p1.name<p2.name;
}
int cmp2(stu p1,stu p2){
    if(p1.name==p2.name)
    return p1.time<p2.time;
    return p1.name<p2.name;
}
int cmp3(stu &p1,stu &p2){
    return p1.cha>p2.cha;
}
int main()
{
    int n,k;
    cin>>n>>k;
    stu peo[10000];
    int ans=0;int tt=0;int cha=0;
    for (int i = 0; i < n; i++)
    {
        int a,h,m,s;
        string cond;
        char t;
        cin>>a>>h>>t>>m>>t>>s>>cond;
        peo[i].name=a;
        peo[i].h=h;peo[i].m=m;peo[i].s=s;
        peo[i].con=cond;
        peo[i].time=h*3600+m*60+s;
    }
    sort(peo,peo+n,cmp);
    sort(peo,peo+n,cmp2);
    for (int j = 0; j < k; j++)
    {
        int h,m,s,time;
        char t;
        cin>>h>>t>>m>>t>>s;
        time=h*3600+m*60+s;
        for (int i = 0; i < n-1; i++)
        {
            if(peo[i].time<=time&&peo[i].con=="in"&&peo[i+1].time>time&&peo[i+1].con=="out"&&peo[i+1].name==peo[i].name){
                ans++;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    for (int i = 0; i < n-1; i++)
    {
        if(peo[i].con=="in"&&peo[i+1].con=="out"&&peo[i+1].name==peo[i].name){
            cha=cha+peo[i+1].time-peo[i].time;
            peo[i+1].cha=cha;
            }
        else if(peo[i].name!=peo[i+1].name)cha=0;
    }
    sort(peo,peo+n,cmp3);
    int i=0;int time=peo[0].cha;int h,m,s;
    while(peo[i].cha==peo[0].cha){
        cout<<peo[i].name<<" ";
        i++;
    }
    s=time%60;time-=s;time/=60;
    m=time%60;time-=m;
    h=time/60;
    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}