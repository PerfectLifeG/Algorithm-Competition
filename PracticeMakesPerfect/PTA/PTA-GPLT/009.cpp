#include<bits/stdc++.h>
using namespace std;
struct peo
{
    int name;
    int mon;
    int num;
    peo(){
        num=0;
        mon=0;
    }
};
int cmp1(peo p1,peo p2){
    if(p1.mon!=p2.mon)return p1.mon>p2.mon;
    return p1.num>p2.num;
}
int main()
{
    int n;cin>>n;
    peo p[n+1];
    for (int i = 1; i <= n; i++)
    {
        p[i].name=i;
    }
    for (int i = 1; i <= n; i++)
    {
        int k;cin>>k;
        for (int j = 1; j <= k; j++)
        {
            int a,b;cin>>a>>b;
            p[a].mon+=b;
            p[a].num++;
            p[i].mon-=b;
        }
    }
    sort(p+1,p+n+1,cmp1);
    for (int i = 1; i <= n; i++)
    {
        cout<<p[i].name;
        printf(" %.2f\n",p[i].mon*1.0/100);
    }
    
    return 0;
}