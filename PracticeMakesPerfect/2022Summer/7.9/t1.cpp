#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;int s=0;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        s+=a;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    if(v[0]>0)v[0]=0;
    cout<<s-v[0];
    return 0;
}