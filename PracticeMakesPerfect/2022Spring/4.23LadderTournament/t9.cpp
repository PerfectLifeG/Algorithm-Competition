#include<bits/stdc++.h>
using namespace std;
struct timee
{
    int start;
    int end;
};
int cmp(timee a,timee b){
    return a.start<b.start;
}
int main(){
    int n;cin>>n;
    timee t[n+1];
    for (int i = 0; i < n; i++)
    {   
        int a,b,c,d,e,f;
        scanf("%d:%d:%d - %d:%d:%d",&a,&b,&c,&d,&e,&f);
        int t1=a*3600+b*60+c;
        int t2=d*3600+e*60+f;
        t[i].start=t1;t[i].end=t2;
    }
    t[n].start=86399;t[n].end=86399;
    sort(t,t+n,cmp);
    if(t[0].start!=0){
            int a=0,b=t[0].start;
            int h1,m1,s1,h2,m2,s2;
            s1=a%60;a-=s1;a/=60;
            m1=a%60;a/=60;
            h1=a%24;
            s2=b%60;b-=s2;b/=60;
            m2=b%60;b/=60;
            h2=b%24;
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
    }
    int t1=t[0].start;int t2=t[0].end;
    for (int i = 0; i < n; i++)
    {   
        t1=t[i].start;t2=t[i].end;
        if(t2!=t[i+1].start){
            int a=t2,b=t[i+1].start;
            int h1,m1,s1,h2,m2,s2;
            s1=a%60;a-=s1;a/=60;
            m1=a%60;a/=60;
            h1=a%24;
            s2=b%60;b-=s2;b/=60;
            m2=b%60;b/=60;
            h2=b%24;
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
        }
    }
    
    return 0;
}