#include<bits/stdc++.h>
using namespace std;
struct peo
{
    int id;
    int root;
    int property;
    int s;
    int familynumber;
    float average;
    float area;
    peo(){
        property=0;;
        s=0;
        familynumber=0;
        id=0;
    }
}p[10000];
map<int,int>mp;
int cmp(peo a,peo b){
    return a.familynumber<b.familynumber;
}
int cmp2(peo a,peo b){
    if(a.average==b.average)return a.id<b.id;
    return a.average>b.average;
}
int find(int a){
    if(a==p[a].root)return a;
    return p[a].root=find(p[a].root);
}
void merge(int b,int f){
    f=find(f);b=find(b);
    if(b>f)
    p[b].root=f;
    else p[f].root=b;
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < 10000; i++)
    {
        p[i].root=i;
    }
    for (int i = 0; i < n; i++)
    {
        int parent,f,m,num;
        cin>>parent>>f>>m>>num;
        if(f!=-1)merge(parent,f);
        else if(m!=-1)merge(parent,m);
        for (int j = 0; j < num; j++)
        {
            int child;cin>>child;
            merge(child,parent);
        }
        cin>>num;
        int s;cin>>s;
        p[parent].s=s;
        p[parent].id=parent;
        p[parent].property=num;
    }
    int ans=0;
    for (int i = 0; i < 10000; i++)
    {
        if(p[i].root)
        {
            p[p[i].root].familynumber++;
            p[p[i].root].property+=p[i].root;
            p[p[i].root].s+=p[i].s;
            if(p[p[i].root].id>0)
            mp[p[i].root]=1;
        }
    }
    for (int i = 0; i < 10000; i++)
    {
        if(p[i].familynumber)ans++;
    }
    cout<<ans<<endl;
    for(auto it:mp){
        p[it.first].average=1.0*p[it.first].s/p[it.first].familynumber;
        p[it.first].area=1.0*p[it.first].property/p[it.first].familynumber;
    }
    sort(p,p+n,cmp);
    sort(p,p+ans,cmp2);
    for (int i = 0; i < ans; i++)
    {
        printf("%04d %d %.3f %.3f\n",p[i].id,p[i].familynumber,p[i].area,p[i].average);
    }
    return 0;
}