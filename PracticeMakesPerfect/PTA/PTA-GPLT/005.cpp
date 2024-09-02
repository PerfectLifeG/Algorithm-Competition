#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    set<int>s[n+1];
    for (int i = 1; i <= n; i++)
    {
        int m;cin>>m;
        for (int j = 0; j < m; j++)
        {
            int t;cin>>t;
            s[i].insert(t);
        }
    }
    int m;cin>>m;int nt,nc;
    for (int i = 0; i < m; i++)
    {   
        nt=0;nc=0;
        int p,q;cin>>p>>q;
        for (auto it:s[p])
        {
            if(s[q].count(it)==1)
            nc++;
        }
        nt=s[q].size()+s[p].size()-nc;
        printf("%.2f%\n",100*1.0*nc/nt);
    }
    return 0;
}