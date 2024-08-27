#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for (int i = 0; i < t-1; i++)
    {
        map<int,int>m;
        int n;cin>>n;
        for (int i = 0; i < n; i++)
        {
            int a;cin>>a;
            if(m.count(a)==0)m[a]++;
            else m[-a]++;
        }
        cout<<m.size()<<endl;
    }
        map<int,int>m;
        int n;cin>>n;
        for (int i = 0; i < n; i++)
        {
            int a;cin>>a;
            if(m.count(a)==0)m[a]++;
            else m[-a]++;
        }
        cout<<m.size();
    return 0;
}