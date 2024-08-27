#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;cin>>k;
    map<int,float,greater<int>>m;
    map<int,float>m1;
    for (int i = 0; i < k; i++)
    {
        int a;float b;
        cin>>a>>b;
        m1[a]=b;
    }
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        int a;float b;
        cin>>a>>b;
        m[a]=b;
    }
    for(auto it:m1){
        m[it.first]+=it.second;
    }
    int cnt=m.size();
    for(auto it:m){
        if(it.second==0)
        cnt--;
    }
    cout<<cnt;
    for(auto it:m){
        if(it.second!=0)
        printf(" %d %.1f",it.first,it.second);
    }
    return 0;
}