#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    map<float,int,greater<float>>mp;
    float a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        float b;
        cin>>b;
        b=b*1.0/a[i];
        mp[b]+=a[i];
    }
    auto it=mp.begin();
    float s=0;
    while(it!=mp.end()&&d>0){
        if(it->second<=d)
        {s+=it->second*it->first;
        d-=it->second;}
        else {s+=1.0*d*it->first;break;}
        it++;
    }
    printf("%.2f",s);
    return 0;
}