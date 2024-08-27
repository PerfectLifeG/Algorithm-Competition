#include<bits/stdc++.h>
using namespace std;
struct Time
{
    int start;
    int end;
};
int cmp(Time t1,Time t2){
    return t1.start<t2.start;
    if(t1.start==t2.start)
    return t1.end>t2.end;
}
int main()
{
    int n;cin>>n;
    Time time[n];
    int a,b,c,d,e,f;
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d - %d:%d:%d",&a,&b,&c,&d,&e,&f);
        time[i].start=a*3600+b*60+c;
        time[i].end=d*3600+e*60+f;
    }
    sort(time,time+n,cmp);
    int cnt=1;int temp=1;
    int j=0;
    for (int i = 1; i < n; i++)
    {
        int start=time[i-1].start;
        int end=time[i-1].end;
        int t=i-1;
        j=max(i,j);
        while(time[j].start>=start&&time[j].start<=end&&j<n){
            j++;
            temp++;
            end=time[++t].end;
        }
        if(temp>cnt)cnt=temp;
        temp=1;
    }
    cout<<cnt;
    return 0;
}