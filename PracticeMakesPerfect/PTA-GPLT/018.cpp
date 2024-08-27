#include<bits/stdc++.h>
using namespace std;
const int Max=1e7+5;
float e1[Max],e2[Max],ans[Max];
int main()
{
    int n;cin>>n;
    int max1,max2;
    for (int i = 0; i < n; i++)
    {
        int a,b;cin>>a>>b;
        if(i==0)max1=a;
        e1[a]=b;
    }
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b;cin>>a>>b;
        if(i==0)max2=a;
        e2[a]=b;
    }
    int t=max1;
    while(max1>=max2)
    {
        double c=1.0*e1[max1]/e2[max2];
        int index=max1-max2;
        ans[index]=c;
        for (int j = max1; j >= index; j--)
        {
            e1[j]-=c*e2[j-index];
        }
        while (abs(e1[max1]) < 0.05) max1--;
    }
    map<int,float,greater<int>>m,mm;
    for (int i = 0; i <= t; i++)
    {
        if(abs(ans[i])>=0.05)
        m.insert(make_pair(i,ans[i]));
        if(abs(e1[i])>=0.05)
        mm.insert(make_pair(i,e1[i]));
    }
    map<int,float,greater<int>>::iterator it=m.begin();
    map<int,float,greater<int>>::iterator itt=mm.begin();
    cout<<m.size();
    if(m.size()==0) 
        cout<<" 0 0.0";
    else
    for (int i = 0; i < m.size(); i++)
    {
        printf(" %d %.1f",it->first,it->second);
        it++;
    }
    cout<<endl<<mm.size();
    if(mm.size()==0)
        cout<<" 0 0.0";
    else
    for (int i = 0; i < mm.size(); i++)
    {
        printf(" %d %.1f",itt->first,itt->second);
        itt++;
    }
    return 0;
}